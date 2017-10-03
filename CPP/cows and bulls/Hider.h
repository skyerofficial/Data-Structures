#ifndef HIDER_H_
#define HIDER_H_

#include <iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
using namespace std;
class Hider{
public:
    Hider();
    int getRandomNumber(int);
    string pickUpWord(string[],int);
    string getUserChoice();
    bool validate(string);
    string acceptGuess();
    bool hasTheUserWon(string ,string );
    bool exceedAttempts(int);
    int* getBullsCowsCount(string,string);
    void printBullsCowsCount(string,string);
};
#endif
