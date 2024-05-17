#include "GraphUtils.h"
using namespace std;

DirectedSimpleGraph* GraphUtils::GenerateSuperiorGraph(DirectedSimpleGraph* i_GraphToCreateFrom)
{
	int numberOfVetices = i_GraphToCreateFrom->GetNumVertices();
	DirectedSimpleGraph* superiorGraphResult = DirectedSimpleGraph::MakeEmptyGraph(numberOfVetices);
	DirectedSimpleGraph* inputGraphTransposed = CreateTransposedGraph(i_GraphToCreateFrom);

	s_ReversedEndListOfGraph = (CreateEndListWithDFS(i_GraphToCreateFrom)).reverse;
	s_CurrentGraph = i_GraphToCreateFrom;
	s_VerticesColorArray.resize(numberOfVetices);
	s_Parents.resize(numberOfVetices);
	
	for (vertex u : s_VerticesColorArray)
	{
		s_VerticesColorArray[u] = eColors::WHITE;
	}

	s_CurrentGraph = std::move(inputGraphTransposed);
	
	for (vertex u : s_ReversedEndListOfGraph)
	{
		if (s_VerticesColorArray[u] == eColors::WHITE)
		{
			s_CurrentRoot = u;
			visitDFS(u);
		}
	}
}

void GraphUtils::visitDFS(vertex u)
{
	s_VerticesColorArray[u] = eColors::GRAY;
	list<vertex> inputVertexAdjacentList = s_CurrentGraph->GetAdjList(u);

	for (vertex v : inputVertexAdjacentList)
	{
		if (!(s_CurrentGraph->GetEdge(u, v).IsVisited()))
		{
			if (s_VerticesColorArray[v] == eColors::WHITE)
			{
				s_CurrentGraph->GetEdge(u, v).SetVisitStatus(true);
				s_Parents[v] = u;
				visitDFS(v);
			}
		}
	}

	s_VerticesColorArray[u] = eColors::BLACK;
}

DirectedSimpleGraph* GraphUtils::CreateTransposedGraph(DirectedSimpleGraph* i_GraphToTranspose)
{
	int numberOfVertices = i_GraphToTranspose->GetNumVertices();
	vector<list<vertex>> graphAdjacencyList = std::move(i_GraphToTranspose->GetAdjacencyVector());
	DirectedSimpleGraph* trasposedGraph = DirectedSimpleGraph::MakeEmptyGraph(numberOfVertices);
	list<vertex> currentVertexNeighbors;

	for (vertex v = 0 ; v < numberOfVertices ; v++)
	{
		currentVertexNeighbors = i_GraphToTranspose->GetAdjList(v);

		if (currentVertexNeighbors.size() != 0)
		{
			for (vertex u : currentVertexNeighbors)
			{
				trasposedGraph->AddEdge(v, u);
			}
		}
	}

	return trasposedGraph;
}