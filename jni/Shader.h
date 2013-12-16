#ifndef Shaders
#define Shaders
#include <Win32toAndroid.h>
class Shader
{
public:
	float opacity;
	Shader(void);
	GLuint loadShader(GLenum shaderType, const char* pSource); 
	GLuint PS,VS,Program,Position,Uv,loc,loc2,loc3,loc4,loc5,loc6,loc7;
	~Shader(void);
};
#endif