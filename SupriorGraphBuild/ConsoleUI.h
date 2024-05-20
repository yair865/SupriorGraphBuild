#pragma once
#include <iostream>
#include <stdlib.h>
#include "GraphUtils.h"


class ConsoleUI
{
public:
	void ExecuteCondensationGraphProgram();
	~ConsoleUI();

private:
	DirectedSimpleGraph* m_UserInputGraph;

	void getAndCreateUserInputGraph(int& o_NumberOfVertices, int& io_NumberOfEdges);
	void exitProgram();
	
};