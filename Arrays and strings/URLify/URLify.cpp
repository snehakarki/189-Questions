/*: Write a method to replace all spaces in a string with '%20'. You may assume that the string 
has sufficient space at the end to hold the additional characters, and that you are given the "true" 
length of the string. 
EXAMPLE 
Input: "Mr John Smith ", 13 
Output: "Mr%20John%20Smith" 
Testing commit
*/


#include <iostream>
using namespace std;

void replaced(string &s, int trueLength) { // Use a reference to modify the original string
    int space = 0, index = 0;
    for (int i = 0; i < trueLength; i++) {
        if (s[i] == ' ') {
            space++;
        }
    }

    index = trueLength + space * 2; 
    //if(trueLength<s.length()){s[trueLength]='\0'}// Each space is replaced with three characters
    for (int i = trueLength - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            s[index - 1] = '0';
            s[index - 2] = '2';
            s[index - 3] = '%';
            index -= 3;
        } else {
            s[index - 1] = s[i];
            index--;
        }
    }
}

int main() {
    string s = "Mr John Smith    "; // Extra spaces at the end
    int trueLength = 13; // Length of the actual string "Mr John Smith"

    replaced(s, trueLength);
    cout << "Modified string: " << s << endl;

    return 0;
}
