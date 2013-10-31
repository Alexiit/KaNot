#pragma once
#include <Win32toAndroid.h>
class Shader;
class Quad
{
public:
	Quad(int,int,int,int);
	void move(int,int);
	void resize(int,int);
	void rotate(float);
	void Draw(float);
	void setTexture(GLuint);
	void setShader(Shader*);
	~Quad(void);
private:
	int x,y,w,h;
	void GenBuffer();
	float* Translation;
	float* Rotation;
	GLuint texid,VBO;
	Shader* shader;
	static float*Projection;

};

