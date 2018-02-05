// Stephanie Wilson IN200
// Module 03
// Adventure 1

#include <iostream>
#include <string>
#include <sstream>
#include <chrono>  // used for sleep
#include <thread>  // used for sleep
#include <cstdlib> // used to generate random numbers
#include <ctime>   // used to generate random numbers

using namespace std;

int main() 
{
  // Variables
  string mystr;
  string playerName;
  string response;
  int health = 10;
  int attack = 0;
  int block = 0; 
  int totalTurns = 0;
  int gameOver = 0;
  srand(time(0)); // seed random generator with current time
  
  // Prompt player for name and welcome 
  cout << "To begin your adventure, enter your name: " ;
  getline(cin, mystr);
  stringstream(mystr) >> playerName;
  cout << "\nHello, " << playerName << "! Welcome to your adventure!\n\n" << endl;
  this_thread::sleep_for(chrono::milliseconds(500));
  cout << "Your starting health is " << health << ". Every 4-point block builds your health by one. Let's begin!\n";
  
  // generate a random number for the number of turns the player will have
  gameOver = (rand() % 10) + 1; // generate random number between 1-10
    cout << "\nYou will have " << gameOver << " turns." << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
  
  // ask if player wants to see numbers used in game
  cout << "\nWould you like to see the numbers used in your adventure? Y or N: ";
    getline(cin, mystr);
    stringstream(mystr) >> response;
  
  this_thread::sleep_for(chrono::milliseconds(500));
  
  // while the player's health is more than 0 and they still have turns, generate random numbers for attacks and blocks
  do
  {
    bool blockSuccess;
    ++totalTurns;
    attack = (rand() % 4) + 1; // generate a random number 1-4
    block = (rand() % 4) + 1;  // generate a random number 1-4
    this_thread::sleep_for(chrono::milliseconds(1000)); // pause 500 milliseconds between turns
    
    if (block >= attack)
    {
      blockSuccess = true;
      if (block == 4)  // player gets 1 point added to health if their block is 4
      {
        health += 1;
        cout << "\nYou're building your strength! Keep it up!" << endl;
      }
      else
        cout << "\nSuccessful block! Way to go!" << endl;
    }
    else
    {
      health -= attack; // subtract attack from health and store result in health
      cout << "\nOh no! Better luck next time!" << endl;
    }
    
    if (response == "Y" || response == "y")  // if player wants to see numbers used in game
    {
      cout << "Turn #" << totalTurns << ": \n";
      cout << "Attack: " << attack << endl;
      cout << "Block: " << block << endl;
      cout << "Current Health: " << health << endl;
    }
      
  } while (health > 0 && totalTurns < gameOver);
  
  this_thread::sleep_for(chrono::milliseconds(1000));
  
  // let player know how they did
  if (health >= 8)
  {
    cout << "\n\nCongratulations, " << playerName << "! You're indestructable! You survived with an amazing  health of " << health << "!" << endl;
  }
    else if (health > 5 && health < 8)
    {
      cout << "\nCongratulations, " << playerName << "! You survived and are still doing great! Your health is " << health << "." << endl;
    }
    else if (health > 0 && health <= 5)
    {
      cout << "\nCongratulations, " << playerName << "! You survived, but you're looking a little green. You should really see a doctor. Your health is " << health << ".";
    }
  else
    cout << "\n\nOh no, " << playerName << "! Rest in peace ..." << endl;
  
  
  return 0;
}