#pragma once
#ifndef RND_CLASS_H
#define RND_CLASS_H
#include <random>

using namespace std;

class CRnd
{
private:
    static random_device rd;
    static mt19937 gen;

public:
    int GetRandom(int minRange = 0, int maxRange = 255);
};

#endif
