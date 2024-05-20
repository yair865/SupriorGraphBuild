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
		list<vertex> neighbors = m_AdjacencyList[u];

		verticesAdjacent = find(neighbors.begin(), neighbors.end(), v) != neighbors.end();
	}
	else
	{
		throw invalid_argument("One or both vertices doesn't exists in graph!");
	}

	return verticesAdjacent;
}

void DirectedSimpleGraph::AddEdge(vertex u, vertex v) noexcept(false)
{
	if (isValidVertex(u) && isValidVertex(v) && (u != v))
	{
		if (!IsAdjacent(u, v)) 
		{
			m_AdjacencyList[u].push_back(v);
			m_NumEdges++;
		}
	}
	else
	{
		throw invalid_argument("Invalid vertices!");
	}
}

void DirectedSimpleGraph::RemoveEdge(vertex u, vertex v) noexcept(false)
{
	if (isValidVertex(u) && isValidVertex(v))
	{
		list<vertex> neighbors = m_AdjacencyList[u];
		auto it = find(neighbors.begin(), neighbors.end(), v);

		if (it != neighbors.end()) 
		{
			neighbors.erase(it);
			m_NumEdges--;
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
		vertexAdjacenyList = m_AdjacencyList[u];
	}
	else
	{
		throw invalid_argument("Invalid vertex!");
	}

	return vertexAdjacenyList;
}

int DirectedSimpleGraph::GetNumVertices() const 
{
	return m_NumVerticesLogical;
}

int DirectedSimpleGraph::GetNumEdges() const 
{
	return m_NumEdges;
}

bool DirectedSimpleGraph::isValidVertex(vertex v)
{
	return (1 <= v && v <= m_NumVerticesLogical);
}

void DirectedSimpleGraph::AddSingleVertex()
{
	m_AdjacencyList.push_back(list<vertex>());
	m_NumVerticesPhysical++;
	m_NumVerticesLogical++;
}

DirectedSimpleGraph::DirectedSimpleGraph(int n) : m_NumVerticesLogical(n), m_NumVerticesPhysical(n + 1), m_NumEdges(0), m_AdjacencyList(n + 1) {}