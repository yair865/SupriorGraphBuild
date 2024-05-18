#pragma once
#include <list>
#include <vector>
#include <iostream>
using namespace std;

typedef int vertex;

class DirectedSimpleGraph
{
public:
    static DirectedSimpleGraph* MakeEmptyGraph(int n);
    bool IsAdjacent(vertex u, vertex v) noexcept(false);
    void AddEdge(vertex u, vertex v) noexcept(false);
    void RemoveEdge(vertex u, vertex v) noexcept(false);
    list<vertex> GetAdjList(vertex u) noexcept(false);
    int GetNumVertices() const;
    int GetNumEdges() const;
    void AddSingleVertex();

private:
    int numVertices;
    int numEdges;
    vector<list<vertex>> AdjacencyList;

    bool isValidVertex(vertex v);
    DirectedSimpleGraph(int n);
};
