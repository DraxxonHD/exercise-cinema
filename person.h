#pragma once
#include <string>

enum class EMovies;
enum class ETimes;
struct STicket;

class CPerson
{
public:

	void SetNumOfVisitor(int _NumOfVisitor);
	void SetTimeOfMovie(ETimes _TimeOfMovie);
	void SetMovie(EMovies _movie);
	void SetName(std::string _name);
	void SetTicket(STicket& _ticket);

	int GetNumOfVisitor();
	ETimes GetTimeOfMovie();
	EMovies GetMovie();
	std::string GetName();
	STicket* GetTicket();
private:

	int m_NumOfVisitor;
	ETimes m_TimeOfMovie;
	EMovies m_Movie;
	std::string m_pName;
	STicket* m_Ticket;
};