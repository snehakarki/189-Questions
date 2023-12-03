/* Given two strings, write a method to decide if one is a permutation of the 
other.
*/



/*Solution 1:*/

#include<bits/stdc++.h>
using namespace std;

bool ispermutation(string a, string b){
    if(a.length()!=b.length()){
        return false;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a!=b){
        return false;
    }
    return true;
}

int main(){

    string a, b;
    cin>>a>>b;
    if(ispermutation(a,b)){
        cout<<"it is a permutaion"<<endl;

    }
    else{
        cout<<"it it not a permutaion"<<endl;
    }

    return 0;
}

/*Solution 2:*/

/*we can say permutaion aslo means having two words with same chracter count*/

#include<bits/stdc++.h>
using namespace std;

bool ispermutation(string a, string b){
    if(a.length()!=b.length()){
        return false;
    }
    
    vector<int> letters(128,0); // we have assumed it to be ASCII, in case of UNICODE the size will be 65536

    //we'll start by counting letters in the first string

    for (int i = 0; i < a.length(); i++)
    {
        int c=(int) a[i];
        letters[c]++;
    }
    
    // now iterate through the next string and subtract as you keep encounetring the letters

    for (int i = 0; i < b.length(); i++)
    {
        int c=(int)b[i];
        letters[c]--;
        if(letters[c]<0){
            return false;
        }
    }

    return true;
    
}

int main(){

    string a, b;
    cin>>a>>b;
    if(ispermutation(a,b)){
        cout<<"it is a permutaion"<<endl;

    }
    else{
        cout<<"it it not a permutaion"<<endl;
    }

    return 0;
}