#include "ticket_office.h"
#include "receiving_office.h"
#include "processing_office.h"
#include "ticket.h"
#include "order.h"
#include "times.h"
#include "movies.h"

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

void CTicket_Office::CreateTicket(SOrder& _order)
{
    // TODO: hier return-Anweisung eingeben
    STicket* Ticket = new STicket();

    Ticket->m_Movie = _order.m_Movie;
    Ticket->m_NumOfVisitor = _order.m_NumOfVisitor;
    Ticket->m_TimeOfMovie = _order.m_TimeOfMovie;
    Ticket->m_pName = _order.m_pName;

    CProcessing_Office::GetInstance().ReduceSeatsAt(Ticket->m_NumOfVisitor, static_cast<ETimes>(Ticket->m_TimeOfMovie), static_cast<EMovies>(Ticket->m_Movie));
    CReceiving_Office::GetInstance().PutTicketInStorage(*Ticket);
    ///////////////////7
}

void CTicket_Office::DeleteOrder(SOrder& _order)
{
    delete &_order;
}

