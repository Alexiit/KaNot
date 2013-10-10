#pragma once
#include <iostream>
#include "vector.h"

namespace Shapes
{

	class Line
	{
	public: 
		Line();
		~Line();
		PM::Vector3 line;
		PM::Vector3 dpl;
	};


	class Segm
	{
	public: 
		Segm();
		~Segm();
		PM::Vector3 line;
		PM::Vector3 dpl;
		float length;
	};


	class Ellipse
	{
	public: 
		Ellipse();
		~Ellipse();
		PM::Vector3 pos;
		PM::Vector3 size;

	};

}