#ifndef COLLISION_H
#define	COLLISION_H
#include "Vector.h"
#include "sprite.h"
#include "Shapes.h"

class Collision
{
public:
	Collision(void);
	~Collision(void);

	PM::Vector3 newSpeed(Sprite*, float slope, PM::Vector3 oldSpeed);


	void circleVsLine(Sprite*, Sprite*);
	void checkL(Sprite*, Shapes::Line*); // collision with line
	void checkLS(Sprite*, Shapes::Line*); // collision with line segment
};




#endif