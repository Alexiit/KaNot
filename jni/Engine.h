#ifndef ENGINE
#define ENGINE

#include <debug.h>
#include <Win32toAndroid.h>
#include "Texture.h"

class Shader;
class Quad;

class Engine
{
public:

	Engine();
	~Engine(); 
	void fixAspectRatio(float desiredWidth,float desiredHeight,float width,float height);
	void Update();
	void Draw();
	float Scale,blackBarH,blackBarV;
	int x,y;

	private:
		//GLuint VBO,VBO2,Program,PS,VS,Position,Uv,Texture;
		//GLint loc,loc2,loc3;
		GLfloat* GlProjection;
		//GLfloat* GlTranslation;
		//unsigned int num_vertices;
		//GLfloat* Data;
		//float position;
		float sine;
		Quad* Quad1;
		Quad* Quad2;
		Texture m_texture1;
		Texture m_texture2;

};
#endif