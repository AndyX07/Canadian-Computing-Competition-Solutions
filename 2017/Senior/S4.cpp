#include <bits/stdc++.h>

using namespace std;

int l[100001];
int s[100001];

struct vector_sort{
    bool operator()(vector<int> v1, vector<int> v2){
        if(v1[0]<v2[0])return true;
        else if(v1[0]==v2[0]){
            return v1[3]<v2[3];
        }
        return false;
    }
};

int find_p(int x){
    while(x!=l[x]){
        x=l[x];
    }
    return x;
}

int main()
{
    int n, m, d;
    cin >> n >> m >> d;
    for(int i=1; i<=n; i++){
        l[i]=i;
        s[i]=1;
    }
    vector<vector<int>> v;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, a, b, i});
    }
    sort(v.begin(), v.end(), vector_sort());
    int t=0;
    int cur;
    for(int i = 0; i < v.size(); i++){
        int a=find_p(v[i][1]), b=find_p(v[i][2]), c=v[i][3];
        if(a!=b){
            if(c>=n-1){
                t++;
            }
            if(s[a]<s[b])swap(a, b);
            l[b]=a;
            s[a]+=s[b];
            cur=i;
        }
    }
    for(int i=1; i<=n; i++){
        s[i]=1;
        l[i]=i;
    }
    for(auto x :v){
        int a=find_p(x[1]), b=find_p(x[2]);
        if(a!=b){
            if(x[3]<n-1&&x[0]<=v[cur][0]){
                if(s[a]<s[b])swap(a, b);
                l[b]=a;
                s[a]+=s[b];
            }
            else if(x[0]<v[cur][0]){
                if(s[a]<s[b])swap(a, b);
                l[b]=a;
                s[a]+=s[b];
            }
            else if(x[3]<n-1&&x[0]-d<=0){
                t--;
                break;
            }
        }
    }
    cout << t << endl;
    return 0;
}
