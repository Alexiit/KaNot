#include "Matrix.h"
#include "vector.h"
#include "Shapes.h"
#include <iostream>
#include <cmath>
using namespace std;


namespace PM
{
	Vector3::Vector3()
	{
		x=y=z=0;
	}
	Vector3::~Vector3(){}

	float Vector3::dot(Vector3 v1, Vector3 v2)
	{	
		float dot=0;
		dot = v1.x*v2.x+ v1.y*v2.y+v1.z*v2.z;
		return dot;
	}

	float Vector3::dot(Vector3 v2)
	{	
		float dot=0;
		dot = this->x*v2.x+ this->y*v2.y+this->z*v2.z;
		return dot;
	}
}

namespace PM 
{


	Matrix3::Matrix3(){}

	Matrix3::Matrix3(float ij00, float ij01, float ij02, float ij10, float ij11, float ij12, float ij20, float ij21, float ij22)
	{
		matrix[0][0]=ij00;
		matrix[0][1]=ij01;
		matrix[0][2]=ij02;
		matrix[1][0]=ij10;
		matrix[1][1]=ij11;
		matrix[1][2]=ij12;
		matrix[2][0]=ij20;
		matrix[2][1]=ij21;
		matrix[2][2]=ij22;
	}


	////////////////////////////////////////////////////////////// Matriisi * Matriisi /////////////////////////////////////////////////////////////////////////////


	Matrix3 Matrix3::mxm(Matrix3 mL, Matrix3 mR)
	{

		Matrix3 product;

		for(int i=0;i<3;i++)
		{
			for(int j=0; j<3;j++)
			{
				Vector3 vL;
				Vector3 vR;

				vL.x = mL.matrix[i][0];
				vL.y = mL.matrix[i][1];
				vL.z = mL.matrix[i][2];


				vR.x = mR.matrix[0][j];
				vR.y = mR.matrix[1][j];
				vR.z = mR.matrix[2][j];


				float dot=0;
				dot = vL.x*vR.x+ vL.y*vR.y+vL.z*vR.z;


				product.matrix[i][j]=dot;

			}
		}

		return product;
	}


	Matrix3::~Matrix3()
	{}




	////////////////////////////////////////////////////////////// transponointi /////////////////////////////////////////////////////////////////////////////



	Matrix3 Matrix3::MT()
	{
		Matrix3 transpose;
		float temp;
		int j=0;
		int i=0;
		int k=3;
		int n=0;
		while(i<3)

		{

			while(j<k)
			{
				temp = matrix[i][j+n];
				transpose.matrix[i][j+n]=matrix[j+n][i];
				transpose.matrix[j+n][i]=temp;
				j++;
			}
			j=0;
			k--;
			i++;
			n++;
		}

		return transpose;
	}


	Matrix3 Matrix3::MT(float ij00, float ij01, float ij02, float ij10, float ij11, float ij12, float ij20, float ij21, float ij22)
	{
		Matrix3 transpose;
		transpose.matrix[0][0]=ij00;
		transpose.matrix[0][1]=ij10;
		transpose.matrix[0][2]=ij20;
		transpose.matrix[1][0]=ij01;
		transpose.matrix[1][1]=ij11;
		transpose.matrix[1][2]=ij21;
		transpose.matrix[2][0]=ij02;
		transpose.matrix[2][1]=ij12;
		transpose.matrix[2][2]=ij22;
		return transpose;
	}


	////////////////////////////////////////////////////////////// Matriisi * Vektori /////////////////////////////////////////////////////////////////////////////

