#include "processing_office.h"
#include "order.h"
#include "times.h"

CProcessing_Office* CProcessing_Office::s_pSingleton = nullptr;
CProcessing_Office::CProcessing_Office()
    :m_TimeOfMovie(ETimes(2))
    ,m_Movie(EMovies(2))
    ,m_Capacity()
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
    if (_order.m_NumOfVisitor <= m_Capacity[static_cast<int>(_order.m_TimeOfMovie)][static_cast<int>(_order.m_Movie)])
    {
        // check Time
        if (_order.m_TimeOfMovie <= m_TimeOfMovie)
        {
            // check Movie
            if (_order.m_Movie <= m_Movie)
            {
                m_Capacity[static_cast<int>(_order.m_TimeOfMovie)][static_cast<int>(_order.m_Movie)] -= _order.m_NumOfVisitor;
                return true;
            }

        }


    }
    return false;
}

int CProcessing_Office::GetCapacityAt(int _time, int _movie)
{

    return m_Capacity[_time][_movie];
}

CProcessing_Office::~CProcessing_Office()
{
    s_pSingleton = nullptr;
}
