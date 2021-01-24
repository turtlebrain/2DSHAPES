#include "Geometry.h"
#include <vector>
#include <assert.h>
#include "Tensor.h"
using namespace std;

Geometry::Geometry() {

}

Geometry::Geometry(vector<C2DVector> vertices) {
	int i = 0;
	m_vertices = vertices;
	for (i = 0; i < vertices.size(); i++) {
		if (i < vertices.size() - 1) {
			C2DVector dirvec(vertices[i + 1].m_vec[0] - vertices[i].m_vec[0],
				vertices[i + 1].m_vec[1] - vertices[i].m_vec[1]);
			m_edges.push_back(dirvec);
		}
		else {
			C2DVector dirvec(vertices[0].m_vec[0] - vertices[i].m_vec[0],
				vertices[0].m_vec[1] - vertices[i].m_vec[1]);
			m_edges.push_back(dirvec);
		}
	}
	if (i == 1) IsPoint = true;
}

Geometry::~Geometry() {

}

Geometry Geometry::Rotate(double angle) {
	vector<C2DVector> RotatedVertices;
	C2X2Mat RotationMatrix(cos(angle), -sin(angle), sin(angle), cos(angle));
	for (int i = 0; i < m_vertices.size(); i++) {
		RotatedVertices.push_back(RotationMatrix * m_vertices[i]);
	}
	Geometry RotatedGeometry(RotatedVertices);
	return RotatedGeometry;
}

bool Geometry::IsInside(Geometry geom) {
	
	// Check if point is within domain first
	double min_x = 1e10;	double max_x = -1e10;
	double min_y = 1e10;	double max_y = -1e10;
	for (int i = 0; i < this->m_vertices.size(); i++) {
		if (this->m_vertices[i].m_vec[0] < min_x) min_x = m_vertices[i].m_vec[0];
		if (this->m_vertices[i].m_vec[0] > max_x) max_x = m_vertices[i].m_vec[0];
		if (this->m_vertices[i].m_vec[1] < min_y) min_y = m_vertices[i].m_vec[1];
		if (this->m_vertices[i].m_vec[1] > max_y) max_y = m_vertices[i].m_vec[1];
	}
	for (int i = 0; i < geom.m_vertices.size(); i++) {
		if (geom.m_vertices[i].m_vec[0] < min_x || geom.m_vertices[i].m_vec[0] > max_x
			|| geom.m_vertices[i].m_vec[1] < min_y || geom.m_vertices[i].m_vec[1] > max_y) {
			return false;
		}
	}

	/*	intercept[0] = # of lines intersected above point
	intercept[1] = # of lines intersected below point
	intercept[2] = # of lines intersected to the right of point
	intercept[3] = # of lines intersected to the left of point
	*/
	for (int i = 0; i < geom.m_vertices.size(); i++) {
		int intercept[4]; 
	}
	return true;
}