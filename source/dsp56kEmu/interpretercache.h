#pragma once
#include <algorithm>
#include <array>
#include <cassert>
#include <memory>
#include <vector>

namespace dsp56k {
// Fixed logical address space, lazily allocated metadata. Untouched addresses
// share one read-only default page. Pointers to resolved entries remain stable.
template<class T, size_t PageSize=1024> class InterpreterCache {
    static_assert((PageSize & (PageSize-1))==0);
public:
    void clear() { pages.clear(); reads.clear(); count=0; allocated=0; }
    void resize(size_t size,const T& value) {
        clear(); count=size; defaults.fill(value);
        pages.resize((size+PageSize-1)/PageSize); reads.assign(pages.size(),defaults.data());
    }
    void assign(size_t size,const T& value) { resize(size,value); }
    bool empty() const { return count==0; }
    size_t size() const { return count; }
    size_t allocatedPages() const { return allocated; }
    const T& operator[](size_t index) const {
        assert(index<count); return reads[index/PageSize][index%PageSize];
    }
    T* getAllocated(size_t index) {
        if(index>=count || !pages[index/PageSize]) return nullptr;
        return &pages[index/PageSize][index%PageSize];
    }
    T& edit(size_t index) {
        assert(index<count);
        auto& page=pages[index/PageSize];
        if(!page) {
            page=std::make_unique<T[]>(PageSize);
            std::copy(defaults.begin(),defaults.end(),page.get());
            reads[index/PageSize]=page.get(); ++allocated;
        }
        return page[index%PageSize];
    }
private:
    size_t count=0,allocated=0;
    std::vector<std::unique_ptr<T[]>> pages;
    std::vector<const T*> reads;
    // Keep the pointer read on every instruction close to the cache object.
    // The shared default page can be much larger than an ARM load's offset.
    std::array<T,PageSize> defaults{};
};
}
