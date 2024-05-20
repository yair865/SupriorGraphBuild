#include "DirectedSimpleGraph.h"
using namespace std;

// Create an empty graph with n vertices
DirectedSimpleGraph* DirectedSimpleGraph::MakeEmptyGraph(int n)
{ 
	return (new DirectedSimpleGraph(n));
}

// Check if there is an edge from vertex u to vertex v
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
		throw invalid_argument("One or both vertices doesn't exists in the graph!");
	}

	return verticesAdjacent;
}

// Add an edge from vertex u to vertex v
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
		if (u == v)
		{
			throw invalid_argument("Can't add a loop edge!");
		}
		else
		{
			throw invalid_argument("One or both vertices doesn't exists in the graph");
		}
	}

}

// Remove the edge from vertex u to vertex v
void DirectedSimpleGraph::RemoveEdge(vertex u, vertex v) noexcept(false)
{
	if (isValidVertex(u) && isValidVertex(v))
	{
		list<vertex> neighbors = m_AdjacencyList[u];
		auto listIterator = find(neighbors.begin(), neighbors.end(), v);

		if (listIterator != neighbors.end())
		{
			neighbors.erase(listIterator);
			m_NumEdges--;
		}
	}
	else
	{
		throw invalid_argument("One or both vertices doesn't exists in the graph!");
	}
}

// Get the adjacency list of vertex u
const list<int> DirectedSimpleGraph::GetAdjList(vertex u) const noexcept(false)
{
	list<vertex> vertexAdjacenyList;

	if (isValidVertex(u))
	{
		vertexAdjacenyList = m_AdjacencyList[u];
	}
	else
	{
		throw invalid_argument("This vertex doesn't exists in the graph!");
	}

	return vertexAdjacenyList;
}

// Get the number of vertices in the graph
int DirectedSimpleGraph::GetNumVertices() const 
{
	return m_NumVerticesLogical;
}

// Get the number of edges in the graph
int DirectedSimpleGraph::GetNumEdges() const 
{
	return m_NumEdges;
}

// Check if vertex v is valid (exists in the graph)
bool DirectedSimpleGraph::isValidVertex(vertex v) const
{
	return (1 <= v && v <= m_NumVerticesLogical);
}

// Add a single new vertex to the graph
void DirectedSimpleGraph::AddSingleVertex()
{
	m_AdjacencyList.push_back(list<vertex>());
	m_NumVerticesPhysical++;
	m_NumVerticesLogical++;
}

// Constructor to initialize a graph with n vertices
DirectedSimpleGraph::DirectedSimpleGraph(int n) : m_NumVerticesLogical(n), m_NumVerticesPhysical(n + 1), m_NumEdges(0), m_AdjacencyList(n + 1) {}