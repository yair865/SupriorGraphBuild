#pragma once

using namespace std;
#include <list>
#include <vector>
#include <iostream>
#include "Edge.h"

class DirectedSimpleGraph
{
public:
    bool IsAdjacent(vertex u, vertex v);
    void AddEdge(vertex u, vertex v);
    void RemoveEdge(vertex u, vertex v);
    static DirectedSimpleGraph* MakeEmptyGraph(int n);
    //Getters
    int GetNumVertices() const;
    int GetNumEdges() const;
    vector<list<vertex>> GetAdjacencyVector() const;
    Edge GetEdge(vertex u, vertex v);
    list<vertex> GetAdjList(vertex u);

private:
    int numVertices;
    int numEdges;
    vector<list<vertex>> AdjacencyList;

    DirectedSimpleGraph(int n);
};
