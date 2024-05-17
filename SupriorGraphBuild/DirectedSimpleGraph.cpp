#include "DirectedSimpleGraph.h"

using namespace std;
static DirectedSimpleGraph* MakeEmptyGraph(int n) { return (new DirectedSimpleGraph(n));}

DirectedSimpleGraph::DirectedSimpleGraph(int n) :numVertices(n), numEdges(0), AdjacencyList(n) {}

bool DirectedSimpleGraph::IsAdjacent(int u, int v)
{
	if (u >= 1 && u <= numVertices && v >= 1 && v <= numVertices) {
		const std::list<int>& neighbors = AdjacencyList[u - 1];
		return std::find(neighbors.begin(), neighbors.end(), v) != neighbors.end();
	}
	return false;
}

void DirectedSimpleGraph::AddEdge(int u, int v)
{
	if (u >= 1 && u <= numVertices && v >= 1 && v <= numVertices && u != v) {
		if (!IsAdjacent(u, v)) {
			AdjacencyList[u - 1].push_back(v);
			numEdges++;
		}
	}
}

void DirectedSimpleGraph::RemoveEdge(int u, int v)
{
	if (u >= 1 && u <= numVertices && v >= 1 && v <= numVertices) {
		auto& neighbors = AdjacencyList[u - 1];
		auto it = std::find(neighbors.begin(), neighbors.end(), v);
		if (it != neighbors.end()) {
			neighbors.erase(it);
			numEdges--;
		}
	}
}

int DirectedSimpleGraph::GetNumVertices() const {return numVertices;}

int DirectedSimpleGraph::GetNumEdges() const {return numEdges;}

list<int> DirectedSimpleGraph::GetAdjList(int u)
{
	//try
	//{
	//	if (u >= 1 && u <= numVertices)
	//		return AdjacencyList[u - 1];
	//	throw(u);
	//}
	//catch (int u)
	//{
	//	cout << "Vertex doesnt exist!";
	//	return std::list<int>();
	//}
	 
		if (u >= 1 && u <= numVertices)
			return AdjacencyList[u - 1];
		else
		{
			cout << "Vertex doesnt exist!";
		    return std::list<int>();
		}
}
