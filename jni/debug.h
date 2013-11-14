#ifndef DEBUG_H
#define DEBUG_H
//#if __ANDROID__
//#include <jni.h>
//#include <android/log.h>
//#include <GLES2/gl2.h>
//#include<GLES2/gl2ext.h>
//#define LOG_TAG  "libLostCause"
//#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
//#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
//#else
#include <Win32toAndroid.h>
//#endif

class debug
{
public:
	debug(void);
	~debug(void);

	static void printGLString(const char *name, GLenum s);
	static void checkGlError(const char* op);
};

#endif