#pragma once

#include <iostream>
#include <stdlib.h>
#include "GraphUtils.h"

class ConsoleUI
{
public:
	void ExecuteCondensationGraphProgram();
	void getInputFromUser(int& o_NumberOfVertices, int& io_NumberOfEdges);

private:
	DirectedSimpleGraph* m_UserInputGraph;
};