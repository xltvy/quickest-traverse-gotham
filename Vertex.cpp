#include "Vertex.h"

//Constructor
Vertex::Vertex(int _ID) {
    this->ID = _ID;
    this->inDegree = 0;
}

//Copy constructor
Vertex::Vertex(const Vertex &vertex) {
    this->ID = vertex.ID;
    this->inDegree = vertex.inDegree;
    this->outDegree = vertex.outDegree;
    this->adjacencyList = vertex.adjacencyList;
    this->hasNonUsedEdge = vertex.hasNonUsedEdge;
}

//Assignment operator
Vertex& Vertex::operator=(const Vertex &vertex) {
    if (this == &vertex) {
        return *this;
    }
    this->ID = vertex.ID;
    this->inDegree = vertex.inDegree;
    this->outDegree = vertex.outDegree;
    this->adjacencyList = vertex.adjacencyList;
    this->hasNonUsedEdge = vertex.hasNonUsedEdge;
}


