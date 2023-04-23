#include <bits/stdc++.h>

using namespace std;

int adj[50][50];

int d(int x, int y){
    bool visited[50];
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({x, 0});
    while(!q.empty()){
        int a = q.front().first;
        int w = q.front().second;
        q.pop();
        if(a==y) return w;
        if(visited[a])continue;
        visited[a]=1;
        for(int i = 0; i < 50; i++){
            if(adj[a][i]&&visited[i]==0){
                q.push({i, w+1});
            }
        }
    }
    return -1;
}

set<int> f(int x){
    set<int> s;
    for(int i = 0; i < 50; i++){
        if(adj[x][i]){
            s.insert(i);
        }
    }
    return s;
}

int main()
{
    char c;
    memset(adj, 0, sizeof(adj));
    adj[1][6] = 1;
	adj[6][1] = 1;
	adj[2][6] = 1;
	adj[6][2] = 1;
	adj[3][6] = 1;
	adj[6][3] = 1;
	adj[4][6] = 1;
	adj[6][4] = 1;
	adj[5][6] = 1;
	adj[6][5] = 1;
	adj[7][6] = 1;
	adj[6][7] = 1;
	adj[3][4] = 1;
	adj[4][3] = 1;
	adj[4][5] = 1;
	adj[5][4] = 1;
	adj[3][5] = 1;
	adj[5][3] = 1;
	adj[3][15] = 1;
	adj[15][3] = 1;
	adj[13][15] = 1;
	adj[15][13] = 1;
	adj[14][13] = 1;
	adj[13][14] = 1;
	adj[12][13] = 1;
	adj[13][12] = 1;
	adj[7][8] = 1;
	adj[8][7] = 1;
	adj[8][9] = 1;
	adj[9][8] = 1;
	adj[9][10] = 1;
	adj[10][9] = 1;
	adj[9][12] = 1;
	adj[12][9] = 1;
	adj[10][11] = 1;
	adj[11][10] = 1;
	adj[11][12] = 1;
	adj[12][11] = 1;
	adj[16][17] = 1;
	adj[17][16] = 1;
	adj[16][18] = 1;
	adj[18][16] = 1;
	adj[18][17] = 1;
	adj[17][18] = 1;
    while(cin >> c && c!='q'){
        int x, y;
        if(c=='i'){
            cin >> x >> y;
            adj[x][y]=1;
            adj[y][x]=1;
        }
        else if(c=='d'){
            cin >> x >> y;
            adj[x][y]=0;
            adj[y][x]=0;
        }
        else if(c=='n'){
            cin >> x;
            //cout << "<<";
            cout << f(x).size() << endl;
        }
        else if(c=='f'){
            cin >> x;
            set<int> s=f(x);
            set<int> n;
            for(auto a : s){
                set<int> t = f(a);
                for(auto b : t){
                    //cout << b << " ";
                    if(adj[x][b]==0&&b!=x){
                        n.insert(b);
                    }
                }
            }
            //cout << "<<";
            cout << n.size() << endl;
        }
        else if(c=='s'){
            cin >> x >> y;
            int t=d(x, y);
            //cout << "<<";
            if(t==-1){
                cout << "Not connected" << endl;
            }
            else{
                cout << t << endl;
            }
        }
    }
    return 0;
}
