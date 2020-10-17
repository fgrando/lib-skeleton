#ifndef MBXLIB_H_INCLUDED
#define MBXLIB_H_INCLUDED

#include <stdint.h>
#include <cstddef>

//
// Version (32 bits)
// [major| minor| patch]
// [0-255|0-4095|0-4095]
//
///////////////////////////////////////////////////////////////////////////////
#define MBX_VERSION_MAJOR 0
#define MBX_VERSION_MINOR 1
#define MBX_VERSION_PATCH 0
#define MBX_VERSION ((MBX_VERSION_MAJOR << 24) | (MBX_VERSION_MINOR << 12) | MBX_VERSION_PATCH)
#define MBX_VERSION_BUILD_STR __DATE__##" "##__TIME__



//
// Library export flags
// Set flags during build to set Dynamic/Static build. Default is use as DLL.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef MBX_API
#   ifdef _WIN32
#       if defined(MBX_BUILD_SHARED) /* build as DLL */
#           define MBX_API __declspec(dllexport)
#       elif !defined(MBX_BUILD_STATIC) /* use the DLL */
#           define MBX_API __declspec(dllimport)
#       else /* build as static lib */
#           define MBX_API
#       endif
#   else
#       if __GNUC__ >= 4
#           define MBX_API __attribute__((visibility("default")))
#       else
#           define MBX_API
#       endif
#   endif
#endif



//
// The API
//
///////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
extern "C" {
#endif

    // Version data

    uint32_t mbx_get_version(void);
    int32_t mbx_is_compatible_dll(void);



    // Memory Allocation settigns

    MBX_API void mbx_set_allocators(
        void *(*f_malloc)(size_t),
        void *(*f_realloc)(void *, size_t),
        void (*f_free)(void *));
    MBX_API void *mbx_malloc(size_t size);
    MBX_API void *mbx_realloc(void *ptr, size_t size);
    MBX_API void mbx_free(void *ptr);
    MBX_API void *mbx_calloc(size_t count, size_t size);
    MBX_API char *mbx_strdup(const char *str);



    // Lib functionality 

    struct mbx_mailbox_s;
    typedef struct mbx_mailbox_s mbx_mailbox_t;

    MBX_API mbx_mailbox_t *mbx_mailbox_new();
    MBX_API void mbx_mailbox_free(mbx_mailbox_t *mbx);

    // check for new mail
    MBX_API void mbx_refresh(mbx_mailbox_t *mbx);
    
    // messages bigger tan 10 chars are not sent
    MBX_API int32_t mbx_send_message(mbx_mailbox_t *mbx, char* msg);

    // the only message is at index 1
    MBX_API const char *mbx_get_message(const mbx_mailbox_t *mbx, int32_t id);

#ifdef __cplusplus
}
#endif

#endif /* MBXLIB_H_INCLUDED */
