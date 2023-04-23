#include <bits/stdc++.h>

using namespace std;

int a=0, b=0, c=0, n;

int compute(string s){
    int ans = INT_MAX;
    int aa=0, ab=0, ac=0, ba=0, bb=0, bc=0, ca=0, cb=0, cc=0;
    for(int i = 0; i < a; i++){
        if(s[i]=='A')aa++;
        else if(s[i]=='B')ab++;
        else ac++;
    }
    for(int i = a; i < a+b; i++){
        if(s[i]=='A')ba++;
        else if(s[i]=='B')bb++;
        else bc++;
    }
    for(int i = a+b; i < a+b+c; i++){
        if(s[i]=='A')ca++;
        else if(s[i]=='B')cb++;
        else cc++;
    }
    for(int i = 0; i < n; i++){
        int x = (i+a)%n;
        int y = (i+a+b)%n;
        int z = (i+a+b+c)%n;
        int temp = 0;
        int m = min(ab, ba);
        temp+=ab + ac + ba + bc - m;
        ans=min(temp, ans);
        if(s[i]=='A')aa--;
        else if(s[i]=='B')ab--;
        else ac--;
        if(s[x]=='A'){
            aa++;
            ba--;
        }
        else if(s[x]=='B'){
            ab++;
            bb--;
        }
        else{
            ac++;
            bc--;
        }
        if(s[y]=='A'){
            ba++;
            ca--;
        }
        else if(s[y]=='B'){
            bb++;
            cb--;
        }
        else{
            bc++;
            cc--;
        }
        if(s[z]=='A')ca--;
        else if(s[z]=='B')cb--;
        else cc--;
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    n=s.size();
    for(char x : s){
        if(x=='A')a++;
        else if(x=='B')b++;
        else c++;
    }
    int m = compute(s);
    for(int i = 0; i < n; i++){
        if(s[i]=='A')s[i]='C';
        else if(s[i]=='C')s[i]='A';
    }
    swap(a, c);
    m=min(m, compute(s));
    cout << m << endl;
    return 0;
}
