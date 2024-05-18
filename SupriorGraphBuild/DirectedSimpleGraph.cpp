#include "DirectedSimpleGraph.h"
using namespace std;

DirectedSimpleGraph* DirectedSimpleGraph::MakeEmptyGraph(int n)
{ 
	return (new DirectedSimpleGraph(n));
}

bool DirectedSimpleGraph::IsAdjacent(vertex u, vertex v) noexcept(false)
{
	bool verticesAdjacent = false;

	if (isValidVertex(u) && isValidVertex(v))
	{
		list<vertex> neighbors = AdjacencyList[u - 1];

		verticesAdjacent = find(neighbors.begin(), neighbors.end(), v) != neighbors.end();
	}
	else
	{
		throw new invalid_argument("One or both vertices doesn't exists in graph!");
	}

	return verticesAdjacent;
}

void DirectedSimpleGraph::AddEdge(vertex u, vertex v) noexcept(false)
{
	if (isValidVertex(u) && isValidVertex(v) && (u != v))
	{
		if (!IsAdjacent(u, v)) 
		{
			AdjacencyList[u - 1].push_back(v);
			numEdges++;
		}
	}
	else
	{
		throw new invalid_argument("Invalid vertices!");
	}
}

void DirectedSimpleGraph::RemoveEdge(vertex u, vertex v) noexcept(false)
{
	if (isValidVertex(u) && isValidVertex(v))
	{
		list<vertex> neighbors = AdjacencyList[u - 1];
		auto it = find(neighbors.begin(), neighbors.end(), v);

		if (it != neighbors.end()) 
		{
			neighbors.erase(it);
			numEdges--;
		}
	}
	else
	{
		throw new invalid_argument("One or both vertices doesn't exists in graph!");
	}
}
// Consider const here
list<int> DirectedSimpleGraph::GetAdjList(vertex u) noexcept(false)
{
	list<vertex> vertexAdjacenyList;

	if (isValidVertex(u))
	{
		vertexAdjacenyList = AdjacencyList[u - 1];
	}
	else
	{
		throw new invalid_argument("Invalid vertex!");
	}

	return vertexAdjacenyList;
}

int DirectedSimpleGraph::GetNumVertices() const 
{
	return numVertices;
}

int DirectedSimpleGraph::GetNumEdges() const 
{
	return numEdges;
}

bool DirectedSimpleGraph::isValidVertex(vertex v)
{
	return (1 <= v && v <= numVertices);
}

void DirectedSimpleGraph::AddSingleVertex()
{
	AdjacencyList.push_back(list<vertex>());
	numVertices++;
}

DirectedSimpleGraph::DirectedSimpleGraph(int n) : numVertices(n), numEdges(0), AdjacencyList(n) {}