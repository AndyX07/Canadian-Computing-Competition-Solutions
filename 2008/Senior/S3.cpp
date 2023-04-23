#include <bits/stdc++.h>

using namespace std;

char g[20][20];
int r, c;

bool valid(int x, int y){
    if(x>=0&&y>=0&&x<r&&y<c&&g[x][y]!='*'){
        return true;
    }
    return false;
}

int bfs(){
    bool visited[r][c];
    memset(visited, 0, sizeof(visited));
    queue<pair<int, pair<int, int>>> q;
    q.push({1, {0, 0}});
    vector<pair<int, int>> v={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(!q.empty()){
        int w=q.front().first;
        int x=q.front().second.first;
        int y=q.front().second.second;
        q.pop();
        if(visited[x][y])continue;
        visited[x][y]=1;
        if(x==r-1&&y==c-1)return w;
        if(g[x][y]=='+')v={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        else if(g[x][y]=='|') v={{1, 0}, {-1, 0}};
        else if(g[x][y]=='-')v={{0, 1}, {0, -1}};
        for(auto a : v){
            int x1=x+a.first;
            int y1=y+a.second;
            if(valid(x1, y1)&&visited[x1][y1]==0){
                q.push({w+1, {x1, y1}});
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> r >> c;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> g[i][j];
            }
        }
        cout << bfs() << endl;
    }
    return 0;
}
