#pragma once
#include <Win32toAndroid.h>
class Shader
{
public:
	Shader(void);
	GLuint loadShader(GLenum shaderType, const char* pSource); 
	GLuint PS,VS,Program,Position,Uv;
	GLint loc,loc2,loc3;
	~Shader(void);
};

