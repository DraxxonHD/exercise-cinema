#include "ticket_office.h"
#include "ticket.h"
#include "order.h"

CTicket_Office* CTicket_Office::s_pSingleton = nullptr;
CTicket_Office::CTicket_Office() = default;

CTicket_Office::~CTicket_Office()
{
    s_pSingleton = nullptr;
}

CTicket_Office& CTicket_Office::GetInstance()
{
    // TODO: hier return-Anweisung eingeben
    if (s_pSingleton == nullptr)
    {
        s_pSingleton = new CTicket_Office();
    }
    return *s_pSingleton;
}

void CTicket_Office::DestroyInstance()
{
    delete s_pSingleton;
}

STicket& CTicket_Office::CreateTicket(SOrder& _order)
{
    // TODO: hier return-Anweisung eingeben
    STicket* Ticket = new STicket();

    Ticket->m_Movie = _order.m_Movie;
    Ticket->m_NumOfVisitor = _order.m_NumOfVisitor;
    Ticket->m_TimeOfMovie = _order.m_TimeOfMovie;
    Ticket->m_Name = _order.m_Name;

    return *Ticket;
}

void CTicket_Office::DeleteOrder(SOrder& _order)
{
    delete &_order;
}

