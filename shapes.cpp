#pragma once
#include <iostream>
#include "vector.h"
#include "Matrix.h"
#include "Shapes.h"
#include "Calc.h"

#define FULLANGLE 6.283185

namespace Shapes
{

	Line::Line(){};
	Line::~Line(){};

	Segm::Segm(){};
	Segm::~Segm(){};

	Rect::Rect()
	{

		right.line.dplVec = m_Pos;
		right.line.dplVec.x += width/2;
		right.length = height;

		top.line.dplVec = m_Pos;
		top.line.dplVec.y += height/2;
		top.length = width;

		left.line.dplVec = m_Pos;
		left.line.dplVec.x -= width/2;
		left.length = height;

		bottom.line.dplVec = m_Pos;
		bottom.line.dplVec.y -= height/2;
		bottom.length = width;
	}

	void Rect::rotate(float angle)
	{
		if(angle > FULLANGLE)
		{
			angle = angle - FULLANGLE;
		}
		PM::Matrix3 rotM(	cos(angle),			-sin(angle),			0,
							sin(angle),			cos(angle),				0,
							0,					0,						1		);


		this->right.line.dirVec = PM::vxm(this->right.line.dirVec, rotM); // rotatoi oikean sivun suunta vektorin
		this->right.line.dplVec = PM::vxm(this->right.line.dplVec, rotM); // rotatoi siirtymävectorin lokaalin origon (Rect.m_Pos) suhteen.
		
		this->top.line.dirVec = PM::vxm(this->top.line.dirVec, rotM);
		this->top.line.dplVec = PM::vxm(this->top.line.dplVec, rotM);
	
		this->left.line.dirVec = PM::vxm(this->left.line.dirVec, rotM);
		this->left.line.dplVec = PM::vxm(this->left.line.dplVec, rotM);
	
		this->bottom.line.dirVec = PM::vxm(this->bottom.line.dirVec, rotM);
		this->bottom.line.dplVec = PM::vxm(this->bottom.line.dplVec, rotM);

	}


	Rect::~Rect(){}

}





