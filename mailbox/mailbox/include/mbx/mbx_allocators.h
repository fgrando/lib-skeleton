#ifndef MBX_ALLOCATORS_H_INCLUDED
#define MBX_ALLOCATORS_H_INCLUDED

// this verbose mechanism is to show that our allocators are in use
#define VERBOSE 1

#if VERBOSE
#include <iostream>
#define print(str) printf("%s", str);
#else
#define print(str)
#endif



// Provide a way to reconfigure allocators

struct mbx_allocators_s {
    void *(*f_malloc)(size_t);
    void *(*f_realloc)(void *, size_t);
    void(*f_free)(void *);
};

extern struct mbx_allocators_s _mbx_allocators;

inline void *mbx_malloc(size_t size)
{
    print("MAILBOX MALLOC!\n");
    return _mbx_allocators.f_malloc(size);
}

inline void *mbx_realloc(void *ptr, size_t size)
{
    print("MAILBOX REALLOC!\n");
    return _mbx_allocators.f_realloc(ptr, size);
}

inline void mbx_free(void *ptr)
{
    print("MAILBOX FREE!\n");
    _mbx_allocators.f_free(ptr);
}

#endif /* MBX_ALLOCATORS_H_INCLUDED */