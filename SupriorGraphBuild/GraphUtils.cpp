#include "GraphUtils.h"
using namespace std;

DirectedSimpleGraph* GraphUtils::GenerateCondensationGraph(DirectedSimpleGraph* i_GraphToCreateFrom)
{
	int numberOfVertices = i_GraphToCreateFrom->GetNumVertices();
	vertex currentStronglyConnectedComponent = 1;
	vector<vertex> verticesComponent(numberOfVertices + 1);
	vector<eColors> verticesColor;
	DirectedSimpleGraph* condensationGraphResult = DirectedSimpleGraph::MakeEmptyGraph(EMPTY);
	stack<vertex>* reversedEndList = EndListDFS(i_GraphToCreateFrom);
	DirectedSimpleGraph* transposedGraph = CreateTransposedGraph(i_GraphToCreateFrom);
	
	verticesColor.resize(numberOfVertices + 1, eColors::WHITE);
	
	// Main-loop
	while(!(reversedEndList->empty()))
	{
		vertex u = reversedEndList->top();
		reversedEndList->pop();

		if (verticesColor[u] == eColors::WHITE)
		{
			condensationGraphResult->AddSingleVertex();
			verticesComponent[u] = currentStronglyConnectedComponent;
			visitSCCDFS(u, transposedGraph, verticesColor, currentStronglyConnectedComponent, verticesComponent, *condensationGraphResult);
			currentStronglyConnectedComponent++;
		}
	}

	return condensationGraphResult;
}

void GraphUtils::visitSCCDFS(vertex u, DirectedSimpleGraph* i_TransposedGraph, vector<eColors>& i_VerticesColor, vertex i_CurrentComponent, 
								vector<vertex>& i_VerticesComponentsBelonging, DirectedSimpleGraph& io_SuperiorGraphInBuild)
{
	list<vertex> inputVertexAdjacentList = i_TransposedGraph->GetAdjList(u);
	list<vertex> currentSCCAdjacentList;
	vertex u_Component, v_Component;

	i_VerticesColor[u] = eColors::GRAY;

	for (vertex v : inputVertexAdjacentList)
	{
		if (i_VerticesColor[v] == eColors::WHITE)
		{
			i_VerticesComponentsBelonging[v] = i_CurrentComponent;
			visitSCCDFS(v, i_TransposedGraph, i_VerticesColor, i_CurrentComponent, i_VerticesComponentsBelonging, io_SuperiorGraphInBuild);
		}
		else if ((i_VerticesColor[v] == eColors::BLACK) && (i_VerticesComponentsBelonging[u] != i_VerticesComponentsBelonging[v]))
		{
			currentSCCAdjacentList = io_SuperiorGraphInBuild.GetAdjList(i_CurrentComponent);
			u_Component = i_VerticesComponentsBelonging[u];
			v_Component = i_VerticesComponentsBelonging[v];

			if ((currentSCCAdjacentList.size() == 0) || (currentSCCAdjacentList.back() != u_Component))
			{
				io_SuperiorGraphInBuild.AddEdge(v_Component, u_Component);
			}
		}
	}

	i_VerticesColor[u] = eColors::BLACK;
}

stack<vertex>* GraphUtils::EndListDFS(DirectedSimpleGraph* i_GraphToActivateOn)
{
	vector<eColors> verticesColor;
	int numberOfVertices = i_GraphToActivateOn->GetNumVertices();
	stack<vertex>* endListResult = new stack<vertex>();

	// Initializing
	verticesColor.resize(numberOfVertices + 1, eColors::WHITE);

	// Main-loop
	for(vertex u = 1; u <= numberOfVertices; u++)
	{
		if (verticesColor[u] == eColors::WHITE)
		{
			visitEndListDFS(u, i_GraphToActivateOn, verticesColor, *endListResult);
		}
	}

	return endListResult;
}

void GraphUtils::visitEndListDFS(vertex u, DirectedSimpleGraph* i_GraphToActivateOn, vector<eColors>& i_VerticesColor, stack<vertex>& i_ResultEndList)
{
	list<vertex> inputVertexAdjacentList = i_GraphToActivateOn->GetAdjList(u);

	i_VerticesColor[u] = eColors::GRAY;

	for (vertex v : inputVertexAdjacentList)
	{
		if (i_VerticesColor[v] == eColors::WHITE)
		{
			visitEndListDFS(v, i_GraphToActivateOn, i_VerticesColor, i_ResultEndList);
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

	for (vertex u = 1 ; u <= numberOfVertices ; u++)
	{
		currentVertexNeighbors = i_GraphToTranspose->GetAdjList(u);

		if (currentVertexNeighbors.size() != 0)
		{
			for (vertex v : currentVertexNeighbors)
			{
				trasposedGraph->AddEdge(v, u);
			}
		}
	}

	return trasposedGraph;
}

