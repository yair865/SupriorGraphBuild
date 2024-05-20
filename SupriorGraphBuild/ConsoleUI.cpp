#include "ConsoleUI.h"
using namespace std;


void ConsoleUI::ExecuteCondensationGraphProgram()
{
	int n, m;
	DirectedSimpleGraph* userCondesationGraph;

	getInputFromUser(n, m);
	userCondesationGraph = GraphUtils::GenerateCondensationGraph(m_UserInputGraph);
	cout << userCondesationGraph->GetNumVertices() << " " << userCondesationGraph->GetNumEdges();

}

void ConsoleUI::getInputFromUser(int& o_NumberOfVertices, int& io_NumberOfEdges)
{
	vertex u, v;

	cout << "Please enter the number of vertices in the graph: " << endl;
	cin >> o_NumberOfVertices;

	if (o_NumberOfVertices < 1)
	{
		cout << "Invalid input!";
		exit(1);
	}
	
	m_UserInputGraph = DirectedSimpleGraph::MakeEmptyGraph(o_NumberOfVertices);
	
	cout << "Please enter the number of edges in the graph: " << endl;
	cin >> io_NumberOfEdges;

	if (io_NumberOfEdges < 1)
	{
		cout << "Invalid input!";
		exit(1);
	}

	try
	{
		cout << "Please enter the edges, two vertices separated by space then press enter to insert the next edge: " << endl;

		for (int i = 0; i < io_NumberOfEdges; i++)
		{
			cin >> u >> v;
			m_UserInputGraph->AddEdge(u, v);
		}
	}
	catch (const invalid_argument& e)
	{
		cout << e.what();
		exit(1);
	}
	catch (const exception& e)
	{
		cout << e.what();
		exit(1);
	}
	catch (...)
	{
		cout << "Error";
		exit(1);
	}
}
