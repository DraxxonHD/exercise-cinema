#pragma once

struct STicket;
struct SOrder;

class CTicket_Office
{
public:

	static CTicket_Office& GetInstance();
	static void DestroyInstance();

	void CreateTicket(SOrder& _order);
	void DeleteOrder(SOrder& _order);

private:

	CTicket_Office();
	~CTicket_Office();

	CTicket_Office(const CTicket_Office&) = delete;
	CTicket_Office operator = (const CTicket_Office&) = delete;

	static CTicket_Office* s_pSingleton;
};