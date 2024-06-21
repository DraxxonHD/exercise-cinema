#include "application.h"
#include "customer.h"
#include "movies.h"
#include "times.h"
#include "receiving_office.h"
#include "order.h"
#include "processing_office.h"
#include "ticket_office.h"
#include "ticket.h"
#include "tool.h"

#include <string>
#include <iostream>
void CApplication::Initialize()
{
	CTool Tool;
	for (int i = 0; i < s_NumOfCustomer; i++)
	{
	CCustomer* pCustomer = new CCustomer();

	m_pCustomers[i] = pCustomer;

	EMovies RandMovie = Tool.RandomMovie();
	int RandNumOfVisitor = Tool.RandomNumRange(1, 10);
	ETimes RandTime = Tool.RandomTime();
	ENames RandName = Tool.RandomName();

	pCustomer->SetMovie(RandMovie);
	pCustomer->SetNumOfVisitor(RandNumOfVisitor);
	pCustomer->SetTimeOfMovie(RandTime);
	pCustomer->SetName(RandName);




	}


}

void CApplication::Finalize()
{

	for (int i = 0; i < s_NumOfCustomer; i++)
	{
		delete m_pCustomers[i];
	}

	CReceiving_Office::GetInstance().DestroyInstance();
	CProcessing_Office::GetInstance().DestroyInstance();
	CTicket_Office::GetInstance().DestroyInstance();
}

void CApplication::Run()
{
	for (int i = 0; i < s_NumOfCustomer; i++)
	{

		int NumOfVisitor = m_pCustomers[i]->GetNumOfVisitor();
		ETimes TimeOfMovie = m_pCustomers[i]->GetTimeOfMovie();
		EMovies Movie = m_pCustomers[i]->GetMovie();
		ENames pName = m_pCustomers[i]->GetName();

		// customer makes an order
		SOrder& Order = CReceiving_Office::GetInstance().CreateOrder(NumOfVisitor, TimeOfMovie , Movie, pName);

		CCustomer& Customer = *m_pCustomers[i];

		// order is been given to processing office to check the order
		if (CProcessing_Office::GetInstance().IsValidOrder(Order))
		{
			// after check give it to ticket office
			STicket Ticket = CTicket_Office::GetInstance().CreateTicket(Order);
			CReceiving_Office::GetInstance().PutTicketInStorage(Ticket);
			// try to pick up ticket
			STicket* PickUpTicket = CReceiving_Office::GetInstance().PickUpTicket(Customer.GetName());

			// give ticket to customer
			Customer.SetTicket(*PickUpTicket);
			// Who got ticket?
				std::cout << "Customer: " << static_cast<int>(Customer.GetName()) << "| Got The Ticket for: " << Customer.GetNumOfVisitor() << " Visitor | For The Movie: " << static_cast<int>(Customer.GetMovie()) << " | For the Time: " << static_cast<int>(Customer.GetTimeOfMovie()) << std::endl;
			
		}
		else
		{
			//Who got no ticket?
			std::cout << "NO Ticket FOR: " << static_cast<int>(Customer.GetName()) << std::endl;
			CTicket_Office::GetInstance().DeleteOrder(Order);
		}
	}

// Check Caps
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

	std::cout << CProcessing_Office::GetInstance().GetCapacityAt(i,j) << std::endl;
		}
	}
}
