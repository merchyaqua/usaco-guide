#include <bits/stdc++.h>

using namespace std;
/* main thing: learned to code for negative modulo. */
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    // long long divsum[n+1]{};
    long long ans = 0;
    map<long long, long long> modded;
    modded[0] = 1;
    long long psum = 0;
    for (int i = 0; i < n; i++)
    {
        int thing; cin >> thing;
        psum += thing;
        long long m = ((psum) % n + n) % n;
        // cout << psum << ' ' <<  m << endl;

        ans += modded[m];
        modded[m] ++;
    }
    cout << ans;
    


}