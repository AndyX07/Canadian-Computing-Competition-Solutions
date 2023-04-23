#include <bits/stdc++.h>

using namespace std;

int n;
int dp[3002][2][101][101];
vector<int> a;
vector<int> b1;

int recursion(int cur, int b, int x, int y){
    if(dp[cur][b][x][y]!=0)return dp[cur][b][x][y];
    if(cur==n){
        if(b==1){
            if(x<=y){
                //pick b
                dp[cur][b][x][y]=b1[y]+recursion(cur, 0, x, y-1);
            }
        }
        else{
            //skip b
            if(x<=y){
                dp[cur][b][x][y]=recursion(cur, 1, x+1, y);
            }
        }
        return dp[cur][b][x][y];
    }
    if(b==1){
        dp[cur][b][x][y]=max(a[cur]+recursion(cur+1, 0, x, y), recursion(cur, 0, x, y));
        if(x<=y){
            //pick b
            dp[cur][b][x][y]=max(dp[cur][b][x][y], b1[y]+recursion(cur, 0, x, y-1));
        }
    }
    else{
        //skip a
        dp[cur][b][x][y]=max(dp[cur][b][x][y], recursion(cur+1, 1, x, y));
        if(x<=y){
            //skip b
            dp[cur][b][x][y]=max(dp[cur][b][x][y], recursion(cur, 1, x+1, y));
        }
    }
    //cout << dp[cur][b][x][y] << endl;
    return dp[cur][b][x][y];
}

int main()
{
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        a.push_back(t);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        b1.push_back(t);
    }
    sort(b1.begin(), b1.end());
    cout << recursion(0, 1, 0, m-1) << endl;
    return 0;
}
