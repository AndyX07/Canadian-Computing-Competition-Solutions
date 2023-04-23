#include <bits/stdc++.h>

using namespace std;

int main()
{
    int dp[4001];
    memset(dp, 0, sizeof(dp));
    int ctr[2001];
    memset(ctr, 0, sizeof(ctr));
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        ctr[a]++;
    }
    for(int i=1; i<= 2000; i++){
        for(int j=i; j<=2000; j++){
            if(i==j&&ctr[i]>=2){
                dp[i+j]+=ctr[i]/2;
            }
            else if(i!=j && ctr[i]>0 && ctr[j]>0){
                dp[i+j]+=min(ctr[i], ctr[j]);
            }
        }
    }
    int t=0, l=0;
    for(int i=0; i <= 4000; i++){
        if(dp[i]>l){
            l=dp[i];
            t=1;
        }
        else if(dp[i]==l){
            t++;
        }
    }
    cout << l << " " << t << endl;
    return 0;
}
