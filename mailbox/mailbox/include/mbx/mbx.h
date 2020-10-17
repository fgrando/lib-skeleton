#ifndef MBX_H_INCLUDED
#define MBX_H_INCLUDED

// Main include for internal classes to use MBX stuff

#include <mbx/mbx_allocators.h>
#include <mbx/mbx_calloc.h>
#include <mbx/containers.h>

#define MBX_IMPLEMENTS_ALLOCATORS \
public: \
    void *operator new(size_t size) { return mbx_malloc(size); } \
    void operator delete(void *ptr) { mbx_free(ptr); } \
    void *operator new[](size_t size) { return mbx_malloc(size); } \
    void operator delete[](void *ptr) { mbx_free(ptr); } \
    void *operator new(size_t, void *ptr) { return ptr; } \
    void operator delete(void *, void *) {} \
    void *operator new[](size_t, void *ptr) { return ptr; } \
    void operator delete[](void *, void *) {} \
private:

#endif