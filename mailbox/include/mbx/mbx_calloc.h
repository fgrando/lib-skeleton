#ifndef MBX_CALLOC_H_INCLUDED
#define MBX_CALLOC_H_INCLUDED

// calloc() using our allocator

#include <mbx/mbx_allocators.h>
#include <cstring>

inline void *mbx_calloc(size_t count, size_t size)
{
    void *ptr = _mbx_allocators.f_malloc(count * size);
    memset(ptr, 0, count * size);
    return ptr;
}


#endif /* MBX_CALLOC_H_INCLUDED */