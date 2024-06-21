#pragma once


enum class ETimes;
enum class EMovies;
enum class ENames;

struct SOrder;
struct STicket;

class CReceiving_Office
{
public:

	static CReceiving_Office& GetInstance();
	static void DestroyInstance();

public:

	SOrder& CreateOrder(int _NumOfVisitor, ETimes _TimeOfMovie, EMovies _Movie, ENames _name);
	STicket* PickUpTicket(ENames _name);
	STicket** GetTicketStorage();

	void PutTicketInStorage(STicket& _ticket);

private:

	CReceiving_Office();
	~CReceiving_Office();

	CReceiving_Office(const CReceiving_Office&) = delete;
	CReceiving_Office operator = (const CReceiving_Office&) = delete;

	static CReceiving_Office* s_pSingleton;

	static constexpr int s_StorageCapacity = 20;
private:

	STicket* m_TicketStorage[s_StorageCapacity];
	int m_SizeOfStorage;
};