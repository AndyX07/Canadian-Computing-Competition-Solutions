#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    double dp[n];
    dp[n-1]=0;
    vector<int> last(500001);
    int v[n];
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        last[a]=i;
        v[i]=a;
    }
    if(v[0]==v[n-1]){
        cout << 1 << endl;
    }
    else{
        double ans=0;
        for(int i = n-2; i >= 1; i--){
            if(v[i]==v[0]){
                dp[i]=1;
            }
            else if(last[v[i]]!=i){
                dp[i]=dp[last[v[i]]];
            }
            else{
                dp[i]=(ans+1)/((double)n-i);
            }
            ans+=dp[i];
        }
        cout << (ans+1)/(double)n << endl;
    }
    return 0;
}
