
/*Implement an algorithm to determine if a string has all unique characters, 
what if you cannot use additional data structure*/


#include <bits/stdc++.h>
using namespace std;

bool isunique(string s){
    if(s.length()>128){
        return false; 
    }

    vector<bool> char_set(128,false);
    for (int i = 0; i < s.length(); i++)
    {
        int val=s[i];
        if(char_set[val]){
            return false;
        }
        char_set[val]=true; 

    }
    return true;
    
}

int main(){
    string s;
    cin>>s;
    if(isunique(s)){
        cout<<"unique chaarcters"<<endl;

    }
    else{
        cout<<"not unique characters"<<endl;
    }
}

