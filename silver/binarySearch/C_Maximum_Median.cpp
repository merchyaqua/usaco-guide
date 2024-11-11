#include <bits/stdc++.h>

using namespace std;


int last_true(int lo, int hi, function<bool(int)> f) {
    lo --; // why?
    while (lo < hi) {
        int mid = lo + (hi-lo+1)/2; // rounding up for the true middle
        // if search between 0 and 1 it keeps rounding down to 0 and set that to lo.
        if (f(mid)) {
            lo = mid; // if a small target median works, look for larger medians
        } else {
            hi = mid-1; // this is too large we exclude
        }
    }
    return lo;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k; cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int lastWorkMedian = last_true(arr[n/2], arr[n-1]+k, [&](int x) {
            long long sumK = 0;
            for (int j = (n-1)/2; j < n; j++)// mind your brackets at (n-1)
            {
                sumK += max(0,(x - arr[j])); // may well be over -> negative difference, need to reset to
            }
            
            return sumK <= k;
        
        });
    cout << lastWorkMedian;


}