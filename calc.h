#pragma once
#include "vector.h"
#include "Matrix.h"

namespace PM
{


	////////////////////////////////////////////////////////////// Vektori * Matriisi /////////////////////////////////////////////////////////////////////////////
	static Vector3 vxm(Vector3 lV, Matrix3 rM)
	{
		Vector3 vertiVec;
		Vector3 product;
		for(int x=0; x<3; x++)
		{

				vertiVec.x=rM.matrix[0][0];
				vertiVec.y=rM.matrix[1][0];
				vertiVec.z=rM.matrix[2][0];
				product.x = lV.dot(vertiVec);
				vertiVec.x=rM.matrix[0][1];
				vertiVec.y=rM.matrix[1][1];
				vertiVec.z=rM.matrix[2][1];
				product.y = lV.dot(vertiVec);
				vertiVec.x=rM.matrix[0][2];
				vertiVec.y=rM.matrix[1][2];
				vertiVec.z=rM.matrix[2][2];
				product.z = lV.dot(vertiVec);

		return product;
		}

	}

	Vector3 solve(Matrix3 leftM, Vector3 rightV)
	{
		Vector3 ansVec;
		if(leftM.det()!=0)
		ansVec = PM::vxm(rightV, leftM.invert());
		return ansVec;
	}



}