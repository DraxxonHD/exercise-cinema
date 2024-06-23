#pragma once

enum class ETimes;
enum class EMovies;
struct SOrder;

class CProcessing_Office
{
public:

	static CProcessing_Office& GetInstance();
	static void DestroyInstance();

	bool IsValidOrder(SOrder& _order);
	int GetCapacityAt(ETimes _time, EMovies _movie);
	void ReduceSeatsAt(int _NumOfVisitor, ETimes _time, EMovies _movie);
public:

	static constexpr int s_MaxNumOfVisitor = 5;
private:

	CProcessing_Office();
	~CProcessing_Office();

	CProcessing_Office(const CProcessing_Office&) = delete;
	CProcessing_Office operator = (const CProcessing_Office&) = delete;


	static CProcessing_Office* s_pSingleton;

private:

	int m_Capacity[3][3];
	ETimes m_TimeOfMovie;
	EMovies m_Movie;
};