#pragma once
#include <string>

enum class EMovies;
enum class ETimes;

class CTool
{
public:
	static int RandomNumRange(int _min, int _max);

	static std::string RandomName();
	static EMovies RandomMovie();
	static ETimes RandomTime();
	static bool RandomBool();
	static void SetRandSeed();
public:
	static constexpr int s_NameLength = 5;
};