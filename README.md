# quickest-traverse-gotham

Bogazici University

Computer Engineering Department

Fall 2020

CMPE 250

Project 3

Altay Acar

***

This code finds the quickest way to traverse every road given in Gotham City to assemble shattered Bat Signal for Commissioner Gordon. This quickest route for traversing every road is achieved by using Hierholzer's algorithm.

Rules:
- ID of the crossing points start from 0 and ends at V − 1.
- It is possible that there is no path that traverses all of the edges exactly once. In this case, you should print “no path” and do not run the Hierholzer’s algorithm at all.
- All roads are one-way, i.e. directed.

Testing:
- The code will be tested using the below command to the CLI:
  > g++ *.cpp *.h -std=c++11 -o project3
  > ./project3 inputFile outputFile

Input:
- The map of Gotham is provided in given format:
  - The first line contains an integer V that denotes the total number of crossing points of roads (vertices).
  - The next V lines contains an integer (Vertex ID), another integer (D+) which is the out- degree of this vertex, and D+ integers that represent the Vertex IDs to which there is an edge from this vertex.
  - The last line contains an integer denoting the ID of the starting vertex.

Output:
- The final route must contain all of the roads exactly once. So, a sequence of vertex IDs separated by space will be printed to the output file. Note that the edge inclusion order and vertex order in the output is different since tours are merged to produce the final circuit.
