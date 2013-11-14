# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := libKaNot
LOCAL_CFLAGS    := -Werror -D_STLP_USE_SIMPLE_NODE_ALLOC -DANDROID -frtti -fexceptions
LOCAL_SRC_FILES :=  gl_code.cpp \
					Engine.cpp \
					FileReader.cpp \
					Quad.cpp \
					Shader.cpp \
					debug.cpp\
					../Matic.cpp\
					../shapes.cpp
					
					
LOCAL_LDLIBS    := -llog -lGLESv2 -landroid

include $(BUILD_SHARED_LIBRARY)
