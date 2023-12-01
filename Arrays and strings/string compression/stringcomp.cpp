/*String Compression: Implement a method to perform basic string compression using the counts 
of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the 
"compressed" string would not become smaller than the original string, your method should return 
the original string. You can assume the string has only uppercase and lowercase letters (a - z). 
*/

#include <iostream>
#include <string>

using namespace std;

string compressBad(const string& str) {
    string compressedString = "";
    int countConsecutive = 0;

    for (int i = 0; i < str.length(); i++) {
        countConsecutive++;

        // If the next character is different than the current, append this character to the result.
        if (i + 1 >= str.length() || str[i] != str[i + 1]) {
            compressedString += str[i] + to_string(countConsecutive);
            countConsecutive = 0;
        }
    }

    return compressedString.length() < str.length() ? compressedString : str;
}

int main() {
    string input = "aabcccccaaa";
    string compressed = compressBad(input);
    cout << "Compressed String: " << compressed << endl;

    return 0;
}
