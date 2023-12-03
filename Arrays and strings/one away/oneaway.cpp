/*One Away: There are three types of edits that can be performed on strings: insert a character, 
remove a character, or replace a character. Given two strings, write a function to check if they are 
one edit (or zero edits) away. 
EXAMPLE 
pale, ple -> true 
pales, pale -> true 
pale, bale -> true 
pale, bae -> false*/

#include <iostream>
#include <string>

using namespace std;

bool oneEditReplace(const string& s1, const string& s2) {
    bool foundDifference = false;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            if (foundDifference) {
                return false;
            }
            foundDifference = true;
        }
    }
    return true;
}

bool oneEditInsert(const string& s1, const string& s2) {
    int index1 = 0;
    int index2 = 0;
    while (index2 < s2.length() && index1 < s1.length()) {
        if (s1[index1] != s2[index2]) {
            if (index1 != index2) {
                return false;
            }
            index2++;
        } else {
            index1++;
            index2++;
        }
    }
    return true;
}

bool oneEditAway(const string& first, const string& second) {
    if (first.length() == second.length()) {
        return oneEditReplace(first, second);
    } else if (first.length() + 1 == second.length()) {
        return oneEditInsert(first, second);
    } else if (first.length() - 1 == second.length()) {
        return oneEditInsert(second, first);
    }
    return false;
}

int main() {
    string s1 = "pale";
    string s2 = "ple";

    if (oneEditAway(s1, s2)) {
        cout << "One edit away" << endl;
    } else {
        cout << "Not one edit away" << endl;
    }

    return 0;
}
