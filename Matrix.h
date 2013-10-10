#pragma once
#include <iostream>
#include "vector.h"




namespace PM
{

	class Matrix3
	{
	public:
		Matrix3();
		Matrix3(Vector3 vaaka, Vector3 pysty);
		Matrix3(float ij00, float ij01, float ij02, float ij10, float ij11, float ij12, float ij20, float ij21, float ij22);
		~Matrix3();


		static Matrix3 mxv(Matrix3 lM,Vector3 rV);
		static Matrix3 mxm(Matrix3, Matrix3);
		Matrix3 MT();
		Matrix3 MT(float ij00, float ij01, float ij02, float ij10, float ij11, float ij12, float ij20, float ij21, float ij22);

		////////////////////keskeneräiset///////////////////////////


		Matrix3 invert();


		float matrix[3][3];
	};


}
