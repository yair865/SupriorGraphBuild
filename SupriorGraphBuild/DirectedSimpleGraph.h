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
    const list<vertex> GetAdjList(vertex u) const noexcept(false);
    int GetNumVertices() const;
    int GetNumEdges() const;
    void AddSingleVertex();

private:
    int m_NumVerticesPhysical;
    int m_NumVerticesLogical;
    int m_NumEdges;
    vector<list<vertex>> m_AdjacencyList;

    bool isValidVertex(vertex v) const;
    DirectedSimpleGraph(int n);
};