	Matrix3 Matrix3::mxv(Matrix3 lM,Vector3 rV)
	{
		Matrix3 product;


		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(j==0)
				{
					product.matrix[i][j] = lM.matrix[i][j]*rV.x;
				}
				if(j==1)
				{
					product.matrix[i][j] = lM.matrix[i][j]*rV.y;
				}
				if(j==2)
				{
					product.matrix[i][j] = lM.matrix[i][j]*rV.z;
				}
			}

		}
		return product;
	}



	////////////////////////////////////////////////////////////// Käänteismatriisi /////////////////////////////////////////////////////////////////////////////

	Matrix3 Matrix3::invert()
	{
		Matrix3 MI;

		float dVertical[2][3]={{0,0,0},{0,0,0}};
		float dHorizontal[2][2]={{0,0},{0,0}};


		float det=0;

		float op1=(matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0])*matrix[2][2];
		float op2=(matrix[0][0]*matrix[2][1]-matrix[0][1]*matrix[2][0])*matrix[1][2];
		float op3=(matrix[1][0]*matrix[2][1]-matrix[2][0]*matrix[1][1])*matrix[0][2];
		det = op1 - op2 + op3;




		for(int i=0;i<3;i++)

		{
			for(int j=0;j<3;j++)
			{
				//-------- Reducing row count ------------------

				if(i==0) // Row #1 deletetd
				{
					dVertical[0][0]=matrix[1][0];
					dVertical[0][1]=matrix[1][1];
					dVertical[0][2]=matrix[1][2];
					dVertical[1][0]=matrix[2][0];
					dVertical[1][1]=matrix[2][1];
					dVertical[1][2]=matrix[2][2];
				}
				if (i==1) // Row #2 deletetd
				{
					dVertical[0][0]=matrix[0][0];
					dVertical[0][1]=matrix[0][1];
					dVertical[0][2]=matrix[0][2];
					dVertical[1][0]=matrix[2][0];
					dVertical[1][1]=matrix[2][1];
					dVertical[1][2]=matrix[2][2];
				}

				if (i==2) // Row #2 deletetd
				{
					dVertical[0][0]=matrix[0][0];
					dVertical[0][1]=matrix[0][1];
					dVertical[0][2]=matrix[0][2];
					dVertical[1][0]=matrix[1][0];
					dVertical[1][1]=matrix[1][1];
					dVertical[1][2]=matrix[1][2];
				}
				//------------ End red.rows ------------------
				//-------- Reducing column count ------------------
				if(j==0)  // Column #1 deletetd
				{
					dHorizontal[0][0]=dVertical[0][1];
					dHorizontal[0][1]=dVertical[0][2];
					dHorizontal[1][0]=dVertical[1][1];
					dHorizontal[1][1]=dVertical[1][2];
				}

				if(j==1)  // Column #1 deletetd
				{
					dHorizontal[0][0]=dVertical[0][0];
					dHorizontal[0][1]=dVertical[0][2];
					dHorizontal[1][0]=dVertical[1][0];
					dHorizontal[1][1]=dVertical[1][2];
				}

				if(j==2)  // Column #1 deletetd
				{
					dHorizontal[0][0]=dVertical[0][0];
					dHorizontal[0][1]=dVertical[0][1];
					dHorizontal[1][0]=dVertical[1][0];
					dHorizontal[1][1]=dVertical[1][1];
				}

				MI.matrix[i][j]= ((dHorizontal[0][0]*dHorizontal[1][1] - dHorizontal[1][0] * dHorizontal[0][1]*pow(double(-1),i+j))/det);

			}
		}

		MI=MI.MT();
		return MI;
	}	


	////////////////////////////////////////////////////////////// Vektori + Vektori /////////////////////////////////////////////////////////////////////////////
	Vector3 Vector3::plus(Vector3 v)
	{
		v.x+=x;
		v.y+=y;
		v.z+=z;
		return v;
	}

	Vector3 Vector3::neg()
	{
		Vector3 neg;
		neg.x=-x;
		neg.y=-y;
		neg.z=-z;
		return neg;
	}

	Vector3 Vector3::swap(char a, char b)
	{
		Vector3 swap;
		if(a == 'x' && b == 'y')
		{
			char temp = a;
			swap.x= y;
			swap.y=temp;
			swap.z=z;
		}

		if(a == 'x' && b == 'z')
		{
			char temp = a;
			swap.x= z;
			swap.y=y;
			swap.z=temp;

		}

		if(a == 'y' && b == 'z')
		{
			char temp = y;
			swap.x= x;
			swap.y=z;
			swap.z=temp;

		}

		return swap;
	}


	Vector3 Vector3::neg(char element)
	{
		Vector3 neg;
		if (element == x)
		{
			neg.x=-x;
			neg.y=y;
			neg.z=z;

		}
		if (element == y)
		{
			neg.x=x;
			neg.y=-y;
			neg.z=z;

		}
		if (element == z)
		{
			neg.x=x;
			neg.y=y;
			neg.z=-z;


			return neg;}
	}

	Matrix3 Matrix3::scal(float scal)
	{
		Matrix3 mulMat;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
			mulMat.matrix[i][j] = Matrix3::matrix[i][j]*scal;
			}
		}
		return mulMat;
	}


	Matrix3 Matrix3::add(Matrix3 other)
	{
		Matrix3 add;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				add.matrix[i][j] = Matrix3::matrix[i][j]+other.matrix[i][j];
			}
		}
		return add;
	
	}

		Matrix3 Matrix3::minus(Matrix3 other)
	{
		Matrix3 minus;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				minus.matrix[i][j] = Matrix3::matrix[i][j]-other.matrix[i][j];
			}
		}
		return minus;
	
	}

		void Matrix3::identity()
		{
			Matrix3 identity(1,0,0,0,1,0,0,0,1);
		}


		float Matrix3::det()
		{
		float det;
		float op1=(matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0])*matrix[2][2];
		float op2=(matrix[0][0]*matrix[2][1]-matrix[0][1]*matrix[2][0])*matrix[1][2];
		float op3=(matrix[1][0]*matrix[2][1]-matrix[2][0]*matrix[1][1])*matrix[0][2];
		det = op1 - op2 + op3;

		return det;
		}

	Vector3 Vector3::scal(float scal)
	{
	Vector3 product;
	product.x=scal*x;
	product.y=scal*y;
	product.z=scal*z;
	return product;
	}


	Vector3 Vector3::minus(Vector3 minusV)
	{
	Vector3 ans;
	ans.x=x-minusV.x;
	ans.y=y-minusV.y;
	ans.z=z-minusV.z;
	return ans;
	}

	float Vector3::getLenght()
	{
	float lenght;
	lenght = sqrt(pow(x,2)+pow(y,2));
	return lenght;
	}

	float angle(Vector3 vecA, Vector3 vecB)
	{
	float angle;
	angle = acos(vecA.dot(vecB)/(vecA.getLenght()*vecB.getLenght()));
	return angle;
	}

	
	Vector3 Vector3::devScal(float scal)
	{
	Vector3 product;
	product.x=x/scal;
	product.y=y/scal;
	//product.z=z/scal disambled due to z-buffer//
	return product;
	}


	Vector3 Vector3::normalize()
	{
	Vector3 norm;
	norm = norm.devScal(norm.getLenght());
	return norm;
	
	}

	Vector3 Vector3::multipScal(float scal)
	{
	Vector3 devision;
	devision.x=x*scal;
	devision.y=y*scal;
	return devision;
	//devision.z=z*scal disambled due to z-buffer//
	}




}
