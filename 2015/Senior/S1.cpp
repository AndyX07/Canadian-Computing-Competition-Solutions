#include <bits/stdc++.h>

using namespace std;

int main()
{
    deque<int> dq;
    int k, t=0;
    cin >> k;
    for(int i=0; i<k; i++){
        int a;
        cin >> a;
        if(a==0){
            t-=dq.back();
            dq.pop_back();
        }
        else{
            t+=a;
            dq.push_back(a);
        }
    }
    cout << t << endl;
    return 0;
}
