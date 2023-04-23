#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    long long v[n];
    //vector<int> recent(n+1, -1);
    //recent[0]=1;
    v[0]=1;
    k--;
    long long prev=1;
    long long c=0;
    for(int i = 1; i < n; i++){
        c++;
        int x = n-i-1;
        if(x>k) break;
        if(x==k){
            v[i]=prev;
            k--;
        }
        else{
            if(min(k-x, m)>i){
                //cout << "a" << endl;
                v[i]=min(i+1, (int)m);
                //cout << k << " " << i+1 << endl;
                k-=min(i+1,(int)m);
                //recent[i]=v[i];
            }
            else{
                if(k-x>m){
                    //cout << "b" << endl;
                    v[i]=v[i-m];
                    k-=m;
                }
                else{
                    //cout << "c" << endl;
                    v[i]=v[i-(k-x)];
                    //cout << k << " " << k-x << endl;
                    k-=(k-x);
                    //recent[i]=recent[i-(k-x)];
                }
            }
        }
        //cout << k << endl;
        prev=v[i];
    }
    if(k==0&&c==n-1){
        for(int i = 0; i < n; i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << "-1" << endl;
    }
    return 0;
}
