#pragma once
#include "DirectedSimpleGraph.h"
#include <stack>

#define EMPTY 0

class GraphUtils
{
public:
	static DirectedSimpleGraph* GenerateCondensationGraph(DirectedSimpleGraph* i_GraphToCreateFrom);
	static DirectedSimpleGraph* CreateTransposedGraph(DirectedSimpleGraph* i_GraphToTranspose);
	static stack<vertex>* EndListDFS(DirectedSimpleGraph* i_GraphToActivateOn);

private:
	const enum eColors { WHITE, GRAY, BLACK };

	static void visitSCCDFS(vertex u, DirectedSimpleGraph* i_TransposedGraph, vector<eColors>& i_VerticesColor, vertex i_CurrentComponent, vector<vertex>& i_VerticesComponentsBelonging, DirectedSimpleGraph& io_SuperiorGraphInBuild);
	static void visitEndListDFS(vertex u, DirectedSimpleGraph* i_GraphToActivateOn, vector<eColors>& i_VerticesColor, stack<vertex>& i_ResultEndList);
};