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

		Vector3 vPlus(Vector3);
		Vector3 neg();
		Vector3 neg(char);
		Vector3 swap(char, char);
		float& operator [](int index);
		const float& operator [](int index) const;


	};
}



