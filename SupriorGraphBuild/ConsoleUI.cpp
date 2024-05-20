#include "ConsoleUI.h"
using namespace std;

// This method recieves information about a graph from the user, generates it, generates the condesation graph of the input graph
// and prints the number of vertices and edges in the condesation of the graph
void ConsoleUI::ExecuteCondensationGraphProgram()
{
	int n, m;
	DirectedSimpleGraph* userCondesationGraph;

	getAndCreateUserInputGraph(n, m);
	userCondesationGraph = GraphUtils::GenerateCondensationGraph(m_UserInputGraph);
	cout << userCondesationGraph->GetNumVertices() << " " << userCondesationGraph->GetNumEdges();

	delete userCondesationGraph;
}

// This method recieves information about a graph from the user and creates it
void ConsoleUI::getAndCreateUserInputGraph(int& o_NumberOfVertices, int& io_NumberOfEdges)
{
	vertex u, v;

	cout << "Please enter the number of vertices in the graph: " << endl;
	cin >> o_NumberOfVertices;

	if (o_NumberOfVertices < 1)
	{
		exitProgram();
	}
	
	m_UserInputGraph = DirectedSimpleGraph::MakeEmptyGraph(o_NumberOfVertices);
	
	cout << "Please enter the number of edges in the graph: " << endl;
	cin >> io_NumberOfEdges;

	if (io_NumberOfEdges < 1)
	{
		exitProgram();
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
		exitProgram();
	}
	catch (const exception& e)
	{
		cout << e.what();
		exitProgram();
	}
	catch (...)
	{
		cout << "Error!";
		exitProgram();
	}
}

// This method exits the program
void ConsoleUI::exitProgram()
{
	cout << "Invalid input!";

	if (m_UserInputGraph != nullptr)
	{
		delete m_UserInputGraph;
	}

	exit(1);
}

// The destructor the the class
ConsoleUI::~ConsoleUI()
{
	if (m_UserInputGraph != nullptr)
	{
		delete m_UserInputGraph;
	}
}
