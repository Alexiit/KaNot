#include "debug.h"

#ifdef _WIN32
void PrintToOutput(bool error, const char* format, ...)
{
        va_list args;

        char message[10240];
        va_start(args,format);
        vsprintf(message,format,args);
        va_end(args);

                
        OutputDebugStringA("\n");
        if (error)
                OutputDebugStringA(" --(ERROR)-- ");
        OutputDebugStringA(message);
}
#endif

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