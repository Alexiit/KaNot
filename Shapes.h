#ifndef SHAPES_H
#define	SHAPES_H

#include <iostream>
#include "vector.h"
#include "Matrix.h"

namespace Shapes
{

	class Line
	{
	public: 
		Line();
		~Line();
		PM::Vector3 dirVec;
		PM::Vector3 dplVec;
		PM::Matrix3 eqLine(float);
	};



	class Segm
	{
	public: 
		Segm();
		~Segm();
		Line line;
		float length;
	};

	class Rect
	{
	public:
		Rect();
		~Rect();
		void rotate(float angle);
		PM::Matrix3 rotM;

		float angle;
		PM::Vector3 m_Pos;
		float height;
		float width;
		Segm right;
		Segm top;
		Segm left;
		Segm bottom;
	
	};


	class Circl
	{
	public: 
		Circl();
		~Circl();
		PM::Vector3 m_Pos;
		float radius;
		PM::Matrix3 eqCircl();

	};



	class Elli
	{
	public: 
		Elli();
		~Elli();
		PM::Vector3 m_Pos;
		PM::Vector3 size;
		PM::Matrix3 eqElli();

	};


}

#endif