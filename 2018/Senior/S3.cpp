#include <bits/stdc++.h>

using namespace std;

int n, m;
char g[102][102];
bool camera[102][102];

bool valid(int x, int y){
    if(g[x][y]!='W'&&g[x][y]!='C'&&!camera[x][y]){
        return true;
    }
    return false;
}

int main()
{
    cin >> n >> m;
    int d[n][m];
    vector<pair<int, int>> p={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    memset(d, -1, sizeof(d));
    memset(camera, 0, sizeof(camera));
    vector<pair<int, int>> cameras;
    vector<pair<int, int>> cells;
    int x, y;
    for(int i = 0; i < n; i++){
        for(int j=0; j < m; j++){
            char c;
            cin >> c;
            if(c=='C')cameras.push_back({i, j});
            else if(c=='.')cells.push_back({i, j});
            else if(c=='S')x=i, y=j;
            g[i][j]=c;

        }
    }
    for(auto z:cameras){
        int x1=z.first, y1=z.second;
        for(int i=x1; i>0; i--){
            if(g[i][y1]=='.'||g[i][y1]=='S'){
                camera[i][y1]=1;
            }
            else if(g[i][y1]=='W'){
                break;
            }
        }
        for(int i=x1; i<n-1; i++){
            if(g[i][y1]=='.'||g[i][y1]=='S'){
                camera[i][y1]=1;
            }
            else if(g[i][y1]=='W'){
                break;
            }
        }
        for(int i=y1; i>0; i--){
            if(g[x1][i]=='.'||g[x1][i]=='S'){
                camera[x1][i]=1;
            }
            else if(g[x1][i]=='W'){
                break;
            }
        }
        for(int i=y1; i<m-1; i++){
            if(g[x1][i]=='.'||g[x1][i]=='S'){
                camera[x1][i]=1;
            }
            else if(g[x1][i]=='W'){
                break;
            }
        }
    }
    queue<pair<pair<int, int>, int>> q;
    q.push({{x, y}, 0});
    d[x][y]=0;
    while(!q.empty()){
        int x1=q.front().first.first;
        int y1=q.front().first.second;
        int w=q.front().second;
        q.pop();
        if(!valid(x1, y1)) continue;
        if(g[x1][y1]=='.'||g[x1][y1]=='S'){
            for(auto z:p){
                int x2=x1+z.first;
                int y2=y1+z.second;
                if(valid(x2, y2)){
                    if(d[x2][y2]==-1||w+1<d[x2][y2]){
                        d[x2][y2]=w+1;
                        q.push({{x2, y2}, w+1});
                        //cout << x2 << " " << y2 << endl;
                    }
                }
            }
        }
        else{
            //cout << x1 << " " << y1 << endl;
            if(g[x1][y1]=='D'){
                int x2=x1+1, y2=y1;
                if(valid(x2, y2)){
                    if(d[x2][y2]==-1||w<d[x2][y2]){
                        d[x2][y2]=w;
                        q.push({{x2, y2}, w});
                    }
                }
            }
            else if(g[x1][y1]=='U'){
                int x2=x1-1, y2=y1;
                if(valid(x2, y2)){
                    if(d[x2][y2]==-1||w<d[x2][y2]){
                        d[x2][y2]=w;
                        q.push({{x2, y2}, w});
                    }
                }
            }
            else if(g[x1][y1]=='R'){
                int x2=x1, y2=y1+1;
                if(valid(x2, y2)){
                    if(d[x2][y2]==-1||w<d[x2][y2]){
                        d[x2][y2]=w;
                        q.push({{x2, y2}, w});
                    }
                }
            }
            else if(g[x1][y1]=='L'){
                int x2=x1, y2=y1-1;
                if(valid(x2, y2)){
                    if(d[x2][y2]==-1||w<d[x2][y2]){
                        d[x2][y2]=w;
                        q.push({{x2, y2}, w});
                    }
                }
            }
        }
    }
    /*
    for(int i=0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(d[i][j]==-1){
                cout << "W" << " ";
            }
            else cout << "0" << " ";
        }
        cout << endl;
    }
    */
    for(auto z:cells){
        cout << d[z.first][z.second] << endl;
    }
    return 0;
}
