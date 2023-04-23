#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s){
    string s1 = s;
    reverse(s.begin(), s.end());
    if(strcmp(s.c_str(), s1.c_str()) == 0){
        return true;
    }
    return false;
}

int main()
{
    string s;
    getline(cin, s);
    for(int i = s.size(); i >= 1; i--){
        for(int j = 0; j <= s.size()-i; j++){
            string s1 = s.substr(j, i);
            if(isPalindrome(s1)){
                cout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}
