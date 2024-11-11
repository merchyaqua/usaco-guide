#include <bits/stdc++.h>

using namespace std;
int n, m, c;

int cows[100000];

bool works(int patience){
    // we have sorted cows. take at most c of the cows that are physically able to get on within average cow patience.
    // then we check the buses we need and compare to m.
    int busesNeeded = 0;
    int cowPointer = 0;
    while (busesNeeded <= m && cowPointer<n){
        int maxLate = cows[cowPointer]+ patience;
        int onBoard = 0;
        while (cows[cowPointer] <= maxLate && onBoard < c){
            onBoard++;
            cowPointer++;
        }
        busesNeeded++;
    }
    if (busesNeeded > m) return false;
    return true;


}

int binarySearch(int lo, int hi){
    if (lo == hi) return lo;
    if (lo+1 == hi) {
        if (works(lo)) return lo;
        return hi;
    }

    int mid = lo + (hi-lo)/2;
    if (works(mid)) return binarySearch(lo, mid);
    return binarySearch(mid+1, hi);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    cin >> n >> m >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> cows[i];
    }
    sort(cows, cows+n);
    cout << binarySearch(0, cows[n-1]-cows[0]+1);
    // cout << works(10);

    // long long mc = m*c;
    // int maxdiff = 0;



    // if (mc == n) {
    //     // go through each groups of c and take max diff
    //     for (int i = 0; i < n; i+=c)
    //     {
    //         int first = cows[i];
    //         int second = cows[i+c-1];
    //         maxdiff = max(maxdiff, second-first);
    //     }
        
    // } else {
    //     int extra_buses = m - ceil(n / c);
    //     // sort groups of cows according to their waiting times
    //     // go to the group with highest waiting time and give buses. it is possible that even after dishing out buses, one of the newly grouped cows still hold highest waiting time.
    //     vector<pair<int, int>> buses;
    //     for (int i = 0; i < n; i+=c)
    //     {
    //         int first = cows[i];
    //         int second = cows[i+c-1];
    //         buses.push_back(make_pair(first, second));
    //     }

    //     while (extra_buses > 0) {
    //         // auto index = max_element(buses.begin(), buses.end(), [](auto a, auto b){
    //         //     return a.second-a.first < b.second-b.first;
    //         // })


    //     }
    // }
    // fine i give up.


}