#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<char> v;
    vector<string> v1;
    char c;
    string s;
    while(true){
        cin >> c;
        cin >> s;
        v.push_back(c);
        if(strcmp(s.c_str(), "SCHOOL") != 0){
            v1.push_back(s);
        }
        else{
            break;
        }
    }
    reverse(v1.begin(), v1.end());
    reverse(v.begin(), v.end());
    for(int i = 0; i < v1.size(); i++){
        if(v[i] == 'R'){
            cout << "Turn LEFT onto "<< v1[i]<< " street." << endl;
        }
        else{
            cout << "Turn RIGHT onto "<<v1[i]<<" street." << endl;
        }
    }
    if(v[v.size()-1] == 'R'){
        cout << "Turn LEFT into your HOME." << endl;
    }
    else{
        cout << "Turn RIGHT into your HOME." << endl;
    }
    return 0;
}
