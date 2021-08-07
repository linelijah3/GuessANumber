#include <iostream>
#include <unistd.h>

using namespace std;

void repeatAsk();
void repeatGuess();
int inputSetNumber,guessedNumber,actualNumber;
int main(){
    //initializes sets of numbers for user to guess
int numberSets[3][5]={{0,5,10,15,20},{0,1,2,3,100},{0,100,105,115,130}};
//initial message displayed before number sets
cout<<"Guess a Number program, ver 1.0, coding began on 8/6/2021\n";
sleep(1);
//for loop to display the number sets on console
for(int x=0;x<3;x++){
    cout<<x+1<<": {";
for (int y=0;y<5;y++){
    if(y==4){
cout<<numberSets[x][y];
    }else{
    cout<<numberSets[x][y]<<", ";
    }
}
cout<<"}"<<"\n";
sleep(1);
}
//program takes input of user for a specific number set
cout<<"What number set would you like to choose? (1,2,3)\n";
sleep(1);

cin>>inputSetNumber;
repeatAsk();
cout<<"You have chosen number set "<<inputSetNumber<<"\n";
sleep(1);
cout<<"The data set will be printed below:\n";
cout<<"{";
for(int z=0; z<5; z++){
if(z==4){
cout<<numberSets[inputSetNumber-1][z];
}else{
cout<<numberSets[inputSetNumber-1][z]<<", ";
}
}
cout<<"}\n";
sleep(1);
cout<<"Now, guess a number from that data set: ";
sleep(1);
cin>>guessedNumber;
actualNumber=rand()%5;
repeatGuess();
cout<<"Thank you for using this program!";
sleep(1);
}
void repeatGuess(){
    int numberSets[3][5]={{0,5,10,15,20},{0,1,2,3,100},{0,100,105,115,130}};
if(guessedNumber==numberSets[inputSetNumber-1][actualNumber]){
cout<<"Your guess was correct!\n";
sleep(1);
}else{
    cout<<"Try again, your guess was incorrect.\n";
    sleep(1);
    cin.clear();
    cin.ignore(10000,'\n');
    cin>>guessedNumber;
    repeatGuess();
}
}
//recursive function that outputs text based off of user input
void repeatAsk(){
    //only allows set numbers of 1-3
    if((inputSetNumber>0)&&(inputSetNumber<4)){
cout<<"Valid set number.\n";
sleep(1);
}else{
    cout<<"Invalid set number.\n";
    sleep(1);
    cout<<"Please enter a valid set number.\n";
    sleep(1);
    //clears previous input so the function doesn't continuously return the same "invalid" message
    cin.clear();
    cin.ignore(10000,'\n');
    cin>>inputSetNumber;
    //calls function again to accept user input again
    repeatAsk();
}
}