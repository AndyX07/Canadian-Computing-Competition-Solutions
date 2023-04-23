#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    while(getline(cin, s) && s != "0"){
        stack<string> st;
        for(int i = s.size()-1; i >= 0; i--){
            char c = s[i];
            if(c == ' ') continue;
            if(c == '+' || c == '-'){
                string c1, c2;
                c1 = st.top();
                st.pop();
                c2 = st.top();
                st.pop();
                string temp = c1 + c2 + c;
                st.push(temp);
            }
            else{
                st.push(string(1, c));
            }
        }
        for(char c : st.top()){
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}
