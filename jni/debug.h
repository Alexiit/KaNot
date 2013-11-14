#ifndef DEBUG_H
#define DEBUG_H

#include <Win32toAndroid.h>
#if __ANDROID__
#include <jni.h>
#include <android/log.h>
#include <GLES2/gl2.h>
#include<GLES2/gl2ext.h>
//#define LOG_TAG  "libLostCause"
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#else
#include <Windows.h>
#include <iostream>
#define  LOGI(...)  PrintToOutput(false,__VA_ARGS__)
//Use tostring()
#define  LOGE(...)  PrintToOutput(true,__VA_ARGS__)
void PrintToOutput(bool error, const char* format, ...);
#endif

class debug
{
public:

	static void printGLString(const char *name, GLenum s);
	static void checkGlError(const char* op);
};

#endif