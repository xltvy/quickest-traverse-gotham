#include <string>
#include <vector>
#include <deque>

using namespace std;

#ifndef CMPE250_PROJECT_3_VERTEX_H
#define CMPE250_PROJECT_3_VERTEX_H


class Vertex {

public:

    int ID; //ID number of the vertex
    int inDegree;   //Number of edges leading to this vertex
    int outDegree;  //Number of edges emerging from this vertex
    deque<int> adjacencyList;   //Vertexes that are adjacent to this vertex
    bool hasNonUsedEdge;    //Checks if this vertex has a non-used edge or not

    Vertex(int _ID);    //Constructor
    Vertex(const Vertex& vertex);   //Copy constructor
    Vertex& operator=(const Vertex& vertex);    //Assignment operator

    //Adds an edge from this vertex to the given vertex v as the parameter
    void addEdge(Vertex& v) {
        this->adjacencyList.push_back(v.ID);
        v.inDegree++;
    }

};

#endif
