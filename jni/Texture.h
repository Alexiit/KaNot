#ifndef TEXTURE
#define TEXTURE

class Texture
{
public:
	Texture();
	~Texture();

	void LoadTexture(const char* path);
	unsigned int getTextureID();

private:
	unsigned int m_textureID;
	unsigned char* m_pixels;
};

#endif

