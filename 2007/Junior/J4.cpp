#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    string t1 = "";
    string t2 = "";
    stringstream ss(s1);
    char c;
    while(ss >> c){
        if(c != ' '){
            t1 += c;
        }
    }
    stringstream ss1(s2);
    while(ss1 >> c){
        if(c != ' '){
            t2 += c;
        }
    }
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    if(strcmp(t1.c_str(), t2.c_str()) == 0){
        cout << "Is an anagram." << endl;
    }
    else{
        cout << "Is not an anagram." << endl;
    }
    return 0;
}
