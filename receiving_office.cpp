#include "receiving_office.h"
#include "order.h"
#include "ticket.h"
#include "names.h"

#include <assert.h>

CReceiving_Office* CReceiving_Office::s_pSingleton = nullptr;

CReceiving_Office::CReceiving_Office()
    :m_SizeOfStorage(s_StorageCapacity)
{
    for (int i = 0; i < s_StorageCapacity; i++)
    {
        m_TicketStorage[i] = nullptr;
    }
}

CReceiving_Office& CReceiving_Office::GetInstance()
{
    // TODO: hier return-Anweisung eingeben
    if (s_pSingleton == nullptr)
    {
        s_pSingleton = new CReceiving_Office();
    }
    return *s_pSingleton;
}

void CReceiving_Office::DestroyInstance()
{
    delete s_pSingleton;
}

SOrder& CReceiving_Office::CreateOrder(int _NumOfVisitor, ETimes _TimeOfMovie, EMovies _Movie, ENames _name)
{
    // TODO: hier return-Anweisung eingeben
    SOrder* Order = new SOrder();

    Order->m_NumOfVisitor = _NumOfVisitor;
    Order->m_TimeOfMovie = _TimeOfMovie;
    Order->m_Movie = _Movie;
    Order->m_Name = _name;


    return *Order;
}

STicket* CReceiving_Office::PickUpTicket(ENames _name)
{
    // TODO: hier return-Anweisung eingeben
    for (int i = 0; i < s_StorageCapacity; i++)
    {
        if (m_TicketStorage[i]->m_Name == _name)
        {
            STicket* Ticket = m_TicketStorage[i];
            m_TicketStorage[i] = nullptr;
            return Ticket;
            break;
        }
    }

    // return nothing
    return nullptr;
}

STicket** CReceiving_Office::GetTicketStorage()
{
    return m_TicketStorage;
}

void CReceiving_Office::PutTicketInStorage(STicket& _ticket)
{
    assert(m_SizeOfStorage <= s_StorageCapacity);
    for (int i = 0; i < s_StorageCapacity; i++)
    {
        if (m_TicketStorage[i] == nullptr)
        {
            m_TicketStorage[i] = &_ticket;
            break;
        }
    }
}

CReceiving_Office::~CReceiving_Office()
{
    s_pSingleton = nullptr;
}
