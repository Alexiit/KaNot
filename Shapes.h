#pragma once
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
		PM::Vector3 dir;
		PM::Vector3 dpl;
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
		PM::Vector3 pos;
		Segm side0;
		Segm side1;
		Segm side2;
		Segm side3;
	
	};


	class Circl
	{
	public: 
		Circl();
		~Circl();
		PM::Vector3 pos;
		float radius;
		PM::Matrix3 eqCircl();

	};



	class Elli
	{
	public: 
		Elli();
		~Elli();
		PM::Vector3 pos;
		PM::Vector3 size;
		PM::Matrix3 eqElli();

	};


}