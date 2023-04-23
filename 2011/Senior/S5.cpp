#include <bits/stdc++.h>

using namespace std;

int k;

int f(int n){
    int t=0;
    for(int i = 0; i <= k; i++){
        if((n & (1<<i))==(1<<i)){
            t++;
        }
        else{
            if(t>=4){
                int temp=((1<<t)-1)<<(i-t);
                n=n^temp;
                return n;
            }
            else{
                t=0;
            }
        }
    }
    return n;
}

int bfs(int n){
    vector<bool> visited(1<<k, 0);
    queue<pair<int, int>> q;
    q.push({0, n});
    while(!q.empty()){
        int t=q.front().first;
        int x=q.front().second;
        q.pop();
        /*
        for(int i = k-1; i >=0; i--){
            if(x&(1<<i)) cout << "1";
            else cout << "0";
        }
        cout << endl;
        */
        if(x==0) return t;
        if(visited[x]) continue;
        visited[x]=1;
        for(int i = 0; i < k; i++){
            //cout << "!" << (x&(1<<i)) << endl;
            if((x&(1<<i))==0){
                int temp = x;
                temp=temp|(1<<i);
                /*
                for(int j = k-1; j >=0; j--){
                    if(temp&(1<<j)) cout << "1";
                    else cout << "0";
                }

                cout << endl;
                */
                temp=f(temp);
                if(!visited[temp]){
                    /*
                    for(int j = k-1; j >=0; j--){
                        if(temp&(1<<j)) cout << "1";
                        else cout << "0";
                    }
                    cout << endl;
                    */
                    //cout << "@" << endl;
                    q.push({t+1, temp});
                }
            }
        }
    }
}

int main(){
    cin >> k;
    int n=0;
    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        n<<=1;
        n=n|a;
    }
    cout << bfs(n) << endl;
    return 0;
}
