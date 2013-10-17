#pragma once
#include <iostream>
#include "vector.h"
#include "Matrix.h"
#include "Shapes.h"
#include "Calc.h"

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
		if(angle > 4.28318)
		{
			angle = angle / 4.28318;

		}
		PM::Matrix3 rotM(cos(angle),-sin(angle),0,sin(angle),cos(angle), 0,0,0,1);


		Rect.right.line.dirVec = PM::vxm(Rect.right.line.dirVec, rotM); // rotatoi oikean sivun suunta vektorin
		Rect.right.line.dplVec = PM::vxm(Rect.right.line.dplVec, rotM); // rotatoi siirtymävectorin lokaalin origon (Rect.m_Pos) suhteen.
		
		Rect.top.line.dirVec = PM::vxm(Rect.top.line.dirVec, rotM);
		Rect.top.line.dplVec = PM::vxm(Rect.top.line.dplVec, rotM);
	
		Rect.left.line.dirVec = PM::vxm(Rect.left.line.dirVec, rotM);
		Rect.left.line.dplVec = PM::vxm(Rect.left.line.dplVec, rotM);
	
		Rect.bottom.line.dirVec = PM::vxm(Rect.bottom.line.dirVec, rotM);
		Rect.bottom.line.dplVec = PM::vxm(Rect.bottom.line.dplVec, rotM);

	}


	Rect::~Rect(){}

}





