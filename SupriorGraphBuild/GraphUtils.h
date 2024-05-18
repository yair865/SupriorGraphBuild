#pragma once
#include "DirectedSimpleGraph.h"
#include <stack>

#define EMPTY 0

class GraphUtils
{
public:
	static DirectedSimpleGraph* GenerateSuperiorGraph(DirectedSimpleGraph* i_GraphToCreateFrom);
	static DirectedSimpleGraph* CreateTransposedGraph(DirectedSimpleGraph* i_GraphToTranspose);
	static stack<vertex>* DFSWithEndListAndParents(DirectedSimpleGraph* i_GraphToActivateDFSOn, vector<vertex>& o_VerticesParents, int& o_NumberOfSCC);
	static vector<vertex>* CreateSCCWithDFS(DirectedSimpleGraph* i_GraphToActivateDFSOn);

private:
	const enum eColors {WHITE, GRAY, BLACK};
	static void visitDFSEndListParents(vertex u, vector<eColors>& i_VerticesColor, stack<vertex>& i_ResultEndList, vector<vertex>& o_VerticesRoot, vertex i_CurrentRoot);
	static void visitSCCDFS(vertex u, vector<eColors>& i_VerticesColor, vector<vertex>& i_VerticesRoot, DirectedSimpleGraph& io_SuperiorGraphInBuild);
	static DirectedSimpleGraph* s_CurrentGraph;
	static vector<vertex> s_ReversedEndListOfGraph;
	static vector<eColors> s_VerticesColorArray;
	static vertex s_CurrentRoot;
	static vector<vertex> s_Parents;
	static int s_SuperiorGraphNumberOfVertices;
	static int s_SuperiorGraphNumberOfEdges;
};