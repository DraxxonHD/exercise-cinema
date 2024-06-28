#include "tool.h"
#include "names.h"
#include "movies.h"
#include "times.h"

#include <random>
#include <time.h>
#include <string>


int CTool::RandomNumRange(int _min, int _max)
{
    int RandomNum = (rand() % (_max + 1)) + _min;
    return RandomNum;
}

std::string CTool::RandomName()
{
    char name[s_NameLength] = {};
    char AsciiChar;
    for (int i = 0; i < s_NameLength; i++) {
        int AsciiValue = rand() % 26 + 97;
        AsciiChar = (char)AsciiValue;
        name[i] = AsciiChar;
    }    

    std::string strName(name, s_NameLength);
    return strName;
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

void CTool::SetRandSeed()
{
    srand(time(NULL));
}

