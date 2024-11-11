#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    int n, q; cin >> n >> q;
    int haybales[n];
    for (int i = 0; i < n; i++)
    {
        cin >> haybales[i];
    }
    // sorting for using bounds properly
    sort(haybales, haybales+n);
    for (int i = 0; i < q; i++)
    {
        int a, b; cin >> a >> b;
        // find the position of each. use index of lower bound e.g. you want the 3rd haybale bc it fits in the range and the 5th haybale is the last that fits in the range so 3 in range in total.
        int first = lower_bound(haybales, haybales+n, a) - haybales; // take distance from beginning
        int second = upper_bound(haybales, haybales+n, b) - haybales; // first one out of range that we exclude but also nicely does the inclusive +1 thing
        cout << second-first << '\n';

    }
    
    

}