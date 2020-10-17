#include <mbxlib.h>

// Versions

uint32_t mbx_get_version(void)
{
    return MBX_VERSION;
}

int32_t mbx_is_compatible_dll(void)
{
    uint32_t major = mbx_get_version() >> 24;
    return major == MBX_VERSION_MAJOR;
}
