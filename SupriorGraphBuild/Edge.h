#pragma once

typedef int vertex;

class Edge
{
public:
	Edge(vertex u, vertex v);
	void SetVisitStatus(bool i_NewVisitStatus);
	bool IsVisited();

private:
	vertex m_U;
	vertex m_V;
	bool m_VisitStatus;
};