#pragma once

enum class ETimes;
enum class EMovies;
enum class ENames;

struct SOrder
{
	int m_NumOfVisitor;
	ETimes m_TimeOfMovie;
	EMovies m_Movie;
	ENames m_Name;
};