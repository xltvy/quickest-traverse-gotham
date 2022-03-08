#include <iostream>
#include <fstream>
#include "Vertex.h"
#include <list>

using namespace std;

//Finds and returns the ID number of given parameter vertex's closest adjacent vertex
int getFirstNonUsedEdge(Vertex* vertex) {
    int res;
    if (vertex->adjacencyList.size() != 0) {
        res = vertex->adjacencyList.front();
        //In order to mark that edge to the front vertex used, it is removed from the adcacencyList
        vertex->adjacencyList.pop_front();
    }
    return res;
}

//Finds the next vertex in the circuit that has unused edge(s)
Vertex* findNextVertex(list<int> circuit, vector<Vertex*> gotham) {
    for (auto curr: circuit) {
        if (gotham.at(curr)->hasNonUsedEdge) {
            //Returns the first vertex in the circuit that has unused edge(s)
            return gotham.at(curr);
        }
    }
    //If every edge of every vertex is used, returns NULL
    return NULL;
}

//Merges the produced new tour to the current circuit in the given position
list<int> merge(list<int> circuit, vector<int> tour, int merging_point) {
    list<int>::iterator itr;
    itr = circuit.begin();
    int pos = 1;    //Starting position
    //Finds the position of the merging operation according the merging_point parameter, which is the ID of a vertex
    for (auto curr: circuit) {
        if (curr == merging_point) {
            break;
        }
        pos++;
    }
    advance(itr, pos);
    circuit.insert(itr, tour.begin(), tour.end());  //Merges the circuit and the new tour
    return circuit;
}

int main(int argc, char const *argv[]) {

    ifstream read(argv[1]); //Reads the input file
    ofstream write(argv[2]);    //Writes to the output file

    ios::sync_with_stdio(false);    //For time management of io operations

    int totalVer;   //Total number of vertexes
    read >> totalVer;
    vector<Vertex*> gotham; //Graph consisting the vertexes
    list<int> circuit;  //Circuit that traverses every edge for once
    int tot_edges = 0;  //Total number of edges
    //Vertexes created according to the totalVer
    for (int i=0; i<totalVer; i++) {
        Vertex* vert = new Vertex(i);
        gotham.push_back(vert);
    }
    //Edges created
    for (auto &vertex: gotham) {
        int id, outDegree;
        read >> id; //ID of the vertex that the edge emerges from
        read >> outDegree;  //Total number of edges emerging from the vertex
        vertex->outDegree = outDegree;
        vertex->hasNonUsedEdge = true;  //Every edge is unused when newly created
        for (int i=0; i<outDegree; i++) {
            int to;
            read >> to;
            vertex->addEdge(*gotham.at(to));
            tot_edges++;
        }
    }
    //Checks if the graph is eulerian
    for (auto &vertex: gotham) {
        //If there is a vertex that has unmatching number of outDegree and inDegree, the graph is not eulerain
        if (!(vertex->inDegree==vertex->outDegree)) {
            write << "no path"; //Output for the non-eulerian graphs
            goto termination_point; //Program jumps to the termination point
        }
    }
    {
        int start;  //ID of the starting vertex
        read >> start;

        vector<int> tour;   //Represents one cycle starts from and ends at the starting vertex, and contains the IDs of every vertex visited during tour
        Vertex* temp = gotham.at(start);
        circuit.push_back(start);
        //Runs until every edge is used
        while (circuit.size() <= tot_edges) {
            tour.clear();   //Clears the tour, when starting to a new one
            while (temp->hasNonUsedEdge) {
                //Finds the newxt non-used edge and adds the vertex that edge goes to to the tour
                int next = getFirstNonUsedEdge(temp);
                //Checks if the current vertex has unused edges left
                if (temp->adjacencyList.size()==0) {
                    //If not (adjacency lis is empty), marks it
                    temp->hasNonUsedEdge = false;
                }
                temp = gotham.at(next); //Next vertex
                tour.push_back(next);   //Next vertex is added to the tour
            }
            circuit = merge(circuit, tour, temp->ID);   //Tour is added to the circuit
            temp = findNextVertex(circuit, gotham); //Next vertex that has unused edge is found
        }
    }
    //Writes the circuit to the output file in given format
    for (auto road: circuit) {
        write << road << " ";
    }

termination_point:  //Termination point of the program for non-eulerian graphs
    read.close();   //Closes the ifstream
    write.close();  //Closes the ofstream
    //Deletes every Vertex object that create with "new"
    for (auto &vertex: gotham) {
        delete vertex;
    }

    return 0;
}
