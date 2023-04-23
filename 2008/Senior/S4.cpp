#include <bits/stdc++.h>

using namespace std;

int best = 0;

void g(vector<int> v, int s){
    if(s==1){
        if(v[0]<=24&&v[0]>best){
            best=v[0];
        }
        return;
    }
    for(int i = 0; i < s; i++){
        for(int j = i+1; j < s; j++){
            //cout << i << " " << j << " " << s << endl;
            vector<int> v1(s-1);
            int t = 0;
            for(int k = 0; k < s; k++){
                if(k!=i&&k!=j){
                    v1[t]=(v[k]);
                    t++;
                }
            }
            int a=v[i], b=v[j];
            v1[s-2]=a+b;
            g(v1, s-1);

            v1[s-2]=a-b;
            g(v1, s-1);
            v1[s-2]=b-a;
            g(v1, s-1);

            v1[s-2]=a*b;
            g(v1, s-1);

            if(b!=0&&a%b==0){
                v1[s-2]=(a/b);
                g(v1, s-1);
            }
            else if(a!=0&&b%a==0){
                v1[s-2]=(b/a);
                g(v1, s-1);
            }

        }
    }
}

int main()
{
    int n;
    cin >> n;
    while(n--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g({a,b,c,d}, 4);
        cout << best << endl;
        best=0;
    }
    return 0;
}
