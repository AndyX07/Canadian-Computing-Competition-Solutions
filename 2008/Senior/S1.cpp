#include <bits/stdc++.h>

using namespace std;

int main()
{
    string coldest;
    int best = INT_MAX;
    string city;
    int temp;
    while(cin >> city >> temp && city!="Waterloo"){
        if(temp<best){
            best=temp;
            coldest=city;
        }
    }
    if(temp<best){
        best=temp;
        coldest=city;
    }
    cout << coldest << endl;
    return 0;
}
