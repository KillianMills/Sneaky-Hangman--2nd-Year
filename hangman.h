#include <string>
#include <vector>
 
using namespace std;
 
class hangman
{
public:
        //constructor
        hangman(bool);
 
        //methods
       
        void inputGuesses(); // asks the user to input amount of guesses allowed
        void inputWordSize(); // asked the user to input the word size they want
        void dashX(); // makes a string of dashes of the same length the user inputted
        void readFile(); // read the dictionary file
        void difficulty(); // based on the word size it sorts the dictionary into a smaller vector
        string random(); // randomly selects a word from the now smaller vector
        void mainGame(); // prompts the user to input char guesses until they get the word or run out of guesses
 
        void ending();          //print statement declaring win or loss at the end
 
 
        //instance variables
        int guesses; //how many guesses the user has left
        int wordSize; //the size of the word they are guessing
        char userGuess; // the char input for each letter guessed
        string currentWord; //the string to be checked against, will change as needed
        string dashWord; // a string of length wordSize filling as - initially
        string usedLetters; // a string which keeps track of all user char inputs
 
        vector<string> vecsVector; // holds the entire dictionary file
        vector<string> sliceVector; // holds the reduced dictionary file
       
        bool debug;
};