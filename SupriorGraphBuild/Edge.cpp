#include "Edge.h"

Edge::Edge(vertex u, vertex v) : m_U(u), m_V(v), m_VisitStatus(false)
{
}

void Edge::SetVisitStatus(bool i_NewVisitStatus)
{
	m_VisitStatus = i_NewVisitStatus;
}

bool Edge::IsVisited()
{
	return m_VisitStatus;
}