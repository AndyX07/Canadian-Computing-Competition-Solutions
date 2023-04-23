#include <bits/stdc++.h>

using namespace std;

int h;
int k;
vector<int> v;
int low;
int hi;
int mid;

int possible(int x){
    int ans = INT_MAX;
    for(int i = 0; i < h; i++){
        int ctr = 1;
        int m = v[i]+2*x;
        for(int j = i+1; j < i+h; j++){
            if(v[j]>m){
                ctr++;
                m=v[j]+2*x;
            }
        }
        ans=min(ans, ctr);
    }
    return ans;
}

int main()
{
    cin >> h;
    for(int i = 0; i < h; i++){
        int a;
        cin >> a;
        v.push_back(a);
        v.push_back(a+1000000);
    }
    sort(v.begin(), v.end());
    cin >> k;
    low=0;
    hi=1000000;
    mid = (low+hi)/2;
    while(low<hi){
        if(possible(mid)<=k){
            hi=mid;
        }
        else{
            low=mid+1;
        }
        mid = (low+hi)/2;
        //cout << low << " " << hi << endl;
    }
    cout << mid << endl;
    return 0;
}
