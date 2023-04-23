#include <bits/stdc++.h>

using namespace std;

int w = 0;
int total = 0;
vector<vector<int>> possible = {{3, 0}, {0, 3}, {1, 1}};

void play(vector<pair<int, int>> p, vector<int> scores, int t){
    if(p.size()==0){
        /*
        for(auto x : scores){
            cout << x << " ";
        }
        cout << endl;
        total++;
        */
        auto m = max_element(scores.begin(), scores.end());
        if(m - scores.begin() == t && count(scores.begin(), scores.end(), *m) == 1){
            w++;
        }
        return;
    }
    int a = p[0].first;
    int b = p[0].second;
    p.erase(p.begin());
    vector<int> cpy = scores;
    for(int i = 0; i < 3; i++){
        scores = cpy;
        scores[a]+=possible[i][0];
        scores[b]+=possible[i][1];
        play(p, scores, t);
    }
}

int main()
{
    int t;
    cin >> t;
    int g;
    cin >> g;
    vector<int> scores(5, 0);
    vector<pair<int, int>> p;
    for(int i = 1; i <= 4; i++){
        for(int j = i+1; j <= 4; j++){
            p.push_back({i, j});
        }
    }
    /*
    for(auto x : p){
        cout << x.first << " " << x.second << endl;
    }
    */
    for(int i = 0; i < g; i++){
        int a, b, sa, sb;
        cin >> a >> b >> sa >> sb;
        p.erase(find(p.begin(), p.end(), make_pair(a, b)));
        if(sa > sb){
            scores[a]+=3;
        }
        else if(sb > sa){
            scores[b]+=3;
        }
        else{
            scores[a]++;
            scores[b]++;
        }
    }
    /*
    for(auto x : scores){
        cout << x << " ";
    }
    */
    //cout << endl;
    play(p, scores, t);
    //cout << total << endl;
    cout << w << endl;
    return 0;
}
