#include <bits/stdc++.h>

using namespace std;

vector<int> stree;
vector<int> v;

void build(int node, int l, int r){
    if(l==r){
        stree[node]=v[l];
        return;
    }
    int m = (l+r)/2;
    build(2*node, l, m);
    build(2*node+1, m+1, r);
    stree[node]=__gcd(stree[2*node], stree[2*node+1]);
}

int f(int node, int l, int r, int x, int y){
    //cout << l << " " << r << " " << x << " " << y << endl;
    if(l>=x&&r<=y){
        return stree[node];
    }
    int m = (l+r)/2;
    int ans1 = 0, ans2 = 0;
    if(m>=x){
        ans1=f(2*node, l, m, x, y);
    }
    if(m<y){
        ans2=f(2*node+1, m+1, r, x, y);
    }
    if(ans1!=0&&ans2!=0){
        return __gcd(ans1, ans2);
    }
    else if(ans1==0&&ans2!=0){
        return ans2;
    }
    else if(ans1!=0&&ans2==0){
        return ans1;
    }
    else return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    stree.resize(4*n+1);
    v=vector<int>(n+1, 1);
    int diff[n+2][17];
    memset(diff, 0, sizeof(diff));
    vector<pair<pair<int, int>, int>> v1;
    for(int i = 0; i < m; i++){
        int a, b, z;
        cin >> a >> b >> z;
        diff[a][z]++;
        diff[b+1][z]--;
        v1.push_back({{a,b}, z});
    }
    for(int i=1; i <= 16; i++){
        for(int j = 1; j <= n; j++){
            diff[j][i]+=diff[j-1][i];
            if(diff[j][i]>0){
                v[j]=(v[j]*i)/(__gcd(v[j], i));
            }
        }
    }
    build(1, 1, n);
    for(auto x : v1){
        int a = x.first.first;
        int b = x.first.second;
        int z = x.second;
        if(f(1, 1, n, a, b)!=z){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
