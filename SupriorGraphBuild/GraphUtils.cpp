#include "GraphUtils.h"
using namespace std;

int GraphUtils::s_SuperiorGraphNumberOfVertices = 0;
int GraphUtils::s_SuperiorGraphNumberOfEdges = 0;

DirectedSimpleGraph* GraphUtils::GenerateSuperiorGraph(DirectedSimpleGraph* i_GraphToCreateFrom)
{
	int numberOfVertices = i_GraphToCreateFrom->GetNumVertices();
	int numberOfSCC = 0;
	vector<vertex> verticesRoot(numberOfVertices);
	vector<eColors> verticesColor;
	stack<vertex>* reversedEndList = DFSWithEndListAndParents(i_GraphToCreateFrom, verticesRoot, numberOfSCC);
	DirectedSimpleGraph* superiorGraphResult = DirectedSimpleGraph::MakeEmptyGraph(numberOfSCC);
	DirectedSimpleGraph* inputGraphTransposed = CreateTransposedGraph(i_GraphToCreateFrom);
	
	verticesColor.resize(numberOfVertices, eColors::WHITE);
	
	// Main-loop
	while(!(reversedEndList->empty()))
	{
		vertex u = reversedEndList->top();
		reversedEndList->pop();

		if (s_VerticesColorArray[u] == eColors::WHITE)
		{
			visitSCCDFS(u, verticesColor, verticesRoot, *superiorGraphResult);
		}
	}
}

void GraphUtils::visitSCCDFS(vertex u, vector<eColors>& i_VerticesColor, vector<vertex>& i_VerticesRoot, DirectedSimpleGraph& io_SuperiorGraphInBuild)
{
	i_VerticesColor[u] = eColors::GRAY;
	list<vertex> inputVertexAdjacentList = s_CurrentGraph->GetAdjList(u);
	list<vertex> currentSCCAdjacentList;

	for (vertex v : inputVertexAdjacentList)
	{
		if (i_VerticesColor[v] == eColors::WHITE)
		{
			visitSCCDFS(v, i_VerticesColor, i_VerticesRoot, io_SuperiorGraphInBuild);
		}
		else if (i_VerticesColor[v] == eColors::BLACK)
		{
			if (i_VerticesRoot[u] != i_VerticesRoot[v])
			{
				if ()
				{

				}
			}
		}
	}

	i_VerticesColor[u] = eColors::BLACK;
	i_ResultEndList.push(u);
}

stack<vertex>* GraphUtils::DFSWithEndListAndParents(DirectedSimpleGraph* i_GraphToActivateDFSOn, vector<vertex>& o_VerticesRoot, int& o_NumberOfSCC)
{
	vector<eColors> verticesColor;
	int numberOfVertices = i_GraphToActivateDFSOn->GetNumVertices();
	stack<vertex>* endListResult = new stack<vertex>();

	// Initializing
	verticesColor.resize(numberOfVertices, eColors::WHITE);

	// Main-loop
	for(vertex u = 0; u < numberOfVertices; u++)
	{
		if (verticesColor[u] == eColors::WHITE)
		{
			o_NumberOfSCC++;
			visitDFSEndListParents(u, verticesColor, *endListResult, o_VerticesRoot, u);
		}
	}

	return endListResult;
}

void GraphUtils::visitDFSEndListParents(vertex u, vector<eColors>& i_VerticesColor, stack<vertex>& i_ResultEndList, vector<vertex>& o_VerticesRoot, vertex i_CurrentRoot)
{
	list<vertex> inputVertexAdjacentList = s_CurrentGraph->GetAdjList(u);

	i_VerticesColor[u] = eColors::GRAY;
	o_VerticesRoot[u] = i_CurrentRoot;

	for (vertex v : inputVertexAdjacentList)
	{
		if (i_VerticesColor[v] == eColors::WHITE)
		{
			visitDFSEndListParents(v, i_VerticesColor, i_ResultEndList, o_VerticesRoot, i_CurrentRoot);
		}
	}

	i_VerticesColor[u] = eColors::BLACK;
	i_ResultEndList.push(u);
}

DirectedSimpleGraph* GraphUtils::CreateTransposedGraph(DirectedSimpleGraph* i_GraphToTranspose)
{
	int numberOfVertices = i_GraphToTranspose->GetNumVertices();
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

