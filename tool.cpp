#include "tool.h"
#include "names.h"
#include "movies.h"
#include "times.h"

#include <random>
#include <time.h>

CTool::CTool()
{
    srand(time(NULL));
}


int CTool::RandomNumRange(int _min, int _max)
{
    int RandomNum = (rand() % (_max + 1)) + _min;
    return RandomNum;
}

ENames CTool::RandomName()
{
    int RandNum = RandomNumRange(0, 39);
    return ENames(RandNum);
}

EMovies CTool::RandomMovie()
{
    int RandNum = RandomNumRange(0, 2);
    return EMovies(RandNum);
}

ETimes CTool::RandomTime()
{
    int RandNum = RandomNumRange(0, 2);
    return ETimes(RandNum);
}

bool CTool::RandomBool()
{
    bool RandBool = (CTool::RandomNumRange(0, 1));
    return RandBool;
}

