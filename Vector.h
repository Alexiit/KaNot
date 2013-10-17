#pragma once
#include <iostream>
namespace PM
{
	class Vector3
	{
	public:
		Vector3();
		~Vector3();

		static float dot(Vector3 v1, Vector3 v2);
		float dot(Vector3 v2);

		float x,y,z;

		Vector3 scal(float);
		Vector3 plus(Vector3);
		Vector3 neg();
		Vector3 neg(char);
		Vector3 minus(Vector3);
		float angle(Vector3 vecA, Vector3 vecB);
		Vector3 swap(char, char);
		float& operator [](int index);
		float getLenght();
		const float& operator [](int index) const;
		Vector3 normalize();
		Vector3 devScal(float scal);
		bool circleDot(Vector3);

	};
}



