#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> v;
vector<int> st;

void b(int node, int l, int r){
    if(l==r){
        st[node]=v[l];
        //cout << "!" << v[l] << " " << st[node] << endl;
    }
    else{
        int m = (l+r)/2;
        b(node*2, l, m);
        b(node*2+1, m+1, r);
        st[node]=max(st[node*2], st[node*2+1]);
    }
}

int m(int node, int l, int r, int x, int y){
    if(x<=l&&y>=r){
        return st[node];
    }
    int t = 0;
    int mid = (l+r)/2;
    if(x<=mid){
        t=max(t, m(2*node, l, mid, x, y));
    }
    if(y>mid){
        t=max(t, m(2*node+1, mid+1, r, x, y));
    }
    return t;
}

int main()
{
    cin >> n >> k;
    v=vector<int>(n);
    st=vector<int>(4*n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    b(1, 0, n-1);
    long long dp[n+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= k; i++){
        dp[i]=m(1, 0, n-1, 0, i-1);
        //cout << i << " " << dp[i] << endl;
    }
    for(int i = k+1; i <= n; i++){
        int t = i%k;
        if(t==0){
            dp[i]=dp[i-k]+m(1, 0, n-1, i-k, i-1);
        }
        else{
            for(int j = t; j <= k; j++){
                dp[i]=max(dp[i], dp[i-j]+m(1, 0, n-1, i-j, i-1));
            }
        }
        //cout << i << " " << dp[i] << " " << m(1, 0, n-1, i-t, i-1) << " " << m(1, 0, n-1, i-k, i-1)<< endl;
    }
    cout << dp[n] << endl;
    return 0;
}
