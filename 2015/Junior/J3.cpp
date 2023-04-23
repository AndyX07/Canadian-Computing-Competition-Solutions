#include <bits/stdc++.h>

using namespace std;

int main()
{
    string vowel = "aeiou";
    vector<int> d(5);
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < 5; i++){
        d[i] = alphabet.find(vowel[i]);
    }
    string s;
    getline(cin, s);
    string ns = "";
    for(char c : s){
        auto x = vowel.find(c);
        ns+=c;
        if(x == string::npos){
            x = alphabet.find(c);
            int t;
            int m = 9999999;
            for(int i = 0; i < 5; i++){
                int t1 = x-d[i];
                if(t1 < 0){
                    t1*= (-1);
                }
                if(t1 < m){
                    m = t1;
                    t = i;
                }
            }
            ns+=vowel[t];
            if(x != 25){
                x++;
                while(vowel.find(alphabet[x]) != string::npos){
                    if(x == 25){
                        break;
                    }
                    x++;
                }
            }
            ns+=alphabet[x];
        }
    }
    cout << ns << endl;
    return 0;
}
