#ifndef MBX_CONTAINERS_H_INCLUDED
#define MBX_CONTAINERS_H_INCLUDED

// STL containers using our allocator

#include <mbx/proxy_allocator.h>

#include <list>
#include <string>

namespace mbox {

    template <typename T>
    using List = std::list<T *, proxy_allocator<T *> >;
    
    typedef std::basic_string < char, std::char_traits<char>,
        proxy_allocator<char> > String;
}
#endif /* MBX_ALLOCATORS_H_INCLUDED */