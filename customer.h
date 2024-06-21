#pragma once

enum class EMovies;
enum class ENames;
enum class ETimes;
struct STicket;

class CCustomer
{
public:

	void SetNumOfVisitor(int _NumOfVisitor);
	void SetTimeOfMovie(ETimes _TimeOfMovie);
	void SetMovie(EMovies _movie);
	void SetName(ENames _name);
	void SetTicket(STicket& _ticket);

	int GetNumOfVisitor();
	ETimes GetTimeOfMovie();
	EMovies GetMovie();
	ENames GetName();
	STicket* GetTicket();
private:

	int m_NumOfVisitor;
	ETimes m_TimeOfMovie;
	EMovies m_Movie;
	ENames m_Name;
	STicket* m_Ticket;
};