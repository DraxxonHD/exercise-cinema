#include "receiving_office.h"
#include "processing_office.h"
#include "ticket_office.h"
#include "order.h"
#include "ticket.h"
#include "names.h"
#include "tool.h"

#include <assert.h>
#include <iostream>
#include <string>
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

void CReceiving_Office::CreateOrder(int _NumOfVisitor, ETimes _TimeOfMovie, EMovies _Movie, std::string _pname)
{
    // TODO: hier return-Anweisung eingeben
    SOrder* Order = new SOrder();
    Order->m_NumOfVisitor = _NumOfVisitor;
    Order->m_TimeOfMovie = _TimeOfMovie;
    Order->m_Movie = _Movie;
    Order->m_pName = _pname;

    if(!CReceiving_Office::GetInstance().IsTicketStorageFull())
    {
        if (CProcessing_Office::GetInstance().IsValidOrder(*Order))
        {
            CTicket_Office::GetInstance().CreateTicket(*Order);
        }
        else
        {
            CTicket_Office::GetInstance().DeleteOrder(*Order);
        }
    }
    else
    {
        CTicket_Office::GetInstance().DeleteOrder(*Order);
    }
    ///////////////////7
}

STicket* CReceiving_Office::PickUpTicket(std::string _pname)
{
    // TODO: hier return-Anweisung eingeben
    for (int i = 0; i < s_StorageCapacity; i++)
    {
        if (m_TicketStorage[i] != nullptr)
        {

            if (m_TicketStorage[i]->m_pName.compare(_pname) == 0)
            {


                STicket* Ticket = m_TicketStorage[i];
                // clear storage slot after ticket got picked up
                m_TicketStorage[i] = nullptr;
                CReceiving_Office::GetInstance().IncrementStorageSize();
                ////////////////////////////////
                return Ticket;
                break;
            }
        }
    }

    // return nothing
    return nullptr;
}

STicket** CReceiving_Office::GetTicketStorage()
{
    return m_TicketStorage;
}

bool CReceiving_Office::IsTicketStorageFull()
{
    if (m_SizeOfStorage <= 0)
    {
        return true;
    }
    return false;
}

void CReceiving_Office::PutTicketInStorage(STicket& _ticket)
{

    assert(m_SizeOfStorage <= s_StorageCapacity);
    for (int i = 0; i < s_StorageCapacity; i++)
    {
        if (m_TicketStorage[i] == nullptr)
        {
            m_TicketStorage[i] = &_ticket;
            CReceiving_Office::GetInstance().DecrementStorageSize();
            ////////////////////
            break;
        }
    }
}

void CReceiving_Office::IncrementStorageSize()
{
    m_SizeOfStorage += 1;
}

void CReceiving_Office::DecrementStorageSize()
{
    m_SizeOfStorage -=1;
}

CReceiving_Office::~CReceiving_Office()
{
    s_pSingleton = nullptr;
}
