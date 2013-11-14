/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// OpenGL ES 2.0 code

#include <Win32toAndroid.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Engine.h>
#include <FileReader.h>
#include <iostream>
#include <debug.h>



Engine* engine;
bool setupGraphics(int w, int h) {
    debug::printGLString("Version", GL_VERSION);
    debug::printGLString("Vendor", GL_VENDOR);
    debug::printGLString("Renderer", GL_RENDERER);
    debug::printGLString("Extensions", GL_EXTENSIONS);

	std::cout << "2"<<std::endl;
    LOGI("setupGraphics(%d, %d)", w, h);
std::cout << "3"<<std::endl;
	engine = new Engine();
	LOGI("easd");
	engine->fixAspectRatio(780,1280,w,h);
	LOGI("far");
    return true;
}

void renderFrame() {
	engine->Update();
	engine->Draw();
}

extern "C" {
    JNIEXPORT void JNICALL Java_com_android_KaNot_KaNotLib_init(JNIEnv * env, jobject obj,  jint width, jint height);
    JNIEXPORT void JNICALL Java_com_android_KaNot_KaNotLib_step(JNIEnv * env, jobject obj);
	JNIEXPORT void JNICALL Java_com_android_KaNot_KaNotLib_GetManager(JNIEnv* env, jclass clazz, jobject assetManager);
};

JNIEXPORT void JNICALL Java_com_android_KaNot_KaNotLib_init(JNIEnv * env, jobject obj,  jint width, jint height)
{
std::cout << "4"<<std::endl;
    setupGraphics(width, height);
	std::cout << "5"<<std::endl;
}

JNIEXPORT void JNICALL Java_com_android_KaNot_KaNotLib_step(JNIEnv * env, jobject obj)
{
    renderFrame();
}

JNIEXPORT void JNICALL Java_com_android_KaNot_KaNotLib_GetManager(JNIEnv* env, jclass clazz, jobject assetManager)
{
    AAssetManager* mgr = AAssetManager_fromJava(env, assetManager);
	FileReader::mgr = mgr;
}
