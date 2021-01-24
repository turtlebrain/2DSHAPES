// 2DSHAPES.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tensor.h"
#include "Geometry.h"
#include <vector>
#include <stdio.h> 
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

#define PI 3.14159265359


int main()
{
    //For testing purposes
    srand(time(NULL));      // initialize random seed
    vector<C2DVector> Coordinates;
    for (int i = 0; i < 3; i++) {
        C2DVector point(rand() % 10, rand() % 10);
        Coordinates.push_back(point);
    }
    Geometry triangle(Coordinates);
    
    cout << "Vertex 1 is (" << triangle.m_vertices[0].m_vec[0] << "," << triangle.m_vertices[0].m_vec[1] << ")" << endl;
    cout << "Vertex 2 is (" << triangle.m_vertices[1].m_vec[0] << "," << triangle.m_vertices[1].m_vec[1] << ")" << endl;
    cout << "Vertex 3 is (" << triangle.m_vertices[2].m_vec[0] << "," << triangle.m_vertices[2].m_vec[1] << ")" << endl;
    cout << "Edge 1 is (" << triangle.m_edges[0].m_vec[0] << "," << triangle.m_edges[0].m_vec[1] << ")" << endl;
    cout << "Edge 2 is (" << triangle.m_edges[1].m_vec[0] << "," << triangle.m_edges[1].m_vec[1] << ")" << endl;
    cout << "Edge 3 is (" << triangle.m_edges[2].m_vec[0] << "," << triangle.m_edges[2].m_vec[1] << ")" << endl;
    
    C2DVector ResCoord;
    ResCoord = Coordinates[0] + Coordinates[1];
    cout << "Coordinates of Point 1 is (" << Coordinates[0].m_vec[0] << "," << Coordinates[0].m_vec[1] << ")" << endl;
    cout << "Coordinates of Point 2 is (" << Coordinates[1].m_vec[0] << "," << Coordinates[1].m_vec[1] << ")" << endl;
    cout << "Coordinates of P1 + P2 is (" << ResCoord.m_vec[0] << "," << ResCoord.m_vec[1] << ")" << endl;

    Geometry RotatedTriangle = triangle.Rotate(35*PI/180);   //35deg rotation
    cout << "Coordinates of RP 1 is (" << RotatedTriangle.m_vertices[0].m_vec[0] << "," << RotatedTriangle.m_vertices[0].m_vec[1] << ")" << endl;
    cout << "Coordinates of RP 2 is (" << RotatedTriangle.m_vertices[1].m_vec[0] << "," << RotatedTriangle.m_vertices[1].m_vec[1] << ")" << endl;
    cout << "Coordinates of RP 3 is (" << RotatedTriangle.m_vertices[2].m_vec[0] << "," << RotatedTriangle.m_vertices[2].m_vec[1] << ")" << endl;
}


