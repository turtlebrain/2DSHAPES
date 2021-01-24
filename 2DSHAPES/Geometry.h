#pragma once
#include <vector>
#include <assert.h>
#include "Tensor.h"
using namespace std;

class Geometry
{
public:
	Geometry();
	Geometry(vector<C2DVector> vertices);
	~Geometry();

	Geometry Rotate(double angle);
	bool IsInside(Geometry geom);
	void CollsionDetection();

public:
	vector<C2DVector> m_vertices;
	vector<C2DVector> m_edges;
	bool IsPoint;
};

