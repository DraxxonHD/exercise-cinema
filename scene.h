#pragma once

class CPerson;
class CReceiving_Office;
class CProcessing_Office;
class CTicket_Office;


class CScene
{
public:

	void Initialize();
	void Run();
	void Finalize();

public:

	static constexpr int s_NumOfPerson = 50;
private:

	CPerson* m_pPersons[s_NumOfPerson];

};