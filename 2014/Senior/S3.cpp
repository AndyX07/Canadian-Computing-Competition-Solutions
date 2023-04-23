#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> pos(n);
        for(int i = n-1; i >= 0; i--){
            cin >> pos[i];
        }
        stack<int> branch;
        int lake = -1;
        bool b = false;
        for(auto x : pos){
            int a = x;
            if(lake == -1){
                if(a != 1){
                    if(branch.empty()){
                        branch.push(a);
                    }
                    else if(!branch.empty()){
                        if(branch.top() > a){
                            branch.push(a);
                        }
                        else{
                            cout << "N" << endl;
                            b = true;
                            break;
                        }
                    }
                }
                else{
                    lake = a;
                }
            }
            else{
                while(!branch.empty() && branch.top() == lake+1){
                    lake = branch.top();
                    branch.pop();
                }
                if(a == lake+1){
                    lake = a;
                }
                else{
                    if(!branch.empty() && branch.top() > a){
                        branch.push(a);
                    }
                    else if(branch.empty()){
                        branch.push(a);
                    }
                    else{
                        cout << "N" << endl;
                        b = true;
                        break;
                    }
                }
            }
        }
        if(!b){
            cout << "Y" << endl;
        }
    }
    return 0;
}
