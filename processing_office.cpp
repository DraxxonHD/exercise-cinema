#include "processing_office.h"
#include "ticket_office.h"
#include "order.h"
#include "times.h"

#include <iostream>
#include <assert.h>
CProcessing_Office* CProcessing_Office::s_pSingleton = nullptr;
CProcessing_Office::CProcessing_Office()
    :m_TimeOfMovie(ETimes(2))
    ,m_Movie(EMovies(2))
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
    m_Capacity[i][j] = s_MaxNumOfVisitor;

        }
    }
}

CProcessing_Office& CProcessing_Office::GetInstance()
{
    // TODO: hier return-Anweisung eingeben
    if (s_pSingleton == nullptr)
    {
        s_pSingleton = new CProcessing_Office();
    }
    return *s_pSingleton;
}

void CProcessing_Office::DestroyInstance()
{
    delete s_pSingleton;
}

bool CProcessing_Office::IsValidOrder(SOrder& _order)
{
    // TODO: hier return-Anweisung eingeben

    // Check Cap
    int currentcap = CProcessing_Office::GetInstance().GetCapacityAt(_order.m_TimeOfMovie, _order.m_Movie);
    if (_order.m_NumOfVisitor <= currentcap)
    {
        // check Time
        if (_order.m_TimeOfMovie <= m_TimeOfMovie)
        {
            // check Movie
            if (_order.m_Movie <= m_Movie)
            {
                ///////////////////7
                return true;
            }

        }


    }
    return false;
}

int CProcessing_Office::GetCapacityAt(ETimes _time, EMovies _movie)
{

    return m_Capacity[static_cast<int>(_time)][static_cast<int>(_movie)];
}

void CProcessing_Office::ReduceSeatsAt(int _NumOfVisitor, ETimes _time, EMovies _movie)
{
    m_Capacity[static_cast<int>(_time)][static_cast<int>(_movie)] -= _NumOfVisitor;
}

CProcessing_Office::~CProcessing_Office()
{
    s_pSingleton = nullptr;
}
