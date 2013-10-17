#ifndef SPRITE_H
#define	SPRITE_H

#include "calc.h"
#include "Matrix.h"
#include "Shapes.h"
#include "Vector.h"


class Sprite
{
public:
	Sprite(void);
	~Sprite(void);

	Shapes::Rect hitBox;
	
};

#endif