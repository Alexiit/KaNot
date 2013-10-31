#include "Shader.h"


GLuint Shader::loadShader(GLenum shaderType, const char* pSource) {
    GLuint shader = glCreateShader(shaderType);
    if (shader) {
        glShaderSource(shader, 1, &pSource, NULL);
        glCompileShader(shader);
        GLint compiled = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (!compiled) {
            GLint infoLen = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
            if (infoLen) {
                char* buf = (char*) malloc(infoLen);
                if (buf) {
                    glGetShaderInfoLog(shader, infoLen, NULL, buf);
                    #ifndef WINDOWS_FRAMEWORK
                    LOGE("Could not compile shader %d:\n%s\n",
                            shaderType, buf);
                    #else
 
                    #endif
                     
                         
                    free(buf);
                }
                glDeleteShader(shader);
                shader = 0;
            }
        }
    }
    return shader;
} 

Shader::Shader(void)
{
	    static const char gVertexShader[] = 
    "attribute vec3 vPosition;\n"
	"attribute vec2 vUv;\n"
	"uniform mat4 Projection;\n"
	"uniform mat4 Translation;\n"
	"varying vec2 Uv;\n"
    "void main() {\n"
	"  gl_Position = vec4(vPosition,1.0);\n"
	"  gl_Position *= Translation*Projection;\n"	
	"  Uv = vUv;\n"
    "}\n";
 
    static const char gFragmentShader[] = 
	"precision mediump float;\n"
	"varying vec2 Uv;\n"
	"uniform sampler2D s_texture;\n"
    "void main() {\n"
    "  gl_FragColor = texture2D(s_texture,Uv);\n"
    "}\n"; 

	PS = loadShader(GL_FRAGMENT_SHADER,gFragmentShader); 
    VS = loadShader(GL_VERTEX_SHADER,gVertexShader); 
  
    //make the shader program; 
    Program = glCreateProgram(); 
  
    //attach shaders to the program 
    glAttachShader(Program,VS); 
    glAttachShader(Program,PS); 
  
    //bind position string to attrib at loc 0 
    glBindAttribLocation(Program,0,"vPosition"); 
	//bind Color string to attrib at loc 1 
	glBindAttribLocation(Program,1,"vUv"); 

	Position = glGetAttribLocation(Program,"vPosition");
	Uv = glGetAttribLocation(Program,"vUv");
	loc = glGetUniformLocation(Program, "s_texture");
	loc2 = glGetUniformLocation(Program, "Projection");
	loc3 = glGetUniformLocation(Program, "Translation");
}


Shader::~Shader(void)
{
}
