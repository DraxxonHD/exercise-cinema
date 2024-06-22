#include "Person.h"
#include "names.h"


void CPerson::SetNumOfVisitor(int _NumOfVisitor)
{
    m_NumOfVisitor = _NumOfVisitor;
}

void CPerson::SetTimeOfMovie(ETimes _TimeOfMovie)
{
    m_TimeOfMovie = _TimeOfMovie;
}

void CPerson::SetMovie(EMovies _movie)
{
    m_Movie = _movie;
}

void CPerson::SetName(ENames _name)
{
    m_Name = _name;
}

void CPerson::SetTicket(STicket& _ticket)
{
    m_Ticket = &_ticket;
}

int CPerson::GetNumOfVisitor()
{
    return m_NumOfVisitor;
}

ETimes CPerson::GetTimeOfMovie()
{
    return m_TimeOfMovie;
}

EMovies CPerson::GetMovie()
{
    return m_Movie;
}

ENames CPerson::GetName()
{
    return m_Name;
}

STicket* CPerson::GetTicket()
{
    return m_Ticket;
}
