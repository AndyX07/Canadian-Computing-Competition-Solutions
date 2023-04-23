#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    bool merged[n][n];
    memset(merged, 0, sizeof(merged));
    int v[n];
    int psum[n+1];
    psum[0]=0;
    int m=INT_MIN;
    for(int i=0; i<n; i++){
        cin>>v[i];
        if(i==0)psum[i+1]=v[i];
        else{
            psum[i+1]=psum[i]+v[i];
        }
    }
    for(int j=0; j<n; j++){
        for(int i=0; i+j<n; i++){
            int k=i+j;
            if(i==k){
                merged[i][k]=1;
                dp[i][k]=v[i];
            }
            else{
                if(j==1){
                    if(v[i]==v[k]){
                        merged[i][k]=1;
                        dp[i][k]=v[i]+v[k];
                    }
                }
                else{
                    /*
                    int l=i, r=k;
                    while(l<r){
                        int s1=psum[l+1]-psum[i];
                        int s2=psum[k+1]-psum[r];
                        if(s1==s2&&merged[l+1][r-1]&&merged[i][l]&&merged[r][k]){
                            merged[i][k]=1;
                            dp[i][k]=max(dp[i][k], psum[k+1]-psum[i]);
                        }
                        if(s1==s2&& l+1==r&&merged[i][l]&&merged[r][k]){
                            merged[i][k]=1;
                            dp[i][k]=max(dp[i][k], psum[k+1]-psum[i]);
                        }
                        if(s1>s2){
                            r--;
                        }
                        else{
                            l++;
                        }
                    }
                    */
                    for(int l=i; l<n; l++){
                        for(int x=1; x+l<n; x++){
                            int r=l+x;
                            int s1=psum[l+1]-psum[i];
                            int s2=psum[k+1]-psum[r];
                            if(s1==s2&&merged[l+1][r-1]&&merged[i][l]&&merged[r][k]){
                                merged[i][k]=1;
                                dp[i][k]=max(dp[i][k], psum[k+1]-psum[i]);
                            }
                            if(s1==s2&& l+1==r&&merged[i][l]&&merged[r][k]){
                                merged[i][k]=1;
                                dp[i][k]=max(dp[i][k], psum[k+1]-psum[i]);
                            }
                        }
                    }
                }
            }
            m=max(m, dp[i][k]);
        }
    }
    /*
    for(int i=0; i < n; i++){
        for(int j=0; j<n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=0; i < n; i++){
        for(int j=0; j<n; j++){
            cout << merged[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << m << endl;
    return 0;
}
