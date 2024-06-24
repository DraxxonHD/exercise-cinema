#pragma once
#include <string>
enum class ETimes;
enum class EMovies;

struct SOrder
{
	int m_NumOfVisitor;
	ETimes m_TimeOfMovie;
	EMovies m_Movie;
	std::string m_pName;
};