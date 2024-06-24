#include "scene.h"
#include "Person.h"
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
void CScene::Initialize()
{
	CTool Tool;
	// Create people
	for (int i = 0; i < s_NumOfPerson; i++)
	{
	CPerson* pPerson = new CPerson();

	m_pPersons[i] = pPerson;

	// give people different wishes for movies
	EMovies RandMovie = Tool.RandomMovie();
	int RandNumOfVisitor = Tool.RandomNumRange(1, 10);
	ETimes RandTime = Tool.RandomTime();
	std::string pRandName = Tool.RandomName();
	pPerson->SetMovie(RandMovie);
	pPerson->SetNumOfVisitor(RandNumOfVisitor);
	pPerson->SetTimeOfMovie(RandTime);
	pPerson->SetName(pRandName);

	}


}

void CScene::Finalize()
{
	// free memory of people
	for (int i = 0; i < s_NumOfPerson; i++)
	{
		delete m_pPersons[i];
	}
	// destroy Instances
	CReceiving_Office::DestroyInstance();
	CProcessing_Office::DestroyInstance();
	CTicket_Office::DestroyInstance();
}

void CScene::Run()
{
	//serve each person
	for (int i = 0; i < s_NumOfPerson; i++)
	{
		CTool Tool;

		CPerson& Person = *m_pPersons[i];
		int NumOfVisitor = Person.GetNumOfVisitor();
		ETimes TimeOfMovie = Person.GetTimeOfMovie();
		EMovies Movie = Person.GetMovie();
		std::string pName = Person.GetName();

		// Person makes an order
		CReceiving_Office::GetInstance().CreateOrder(NumOfVisitor, TimeOfMovie, Movie, pName);


		//  pick up ticket/no ticket
		STicket* pTicket = CReceiving_Office::GetInstance().PickUpTicket(Person.GetName());

		// give ticket to Person
			Person.SetTicket(*pTicket);
		// Who got ticket?
		if(pTicket != nullptr)
		{
			std::cout << "Person: " << Person.GetName() << " | Got The Ticket for: " << Person.GetNumOfVisitor() << " Visitor | For The Movie: " << static_cast<int>(Person.GetMovie()) << " | For the Time: " << static_cast<int>(Person.GetTimeOfMovie()) << std::endl;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << CProcessing_Office::GetInstance().GetCapacityAt(static_cast<ETimes>(i), static_cast<EMovies>(j)) << "  ";
		}
		std::cout << "" << std::endl;
	}
}
