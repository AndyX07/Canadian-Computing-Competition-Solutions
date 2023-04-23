#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    string alphabet = "0abcdefghijklmno";
    string alphabet1 = "0pqrs";
    string alphabet2 = "0tuv";
    string alphabet3 = "0wxyz";
    while(cin >> s && strcmp(s.c_str(), "halt") != 0){
        stringstream ss(s);
        int counter = 0;
        char c;
        int current = 0;
        while(ss >> c){
            auto x = alphabet.find(c);
            auto y = alphabet1.find(c);
            auto z = alphabet2.find(c);
            auto t = alphabet3.find(c);
            int temp;
            if(x != string::npos){
                temp = ceil((double)x/3);
                x %= 3;
                if(x == 0){
                    x = 3;
                }
                counter += x;
            }
            else if(y != string::npos){
                temp = 100;
                counter += y;
            }
            else if(z != string::npos){
                temp = 1000;
                counter += z;
            }
            else{
                temp = 10000;
                counter += t;
            }
            if(current == temp){
                counter+=2;
            }
            current = temp;
        }
        cout << counter << endl;
    }
    return 0;
}
