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
	Vector3 m_pos;
	Vector3 m_velocity;
	Vector3 m_acceleration;
	Vector3 force;
	float max_vel;
	float mass;

	
};

#endif