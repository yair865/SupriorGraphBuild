#include "GraphUtils.h"
using namespace std;

DirectedSimpleGraph* GraphUtils::GenerateSuperiorGraph(DirectedSimpleGraph* i_GraphToCreateFrom)
{
	int numberOfVetices = i_GraphToCreateFrom->GetNumVertices();
	DirectedSimpleGraph* superiorGraphResult = DirectedSimpleGraph::MakeEmptyGraph(numberOfVetices);
	DirectedSimpleGraph* inputGraphTransposed = createTransposedDirectedGraph(i_GraphToCreateFrom);

	s_ReversedEndListOfGraph = (createEndListWithDFS(i_GraphToCreateFrom)).reverse;
	s_CurrentGraph = i_GraphToCreateFrom;
	s_VerticesColorArray.resize(numberOfVetices);
	s_Parents.resize(numberOfVetices);
	
	for (vertex u : s_VerticesColorArray)
	{
		s_VerticesColorArray[u] = eColors::WHITE;
	}

	s_CurrentGraph = inputGraphTransposed;
	
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

