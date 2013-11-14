#include "debug.h"


debug::debug(void)
{
}


debug::~debug(void)
{
}

void debug::printGLString(const char *name, GLenum s) 
{
    const char *v = (const char *) glGetString(s);
    //LOGI("GL %s = %s\n", name, v);
}

void debug::checkGlError(const char* op)
{
    for (GLint error = glGetError(); error; error
            = glGetError()) {
        //LOGI("after %s() glError (0x%x)\n", op, error);
    }
}