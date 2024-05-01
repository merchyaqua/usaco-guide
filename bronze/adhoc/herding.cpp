#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    // distance between 1st and 2nd -1 and the 2nd3rd-1 = number of steps, min and max.
    int f[3];
    cin >>f[0]>>f[1]>>f[2];
    sort(f, f+3);
    int d,c;
    d = f[1]-f[0]-1;
    c = f[2]-f[1]-1;
    if (d == 0) d = c;
    if (c == 0) c = d;
    auto hm = min(d,c);

    cout << min(hm, 2) << '\n' << max(d,c);

}