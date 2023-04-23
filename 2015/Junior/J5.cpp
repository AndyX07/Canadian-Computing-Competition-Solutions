#include <bits/stdc++.h>

using namespace std;

int visited[251][251][251];
int counter = 0;

//pi(n, k, m) = sum of all possible(pi(n - c, k - 1, c)) where c between m to floor(n/k)

int pi(int n, int k, int m){
    if(visited[n][k][m] != 0){
        return visited[n][k][m];
    }
    else{
        if(n == k || k == 1){
            //cout << "solution reached" << endl;
            visited[n][k][m] = 1;
        }
        else{
            for(int i = m; i <= floor(n/k); i++){
                visited[n][k][m]+=pi(n-i, k-1, i);
            }
        }
    }
    return visited[n][k][m];
}

int main()
{
    memset(visited, 0, sizeof(visited));
    int n, k;
    cin >> n >> k;
    cout << pi(n, k, 1) << endl;
}
