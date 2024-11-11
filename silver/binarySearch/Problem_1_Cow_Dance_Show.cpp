#include <bits/stdc++.h>

using namespace std;


int n, Tmax;

int cows[10000];

// what's the problem? dunno I GUESS IT'S BC THE GREEDY APPROACH FAILS AND ONE MUST USE A HEAP

// bool works(int k){
//     long long stage[k]{};
//     if (k == n) return true;
//     for (int i = 0; i < k; i++)
//     {
//         stage[i] = cows[i]; // put the cow in
//     }
//     // for remaining cows
//     int restptr = k;
//     for (int i = k-1; i >= 0 && restptr <n ; i--)
//     {
//         // for the stage, go small to large, fit in as many longest durations as possible so going from left to right in cows[]
//         while (restptr <n && (stage[i] + cows[restptr] <= Tmax)){ // we haven't gone through all cows and it'd work
//             // it works
//             cout << stage[i] << " takes " << cows[restptr] << '\n';
//             stage[i] += cows[restptr];
            
//             restptr++; // look at next small cow
//         } 
//     }
//     cout << "restptr is " << restptr << '\n';
//     if (restptr != n) return false;
//     return true;
    

    
// } 


bool works(int k){
    // let's find the time this arrangement will end
    // by keeping the quickest cow to leave etc with a pq apparently
    // bit like the oucc bike thing
    priority_queue<int> pq;
    // for (int i = 0; pq.size() < k && i < n; i++){
    //     pq.push(-cows[i]); // no need to sort bc heapsort. heap is max-rooted so smallest cow goes first
    // }
    // now we do stuff to the queue until tmax is exceeded
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (pq.size() == k) { //
            time = -pq.top(); // we need to update quickest available time - no available stages.
            pq.pop(); // we filled the stage already so start to exploit. always look to the quickest toilet stall
            // by popping, we are taking this soonest avail stage for our incoming cow.
        }
        if (time + cows[i] > Tmax) {return false;} // our quickest line can't take this cow and preserve curfew
        pq.push(-(time + cows[i])); // now this stall is free at this time that is after this cow
    }
    return true;
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);

    cin >> n >> Tmax;
    for (int i = 0; i < n ; i++)
    {
        cin >> cows[i];
    }

    int lo = 0, hi = n, mid;
    // int ans = n;
    // sort(cows, cows+n,greater<int>());

    while (lo < hi){
        mid = lo + (hi-lo+1)/2;
        if (lo == hi-1){
            if (works(lo)){ // usual stuff - since we output lo
                lo = lo;
            } else {
                lo = hi;
            }
            break;
        }
        if (works(mid)){
            hi = mid;
            // cout << mid << "works \n";
        } else {
            lo = mid+1;
        }
    }
    cout << lo << '\n';


}