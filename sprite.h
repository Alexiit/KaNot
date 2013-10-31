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
	PM::Vector3 m_pos;
	PM::Vector3 m_velocity;
	PM::Vector3 m_acceleration;
	PM::Vector3 force;
	float max_vel;
	float mass;

	
};

#endif