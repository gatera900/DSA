// Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include<ctime>
#include <string>


using namespace std;

const int MAX_TRIES = 5;
int letterFill(char, string, string&);



 //we can make this program better by adding a hint for each word that is given. Plus, lets  change it to something people from NOrth america are more familiar with. 
int main()
{

  //HANDLE  hConsole;

  //hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

 // SetConsoleTextAttribute(hConsole, 40);
  string name;
  string yes_or_no;
  char letter;
  int num_of_wrong_guesses = 0;
  string hint;

  string word;
  string words[] =
  {
    "mexico",
    "france",
    "italy",
    "southafrica",
    "japan",
    "australia",
    "egypt",
    "singapore",
    "china",
    "turkey"
  };

  //choose and copy a word from array of words randomly
  srand(time(NULL));
  int n = rand() % 10; //range from to 0 and 10. so it will basically choose randomly any of these words. 
  word = words[n]; // word is equal to one of the country names in the array.


  switch (n) // a switch statement that will execute based on which word is chosen.  Range is from zero to 10. 
  {
  case 0: //if Mexico is chosen as the word to guess. Then give the player this hint. 
    hint = "Hint: This country shares a border with the USA";
    break;

  case 1: //if  France  is chosen as the word to guess. Then give the player this hint. 
    hint = "Hint: This country has the Eiffel tower";
    break;

  case 2: //if  Italy  is chosen as the word to guess. Then give the player this hint. 
    hint = "Hint: This country has the city called Rome";
    break;

  case 3: //if  South Africa  is chosen as the word to guess. Then give the player this hint. 
    hint = "Hint: The country in which nelson Mandela was born (Do not enter a space for this one)";
    break;


  case 4: //if  Japan  is chosen as the word to guess. Then give the player this hint. 
    hint = "Hint: The country in which anime was created";
    break;


  case 5: //if  Australia  is chosen as the word to guess. Then give the player this hint. 
    hint = "Hint: This country has kangaroos";
      break;

  case 6:   //if  Egypt  is chosen as the word to guess. Then give the player this hint. 
  hint = "Hint: This country has giant pyramids";
    break;


  case 7: //if  Singapore  is chosen as the word to guess. Then give the player this hint. 
    hint = "Hint: This country has a amazing airport called  Changi Airport";
    break;

  case 8: //if china  is chosen as the word to guess. Then give the player this hint. 
    hint = "Hint: This country has a place called Beijing.";
    break;

  case 9: //if Turkey  is chosen as the word to guess. Then give the player this hint. 
    hint = "Hint: This country has a place called Istanbul.";
    break;
  }


  // Initialize the secret word with the * character.
  string unknown(word.length(), ('_')); //takes each letter of the word and displays it with -. 

  // welcome the user
  cout << "\n\nWelcome to the guessing game...Guess a country Name"; //starts a new line and prints the quoted text. 
  cout << "\n\nEach letter is represented by a star."; //starts a new line and prints the quoted text. 
  cout << "\n\nYou have to type only one letter in one try";  //starts a new line and prints the quoted text. 
  cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";  //Starts a new line. prints the quoted text and max number of tries. 
  cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl; //starts a new line and prints the quoted text. 
  
  // Loop until the guesses are used up
  while (num_of_wrong_guesses < MAX_TRIES)
  {
    cout << endl << hint << endl;
    cout << "\n\n" << unknown;         //new line  and the displays the word in a hidden way. 
    cout << "\n\nGuess a letter: ";    //prints the quoted text with a new line. 
    cin >> letter;                      //user enters the guessed letter.

    // Fill secret word with letter if the guess is correct,
    // otherwise increment the number of wrong guesses.
    if (letterFill(letter, word, unknown) == 0)  //returns the letter the user entered.  the current word selected and how much of the word the user has guessed. 
    {
      cout << endl << "\n\Whoops! That letter isn't in there!" << endl;   //prints the quoted text and ends line.
      num_of_wrong_guesses++; //increase the number of guesses by one. 
    }
    else
    {
      cout << endl << "\n\You found a letter! Isn't that exciting!" << endl; // print the text and ends the line. 
    }
    // Tell user how many guesses has left.
    cout << "\n\You have " << MAX_TRIES - num_of_wrong_guesses; //prints the number of guesses left. This is done by subtracting the number of guesses from the number of max tries. 
    cout << " guesses left." << endl; //Prints the quoted text. 
    // Check if user guessed the word.
    if (word == unknown)
    {
      cout << word << endl; //prints the word selected for the user to guess. 
      cout << "\n\Yeah! You got it!" << endl;
      cout << "\n\Would like to play another round of guessing?" << endl;
      cout << "\n\Enter yes or no" << endl; 

      cin >> yes_or_no;

      if (yes_or_no == "yes") // if user says yes, then start the game again. 
      {
        main(); 
      }


      if (yes_or_no == "no") // if user says no, then end the game. 
      {
        cout << "Closing program" << endl;
        return 0; //returns 0 to close the program.
        
      }
      break;
    }
  }
  if (num_of_wrong_guesses == MAX_TRIES) //to execute when the number of wrong guesses equals the number of max tries. 
  {
    cout << "\n\Sorry, you lose." << endl;
    cout << "\n\The word was " << word << endl;
    cout << "\n\Would like to play another round of guessing?" << endl;
    cout << "\n\Enter yes or no" << endl;

    cin >> yes_or_no;

    if (yes_or_no == "yes") // if user says yes, then start the game again. 
    {
      main();
    }

    if (yes_or_no == "no") // if user says no, then end the game. 
    {
      cout << "Closing program" << endl;
        return 0; //returns 0 to close the program.
       
    }

  }
  return 0; //ensures the program exits better. 
  //cin.ignore(); not needed. Causes issues with exiting. 
  //cin.get();  not needed. Causes issues with exiting. 
 
}

/* Take a one character guess and the secret word, and fill in the
 unfinished guess word. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */

int letterFill(char guess, string secretword, string& guessword)
{
  int i;
  int matches = 0;
  int len = secretword.length();
  for (i = 0; i < len; i++)
  {
    // Did we already match this letter in a previous guess?
    if (guess == guessword[i])
      return 0;
    // Is the guess in the secret word?
    if (guess == secretword[i])
    {
      guessword[i] = guess;
      matches++;
    }
  }
  return matches;
}

