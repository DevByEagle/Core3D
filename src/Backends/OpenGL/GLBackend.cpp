#include "GLBackend.h"

bool GLBackend::IsSupported()
{
#if defined(CORE3D_USE_OPENGL)
    return true;
#else
    return false; // OpenGL is not supported if the macro is not defined
#endif
}