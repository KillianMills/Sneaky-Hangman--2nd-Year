#include "hangman.h"
#include "sneaky.h"
 
#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include<time.h>
 
using namespace std;
 
hangman::hangman(bool b){
                        debug = b;
}
 
void hangman::inputGuesses(){ // prompts user to input the amount of guesses allowed
        cout << "\n\n" <<"PLEASE ENTER THE NUMBER OF GUESSES FOR THE USER TO HAVE: " ;
        cin >> guesses;
        while(!(cin.good()) || guesses<=0 || guesses>26){ // limit user to at least the whole alphabet, change in future       
                        cin.clear();
                        cout<< "INVALID INPUT, PLEASE ENTER A NUMBER BETWEEN 1 AND 26: " ;
                        cin >> guesses;
        }
}
 
void hangman::inputWordSize(){  //prompts user to input the word size or difficulty of the word
        cout << "\n" << "PLEASE ENTER THE SIZE OF WORD YOU WOULD LIKE: " ;
        cin >> wordSize;
        while(!(cin.good()) || wordSize<=0 || wordSize == 26 ||  wordSize == 27 || wordSize>29 ){ // no words of length 0,27,26,>29
                        cin.clear();
                        cout<< "NO WORD OF THAT SIZE, PLEASE INPUT A VALID WORD SIZE: ";
                        cin >> wordSize;
                }
}
 
void hangman::dashX(){ // makes a string of "-" of word length
        for(int i=0; i<wordSize; i++){
                dashWord=dashWord + "-"; //fills string with - for as many letters as there is
        }
}
 
void hangman::readFile(){ //read in file to vector holding entire dictionary
        ifstream file("dictionary.txt");
        istream_iterator<string> start(file), end;
        vector<string> myVector(start, end);
        vecsVector = myVector;
}      
 
void hangman::difficulty(){ //make vector holding all words of size wordSize
        for(int i = 0; i < vecsVector.size(); i++)
        {
            string temp = vecsVector[i];
            if(temp.length() == wordSize){
                        sliceVector.push_back(temp);
            }
        }
}
 
string hangman::random(){  //selects a word at random from the vector of size wordSize
        srand(time(NULL));
        int randomIndex = rand() % sliceVector.size();
        string random = sliceVector[randomIndex];
        return random;
}
 
void hangman::mainGame(){ // where the user will guess the word by inputting character guesses
        cout<< "\n\n" <<  "                ------LET THE GAMES BEGIN!------ "<< "\n\n";
 
        //keep user guessing while guesses!=0
        while(guesses!=0){
       
                int check = guesses;//stores the value of guesses at the start of each guess
                cout <<"WORD SO FAR: " << dashWord << "\n\n";
                cout << "LETTERS USED: "<< usedLetters << endl;
                cout << "GUESSES LEFT: " << guesses << endl;
               
                currentWord = random(); // selects a random word
               
                if(debug==true){
                        cout << "CURRENT WORD: " << currentWord << endl;
                }
               
                cout << "PLEASE ENTER YOUR GUESS: ";   
                cin >> userGuess;
                cout<< "\n";
               
                sneaky s;
                s.makeFamily(sliceVector, userGuess, debug);// makes families based on the dictionary, user input and wordSize
       
                for(int index=0; index<wordSize; index++){      // checks the guess against the first word in the new vector
                        string temp = sliceVector[0];
                        if(userGuess==temp[index]){ // if it has one of these letter the user will not lose any guesses
                                dashWord[index]=userGuess;
                                guesses++;
                        }
                }
               
                if(currentWord==dashWord){ //user guesses the word, break out of loop
                        break;
                }      
               
                usedLetters = usedLetters + userGuess + ' '; // updates list of characters used
                guesses--; // decrements guesses each time
               
                if (guesses>check){ // makes sure you do not get lives back for multiple occurences of letters
                        guesses=check;
                }
                cout << "\n\n";
        }
}
 
void hangman::ending(){ // messages for the end game
 
        currentWord = random(); // selects a random word for the last time, will select same word if user has won.
       
        //loss condition
        if(dashWord!=currentWord){
                cout << "\n\n" << "SORRY THE WORD WAS: " + currentWord + ", YOU LOSE :( " << "\n\n";
        }
 
        //win condition
        else if(dashWord==currentWord){
                cout << "\n\n" << "CONGRATULATIONS, YOU HAVE WON. THE WORD WAS: " + dashWord << "\n\n";
        }
}