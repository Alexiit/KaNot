#include "Matrix.h"
#include "vector.h"
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
	Vector3 Vector3::vPlus(Vector3 v)
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
}

















//
//
//
//int Matic::mxm(float mA[3][3], float mB[3][3])
//	{
//		float AB[3][3]={{0,0,0},{0,0,0},{0,0,0}}; // Matriisien kertolaskun vastaus tallentuu tähän
//		bool okSuorit=0; // tästä voi tarkistaa, että prosessi on suoritettu loppuun
//
//		for(int i=0;i<3;i++)
//		{
//			for(int j=0; j<3;j++)
//			{
//				float vA[3]={mA[i][0],mA[i][1],mA[i][2]};
//				float vB[3]={mB[0][j],mB[1][j],mB[2][j]};
//
//			AB[i][j]= Matic::dot(vA,vB);
//			}
//		}
//
//
////------------matriisin piirto------------------------
//
//		for(int i=0; i<3;i++)
//			{
//				for(int j=0;j<3;j++)
//				{
//					cout << AB[i][j] << "   ";
//				}
//				cout << endl << endl;
//			}
////----------------------------------------------------
//
//	return okSuorit;
//	}
//
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////     Determinant 2    //////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//float Matic::det2(float m22[2][2])
//{
//	float det=0;
//
//	det=m22[0][0]*m22[1][1]-m22[0][1]*m22[1][0];
//	return det;
//}
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////     Determinant 3    //////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//float det3(float m22[3][3])
//{
//	float det=0;
//
//	float op1=(m22[0][0]*m22[1][1]-m22[0][1]*m22[1][0])*m22[2][2];
//	float op2=(m22[0][0]*m22[2][1]-m22[0][1]*m22[2][0])*m22[1][2];
//	float op3=(m22[1][0]*m22[2][1]-m22[2][0]*m22[1][1])*m22[0][2];
//	det = op1 - op2 + op3;
//	return det;
//}
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////     Transponoitu Matriisi    ///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//int Matic::transpose(float m33[3][3])
//{
//	float mt[3][3]={{0,0,0},{0,0,0},{0,0,0}};
//	for(int i=0;i<3;i++)
//		{
//			for(int j=0; j<3;j++)
//			{
//				mt[i][j] = m33[j][i];
//
//
//				cout << mt[i][j]<<"    ";
//
//			}
//			cout <<endl<< endl;
//		}
//
//	return 0;
//}
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////     Alideterminantti    ///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//
//float Matic::subDet(float m33[3][3],int RC[2])
//{
//	float dVertical[2][3]={{0,0,0},{0,0,0}};
//	float dHorizontal[2][2]={{0,0},{0,0}};
//	float subDet=0;
////-------- Reducing row count ------------------
//
//	if(RC[0]==1) // Row #1 deletetd
//		{
//			dVertical[0][0]=m33[1][0];
//			dVertical[0][1]=m33[1][1];
//			dVertical[0][2]=m33[1][2];
//			dVertical[1][0]=m33[2][0];
//			dVertical[1][1]=m33[2][1];
//			dVertical[1][2]=m33[2][2];
//		}
//	if (RC[0]==2) // Row #2 deletetd
//		{
//			dVertical[0][0]=m33[0][0];
//			dVertical[0][1]=m33[0][1];
//			dVertical[0][2]=m33[0][2];
//			dVertical[1][0]=m33[2][0];
//			dVertical[1][1]=m33[2][1];
//			dVertical[1][2]=m33[2][2];
//		}
//
//	if (RC[0]==3) // Row #2 deletetd
//		{
//			dVertical[0][0]=m33[0][0];
//			dVertical[0][1]=m33[0][1];
//			dVertical[0][2]=m33[0][2];
//			dVertical[1][0]=m33[1][0];
//			dVertical[1][1]=m33[1][1];
//			dVertical[1][2]=m33[1][2];
//		}
////------------ End red.rows ------------------
////-------- Reducing column count ------------------
//		if(RC[1]==1)  // Column #1 deletetd
//		{
//			dHorizontal[0][0]=dVertical[0][1];
//			dHorizontal[0][1]=dVertical[0][2];
//			dHorizontal[1][0]=dVertical[1][1];
//			dHorizontal[1][1]=dVertical[1][2];
//		}
//
//		if(RC[1]==2)  // Column #1 deletetd
//		{
//			dHorizontal[0][0]=dVertical[0][0];
//			dHorizontal[0][1]=dVertical[0][2];
//			dHorizontal[1][0]=dVertical[1][0];
//			dHorizontal[1][1]=dVertical[1][2];
//		}
//
//		if(RC[1]==3)  // Column #1 deletetd
//		{
//			dHorizontal[0][0]=dVertical[0][0];
//			dHorizontal[0][1]=dVertical[0][1];
//			dHorizontal[1][0]=dVertical[1][0];
//			dHorizontal[1][1]=dVertical[1][1];
//		}
////-------- End Reducing column count ------------------
//
//cout<<"RC-Vector: ("<<RC[0]<<","<<RC[1]<<")"<<endl;
//
////------------alidet piirto------------------------
//
//		for(int i=0; i<2;i++)
//			{
//				for(int j=0;j<2;j++)
//				{
//					cout << dHorizontal[i][j] << "   ";
//				}
//				cout << endl << endl;
//			}
////----------------------------------------------------
//
//
//
//
////------------matriisin piirto------------------------
//
//		for(int i=0; i<3;i++)
//			{
//				for(int j=0;j<3;j++)
//				{
//					cout << m33[i][j] << "   ";
//				}
//				cout << endl << endl;
//			}
////----------------------------------------------------
//		subDet=det2(dHorizontal);
//
//
//
//	return subDet;
//}	


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////     Käänteismatriisi    ///////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//float invm(float m33[3][3])
//{
//	float detm33=det3(m33);
//std::cout << "det mm3: "<<detm33<<endl;
//// Tarkistetaan matriisin singulaarisuus:
//if (detm33 != 0)
//{
//
//
////---------alideterminanttien lasku ja sijoitus sekä jako determinantilla-----------
//float invm[3][3] = {{0,0,0},{0,0,0},{0,0,0}}; //alustus
//
//for(int i=0; i<3; i++)
//	{
//		for(int j=0; j<3; j++)
//		{
//			int RC[2]={i+1,j+1}; //vektori subDet():lle rivien ja sarakkeiden poistamiseksi.
//			
//			invm[i][j]=(subDet(m33, RC)/detm33);
//			
//			if (invm[i][j]<0)//if-lause toteuttaa itseisarvon.
//			{
//			invm[i][j]=invm[i][j]*pow(float(-1),i+j+1);
//			}
//			else
//			{
//			invm[i][j]=invm[i][j]=invm[i][j]*pow(float((-1)),i+j);
//			}
//		}
//
//	}
////---------transponointi------------------
//Matic::transpose(invm);
//
//
////------------matriisin piirto------------------------
//
////Alkup. Matriisi:
//cout << "Matriisi:"<<endl;
//
//for(int i=0; i<3;i++)
//	{
//		for(int j=0;j<3;j++)
//		{
//			cout << m33[i][j] << "   ";
//		}
//		cout << endl << endl;
//	}
//
////Käänteismatriisi
//cout << endl << endl << "Kaanteismatriisi:"<<endl;
//
//for(int i=0; i<3;i++)
//	{
//		for(int j=0;j<3;j++)
//		{
//			cout << invm[i][j] << "   ";
//		}
//		cout << endl << endl;
//	}
////----------------------------------------------------
//return 1;
//}
//else
//return 0;
//}
//
//
//
//float Matic::solve3(float m33[3][3], float ans3[])
//{
//	float ans[3] = Matic::mxv(Matic::invm(m33),ans3);
//	return 0;
//
//}
//
//
//Matic::~Matic(void)
//{
//}
//
//
//
//
//namespace PM
//{
//	Vector3::Vector3()
//		: x(0),
//		  y(0),
//		  z(0)
//	{}
//
//	float& Vector3::operator [](int index)
//	{
//		return (&x)[index];
//	}
//
//	const float& Vector3::operator [](int index) const
//	{
//		return (&x)[index];
//	}
//
//
//	Matrix3::Matrix3(Vector3 pysty, Vector3 vaaka)
//	{
//		for (int i=0; i<3; i++)
//		{
//			for(int j=0;j<3; j++)
//			{
//				matrix[i][j] = pysty[i] * vaaka[j];
//			}
//		}
//	}
//}