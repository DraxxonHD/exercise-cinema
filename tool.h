#pragma once

enum class ENames;
enum class EMovies;
enum class ETimes;

class CTool
{
public:
	static int RandomNumRange(int _min, int _max);

	static ENames RandomName();
	static EMovies RandomMovie();
	static ETimes RandomTime();
	static bool RandomBool();
	CTool();
};