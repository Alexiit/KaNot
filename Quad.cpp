#include "Quad.h"
#include <Shader.h>
float* Quad::Projection = NULL;

Quad::Quad(int W,int H,int X, int Y)
{
	w = W;
	h = H;
	x = X;
	y = Y;

	Translation = (float*)calloc(16,sizeof(float));
	Rotation = (float*)calloc(16,sizeof(float));
	glGenBuffers(1,&VBO);
	GenBuffer();
	move(x,y);
	
}

void Quad::GenBuffer()
{
	float* Data = (float*)malloc(30*sizeof(float));

	Data[0] = -w/2; 
    Data[1] = -h/2; 
    Data[2] = 0; 

    Data[3] = 0; 
    Data[4] = 0; 


    Data[5] = -w/2; 
    Data[6] = h/2; 
    Data[7] = 0;

    Data[8] = 0; 
    Data[9] = 1; 


    Data[10] = w/2; 
    Data[11] = -h/2; 
	Data[12] = 0; 

    Data[13] = 1; 
    Data[14] = 0; 
    

    Data[15] = -w/2; 
    Data[16] = h/2; 
    Data[17] = 0; 

	Data[18] = 0; 
    Data[19] = 1; 


    Data[20] = w/2; 
    Data[21] = h/2; 
	Data[22] = 0; 

    Data[23] = 1; 
    Data[24] = 1; 


    Data[25] = w/2; 
    Data[26] = -h/2; 
    Data[27] = 0; 

	Data[28] = 1; 
    Data[29] = 0; 
	
  
  
    glBindBuffer(GL_ARRAY_BUFFER,VBO); 
  
    glBufferData(GL_ARRAY_BUFFER,sizeof(Data)*30,Data,GL_DYNAMIC_DRAW); 
}

void Quad::move(int X,int Y)
{
	Translation[0] = 1;
	Translation[3] = X;
	Translation[5] = 1;
	Translation[7] = Y;
	Translation[10] = 1;
	Translation[15] = 1;
	x = X; y = Y;
}

void Quad::resize(int W,int H)
{
	w = W;
	h = H;
	GenBuffer();
}

void Quad::rotate(float)
{
	//ei tehdä vielä, irrelevanttia
}

void Quad::Draw(float z)
{
	glUseProgram(shader->Program);

	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	Translation[11] = z;
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texid);

	glUniform1i(shader->loc, 0); 

    glVertexAttribPointer(shader->Position,3,GL_FLOAT,GL_FALSE,5*sizeof(GL_FLOAT),0); 
	glVertexAttribPointer(shader->Uv,2,GL_FLOAT,GL_FALSE,5*sizeof(GL_FLOAT),(void*)(sizeof(GL_FLOAT)*3)); 
	glUniformMatrix4fv(shader->loc2,1,GL_FALSE,Projection);
	glUniformMatrix4fv(shader->loc3,1,GL_FALSE,Translation);
	glBindBuffer(GL_ARRAY_BUFFER,VBO); 
    glDrawArrays(GL_TRIANGLES,0,30); 
}

void Quad::setTexture(GLuint Texture)
{
	texid = Texture;
}

void Quad::setShader(Shader* shader)
{
	this->shader = shader;
}

Quad::~Quad(void)
{
}
