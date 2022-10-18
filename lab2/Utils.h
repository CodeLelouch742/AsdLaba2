#ifndef LABA2_UTILS_H
#define LABA2_UTILS_H

#include <iostream>
#include <chrono>
#include <math.h>
#include <Windows.h>

using namespace std;

float pathLenght(float, float, float, float);
int snailsInput();
int snailsConfusionOutput();
void shortestTimeOutput(int);
void lookingSnailsConfusion();


int snailAmount=0;
float shortestTime = 141422;//100000*sqrt(2)+1 максимальная длина по диагонали


struct Snail
{
    float x = 0;
    float y = 0;
    int lenght = snailAmount - 1;
    bool confusion = false;
    float* paths = new float[lenght]();

    void lookingConfusion()//O(n*log(n))
    {
        mergerSort(paths, 0, lenght-1);
            if (paths[0] == paths[1])
                this->confusion = true;
    }

    void mergerSort(float* allPaths, int first, int last)//O(nlog(n))
    {

        int center = first + (last - first) / 2;
        if (first < last)
        {
            mergerSort(allPaths, first, center);
            mergerSort(allPaths, center + 1, last);

            merger(allPaths, first, center, last);//O(n)
        }
    }

    void merger(float* partPaths, int first, int center, int last)//O(n)
    {
        int i = 0, j = 0, k = first;
        int number1 = center - first + 1;
        int number2 = last - center;
        float* part1Paths = new float[number1]();
        float* part2Paths = new float[number2]();

        for (int i = 0; i < number1; i++)
            part1Paths[i] = partPaths[first + i];
        for (int j = 0; j < number2; j++)
            part2Paths[j] = partPaths[center + 1 + j];

        while (i < number1 && j < number2)
        {
            if (part1Paths[i] <= part2Paths[j])
            {
                partPaths[k] = part1Paths[i];
                i++;
            }
            else
            {
                partPaths[k] = part2Paths[j];
                j++;
            }
            k++;
        }

        while (i < number1)
        {
            partPaths[k] = part1Paths[i];
            i++;
            k++;
        }

        while (j < number2)
        {
            partPaths[k] = part2Paths[j];
            j++;
            k++;
        }
        delete[] part1Paths;
        delete[] part2Paths;
    }
};

#endif //LABA2_UTILS_H
