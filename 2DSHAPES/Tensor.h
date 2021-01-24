#pragma once
#include <vector>
#include <assert.h>
using namespace std;

class Tensor
{

};

class C2DVector
{
public:

	C2DVector();
	C2DVector(double x, double y);
	~C2DVector();

	//Operators overloading for vector operations
	C2DVector operator+(const C2DVector& vec);
	double operator*(const C2DVector& vec);

public:
	vector<double> m_vec;


};

class C2X2Mat
{
public:

	C2X2Mat();
	C2X2Mat(double a11, double a12, double a21, double a22);
	~C2X2Mat();

	//Operators overloading for matrix operations
	C2DVector operator*(const C2DVector& vec);

public:
	vector<double> m_mat;
};