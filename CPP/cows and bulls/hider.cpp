#include "Hider.h"
#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
using namespace std;
Hider::Hider(){

}

int Hider::getRandomNumber(int max){
    int random;
    random=rand()%max;
    return random;
}

string Hider::pickUpWord(string listOfWords[],int length){
    srand(time(NULL));
    int random=getRandomNumber(length);
    return listOfWords[random];
}

string Hider::getUserChoice(){
  string userChoice;
  cin>>userChoice;
  return userChoice;
}

bool Hider::validate(string guess){

    if(guess.length()!=5) {
        cout<<"Enter word of 5 length ";
        return false;
    }

    bool validGuess=true;
    for(int i=0;i<guess.length();i++){
        char ch=guess[i];
        if(ch<'a' || ch>'z'){
            validGuess=false;
            cout<<"Word should be formatted by letters a-z"<<endl;
            break;
        }

    for(int j=0;j<guess.length()&&j!=i;j++)
    {
        if(ch==guess[j]){
            validGuess=false;
            cout<<"repeating chracters"<<endl;
            break;
        }
    }
    if(!validGuess)
        break;
    }
    return validGuess;
}

string Hider::acceptGuess(){
  string guess;
  do{
    guess=getUserChoice();
    cout<<"user:"<<guess;
  }
  while(!validate(guess));
  return guess;
}

bool Hider::hasTheUserWon(string guess,string word){
 if(guess==word){
    cout<<"you got it right"<<endl;
    return true;
 }
 else{
    return false;
 }
}

bool Hider::exceedAttempts(int attempts){
    if(attempts>10){
        cout<<"You have exceeded attempts"<<endl;
        return true;
    }
    return false;
}

int* Hider::getBullsCowsCount(string guess,string word){
    int bullsCount=0,cowsCount=0;
    int* count=new int[2];
    for(int i=0;i<guess.length();i++)
    {
        char chGuess=guess[i];
        for(int j=0;j<word.length();j++){
            if(chGuess==word[j]&&i==j)bullsCount++;
            else if(chGuess==word[j] && i!=j)cowsCount++;
        }
    }
    count[0]=bullsCount;
    count[1]=cowsCount;
    return count;
}
void Hider::printBullsCowsCount(string guess,string word){
int* count=getBullsCowsCount(guess,word);
cout<<"Bulls:"<<count[0]<<"Cows:"<<count[1]<<endl;
}

