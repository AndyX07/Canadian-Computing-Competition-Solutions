#include <bits/stdc++.h>

using namespace std;

bool visited[9][9];
int m[9][9];
int p[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

bool valid(int a, int b){
    if(a >0 && b > 0 && a <= 8 && b <= 8){
        return true;
    }
    else{
        return false;
    }
}

int d(int x, int y, int x1, int y1)
{
    memset(visited, 0, sizeof(visited));
    priority_queue<pair<int, pair<int, int>>> pq;
    memset(m, -1, sizeof(m));
    m[x][y] = 0;
    pq.push({0, {x, y}});
    while(!pq.empty()){
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();
        if(visited[a][b]) continue;
        else if(a == x1 && b == y1){
            return m[a][b];
        }
        else{
            visited[a][b] = true;
            for(int i = 0; i < 8; i++){
                    int a1 = a+p[i][0], b1 = b+p[i][1];
                    if(valid(a1, b1)){
                        if(m[a][b]+1 < m[a1][b1] || m[a1][b1] == -1){
                            m[a1][b1] = m[a][b]+1;
                            pq.push({-m[a1][b1], {a1, b1}});
                        }
                    }
                }
            }
        }
    }

int main()
{
    int x, y, x1, y1;
    cin >> x >> y >> x1 >> y1;
    cout << d(x, y, x1, y1) << endl;
    return 0;
}
