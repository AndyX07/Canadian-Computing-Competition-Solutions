#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int l = count(s.begin(), s.end(), 'L');
    int m = count(s.begin(), s.end(), 'M');
    string lsub = s.substr(0, l);
    string msub = s.substr(l, m);
    string ssub = s.substr(l+m);
    int nl = lsub.size()-count(lsub.begin(), lsub.end(), 'L');
    int nm = msub.size()-count(msub.begin(), msub.end(), 'M');
    int t = nl + nm;
    t-=min(count(lsub.begin(), lsub.end(), 'M'), count(msub.begin(), msub.end(), 'L'));
    cout << t << endl;
    return 0;
}
