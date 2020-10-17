#include <mbxlib.h>
#include <mbx/mbx_allocators.h>
#include <cstdlib>

// Allocators

struct mbx_allocators_s _mbx_allocators = {
    malloc,
    realloc,
    free
};

void mbx_set_allocators(
    void *(*f_malloc)(size_t),
    void *(*f_realloc)(void *, size_t),
    void (*f_free)(void *))
{
    _mbx_allocators.f_malloc = f_malloc;
    _mbx_allocators.f_realloc = f_realloc;
    _mbx_allocators.f_free = f_free;
}
