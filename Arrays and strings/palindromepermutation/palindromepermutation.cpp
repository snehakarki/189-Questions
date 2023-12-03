/*Given a string, write a function to check if it is a permutation of 
a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A 
permutation is a rearrangement of letters. The palindrome does not need to be limited to just 
dictionary words. 
EXAMPLE 
Input: Tact Coa 
Output: True (permutations: "taco cat'; "atco eta·; etc.)*/


#include <iostream>
#include <vector>

bool isPermutationOfPalindrome(std::string phrase);
bool checkMaxOneOdd(std::vector<int>& table);
int getCharNumber(char c);
std::vector<int> buildCharFrequencyTable(std::string phrase);

bool isPermutationOfPalindrome(std::string phrase) {
    std::vector<int> table = buildCharFrequencyTable(phrase);
    return checkMaxOneOdd(table);
}

bool checkMaxOneOdd(std::vector<int>& table) {
    bool foundOdd = false;
    for (int count : table) {
        if (count % 2 == 1) {
            if (foundOdd) {
                return false;
            }
            foundOdd = true;
        }
    }
    return true;
}

int getCharNumber(char c) {
    int a = 'a';
    int z = 'z';
    int val = c;
    if (a <= val && val <= z) {
        return val - a;
    }
    return -1;
}

std::vector<int> buildCharFrequencyTable(std::string phrase) {
    std::vector<int> table('z' - 'a' + 1, 0);
    for (char c : phrase) {
        int x = getCharNumber(c);
        if (x != -1) {
            table[x]++;
        }
    }
    return table;
}

int main() {
    std::string inputPhrase = "taco cat";
    bool result = isPermutationOfPalindrome(inputPhrase);
    if (result) {
        std::cout << "The phrase is a permutation of a palindrome." << std::endl;
    } else {
        std::cout << "The phrase is not a permutation of a palindrome." << std::endl;
    }
    return 0;
}
