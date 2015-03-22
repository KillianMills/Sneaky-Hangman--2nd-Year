#include <string>
#include <vector>
#include <map>
 
using namespace std;
 
class sneaky
{
public:
        //methods
        string keyMaker(string, char); // makes a unique key based on the occurence of the user's guess
        map<string, vector<string> > mapMaker(vector<string>& , char);
        void debugger(int, bool);
        void makeFamily(vector<string>& , char, bool); // sorts the vector into seperate vectors based on character
       
        //instance variables
        string temp; // temp string for holding word being checked
        //bool debug;
};