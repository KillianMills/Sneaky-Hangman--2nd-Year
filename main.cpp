#include "hangman.h"
 
#include <iostream>
 
int main()
{
        bool b=false; // boolean for debug on/off
        char choice; // for chosing to play or not
        char mode; // for chosing debug mode or not
        std::cout<< "\n\n" <<"          ------WELCOME TO MY FIRST GAME: HANGMAN------"<< "\n\n" << "WOULD YOU LIKE TO PLAY? Y/N: ";
        std::cin>> choice;
       
        std::cout<< "\n\n"<< "WOULD YOU LIKE TO ENTER DEBUG MODE? Y/N: " ;
        std::cin>> mode ;
       
        if(mode=='Y' || mode == 'y'){
                std::cout<< "\n" << "                ------ENTERING DEDBUG MODE------"<< "\n\n";
                b = true;
        }
        else {
                std::cout<< "\n" << "                ------ENTERING NORMAL GAME------"<< "\n\n";
                b = false;
        }
               
        while(choice=='y' || choice=='Y'){ // lets the game be played again while the user does not input n or N
       
                hangman h(b);
                h.inputGuesses(); // user inputs the amount of guesses allowed
                h.inputWordSize(); // user inputs size of word to be used
                h.dashX(); // creates a string of - of length of word
                h.readFile(); // reads dictionary file
                h.difficulty(); // reads words of size word into vector
       
                h.mainGame(); // user guesses characters
                h.ending(); // end of game, print win or loss
               
                std::cout<< "Do you want to play again? Y/N: ";
                std::cin>> choice;
               
                if(choice=='n' || choice=='N'){
                        break;
                }
        }
       
        std::cout << "\n\n" << "GOOD BYE." << "\n\n" ;
        return 0;
}