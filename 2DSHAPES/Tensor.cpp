#include "Tensor.h"
#include <vector>
#include <assert.h>
using namespace std;

C2DVector::C2DVector() {
	for (int i = 0; i < 2; i++) m_vec.push_back(0);
}

C2DVector::C2DVector(double x, double y) {
	m_vec.push_back(x);
	m_vec.push_back(y);
}

C2DVector::~C2DVector()	{

}

C2DVector C2DVector::operator+(const C2DVector& vec) {
	C2DVector res_vec;
	res_vec.m_vec[0] = this->m_vec[0] + vec.m_vec[0];
	res_vec.m_vec[1] = this->m_vec[1] + vec.m_vec[1];
	return res_vec;
}

double C2DVector::operator*(const C2DVector& vec) {
	double DotProduct = 0;
	for (int i = 0; i < 2; i++) DotProduct += this->m_vec[i] + vec.m_vec[i];
	return DotProduct;
}

C2X2Mat::C2X2Mat() {
	for (int i = 0; i < 4; i++) m_mat.push_back(0);
}

C2X2Mat::C2X2Mat(double a11, double a12, double a21, double a22) {
	m_mat.push_back(a11);
	m_mat.push_back(a12);
	m_mat.push_back(a21);
	m_mat.push_back(a22);
}

C2X2Mat::~C2X2Mat() {

}

C2DVector C2X2Mat::operator*(const C2DVector& vec) {
	C2DVector res_vec;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			int ind_ij = 2 * i + j;
			res_vec.m_vec[i] += this->m_mat[ind_ij] * vec.m_vec[j];
		}
	}
	return res_vec;
}