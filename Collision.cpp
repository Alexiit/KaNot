#include "Collision.h"
//#include "calc.h"
#include "sprite.h"

Collision::Collision(void)
{
}


Collision::~Collision(void)
{
}






PM::Vector3 newSpeed(Sprite* currentSprite, PM::Vector3 wall, PM::Vector3 oldSpeed)
{
	float angle = 3.141593 - 2*PM::angleBV(oldSpeed, wall);


	PM::Matrix3 rotMat(					cos(angle),			-sin(angle),		0,
										sin(angle),			cos(angle),			0,
										0,					0,					1);
	
	PM::Vector3 newSpeed = PM::vxm(oldSpeed, rotMat);
	currentSprite->m_velocity = newSpeed;


	return newSpeed;

} 