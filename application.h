#pragma once

class CCustomer;
class CReceiving_Office;
class CProcessing_Office;
class CTicket_Office;


class CApplication
{
public:

	void Initialize();
	void Run();
	void Finalize();

public:

	static constexpr int s_NumOfCustomer = 50;
private:

	CCustomer* m_pCustomers[s_NumOfCustomer];

};