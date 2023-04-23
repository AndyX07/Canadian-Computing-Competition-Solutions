#include <bits/stdc++.h>

using namespace std;

long long n, c;
vector<long long> psum;
vector<long long> v;

long long s(int a, int b){
    if(b>=a){
        return (psum[b+1]-psum[a]);
    }
    else{
        return (psum[c]-psum[a]+psum[b+1]);
    }
}

int main()
{
    cin >> n >> c;
    long long t=n*(n-1)*(n-2)/6;
    psum=vector<long long>(c+1, 0);
    v=vector<long long>(c, 0);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v[a]++;
    }
    for(int i = 0; i < c; i++){
        if(i==0){
            psum[i+1]=v[i];
        }
        else{
            psum[i+1]=psum[i]+v[i];
        }
    }
    for(int i = 0; i < c; i++){
        int j=(i+c/2)%c;
        long long k=s(i+1, j);
        //cout << i << " " << j << " " << k << endl;
        if(v[i]>=1){
            t-=(v[i]*((k*(k-1))/2));
        }
        if(v[i]>=2){
            t-=(v[i]*(v[i]-1)/2)*k;
        }
        if(v[i]>=3){
            t-=(v[i]*(v[i]-1)*(v[i]-2))/6;
        }
        if(c%2==0){
            if(j<i){
                t+=(v[i]*(v[i]-1)/2)*v[j];
                t+=(v[j]*(v[j]-1)/2)*v[i];
            }
        }
    }
    cout << t << endl;
    return 0;
}
