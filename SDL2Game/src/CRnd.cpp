#include "CRnd.h"

random_device CRnd::rd;        // obtain a random number from hardware
mt19937 CRnd::gen(CRnd::rd()); // seed the generator

int CRnd::GetRandom(int minRange, int maxRange)
{
    uniform_int_distribution<int> distr(minRange, maxRange); // define the range
    return distr(gen);                                       // generate numbers
};
