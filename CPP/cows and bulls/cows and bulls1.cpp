#include "Hider.h"
#include<iostream>
#include<string>
#include<time.h>
#include "hider.cpp"
using namespace std;
int main(){
string words[7]={"quick","quack","junky","mixup","unzip","crazy"};

Hider hider;
string word=hider.pickUpWord(words,7);
string guess;
int noOfAttempts=0;
do {
    guess=hider.acceptGuess();
    hider.printBullsCowsCount(guess,word);
    if(hider.hasTheUserWon(guess,word))
        return 0;
    noOfAttempts++;
    if(hider.exceedAttempts(noOfAttempts)){
        return 1;
    }
    hider.getBullsCowsCount(guess,word);
}
while(true);
}
