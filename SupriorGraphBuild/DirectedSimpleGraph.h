#pragma once

using namespace std;
#include <list>
#include <vector>
#include <iostream>

class DirectedSimpleGraph{
public:
    bool IsAdjacent(int u, int v);
    void AddEdge(int u, int v);
    void RemoveEdge(int u, int v);
    friend static DirectedSimpleGraph* MakeEmptyGraph(int n);
    //Getters
    int GetNumVertices() const;
    int GetNumEdges() const;
    list<int> GetAdjList(int u);

private:
    int numVertices;
    int numEdges;
    vector<list<int>> AdjacencyList;

    DirectedSimpleGraph(int n);
};
