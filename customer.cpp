#include "customer.h"
#include "names.h"


void CCustomer::SetNumOfVisitor(int _NumOfVisitor)
{
    m_NumOfVisitor = _NumOfVisitor;
}

void CCustomer::SetTimeOfMovie(ETimes _TimeOfMovie)
{
    m_TimeOfMovie = _TimeOfMovie;
}

void CCustomer::SetMovie(EMovies _movie)
{
    m_Movie = _movie;
}

void CCustomer::SetName(ENames _name)
{
    m_Name = _name;
}

void CCustomer::SetTicket(STicket& _ticket)
{
    m_Ticket = &_ticket;
}

int CCustomer::GetNumOfVisitor()
{
    return m_NumOfVisitor;
}

ETimes CCustomer::GetTimeOfMovie()
{
    return m_TimeOfMovie;
}

EMovies CCustomer::GetMovie()
{
    return m_Movie;
}

ENames CCustomer::GetName()
{
    return m_Name;
}

STicket* CCustomer::GetTicket()
{
    return m_Ticket;
}
