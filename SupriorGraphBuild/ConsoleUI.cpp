#include "ConsoleUI.h"
using namespace std;


void ConsoleUI::ExecuteCondensationGraphProgram()
{
	int n, m;

	getInputFromUser(n, m);
	

}

void ConsoleUI::getInputFromUser(int& o_NumberOfVertices, int& io_NumberOfEdges)
{
	cout << "Please enter the number of vertices in the graph: ";
	cin >> o_NumberOfVertices;

	if (o_NumberOfVertices < 0)
	{
		cout << "Invalid input!";
		exit(1);
	}

	cout << "Please enter the number of vertices in the graph: ";
	cin >> io_NumberOfEdges;

	if (io_NumberOfEdges < 0)
	{
		cout << "Invalid input!";
		exit(1);
	}

	try
	{
		for (int i = 0; i < io_NumberOfEdges; i++)
		{
			
		}
	}
}
