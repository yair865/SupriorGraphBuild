#pragma once
#include "DirectedSimpleGraph.h"

class GraphUtils
{
public:
	static DirectedSimpleGraph* GenerateSuperiorGraph(DirectedSimpleGraph* i_GraphToCreateFrom);
	static DirectedSimpleGraph* CreateTransposedGraph(DirectedSimpleGraph* i_GraphToTranspose);

private:
	const enum eColors {WHITE, GRAY, BLACK};
	static void visitDFS(vertex u);
	static DirectedSimpleGraph* s_CurrentGraph;
	static vector<vertex> s_ReversedEndListOfGraph;
	static vector<eColors> s_VerticesColorArray;
	static vertex s_CurrentRoot;
	static vector<vertex> s_Parents;
};