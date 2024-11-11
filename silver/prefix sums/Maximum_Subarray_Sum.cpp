#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    long long arr[N+1];
    long long presum[N+1];
    long long maxpresum = -1e9;
    long long minpresum = 0;
    arr[0] = 0;
    presum[0] = 0;
    long long maxpind, minpind;

    for (int i = 1; i < N+1; i++)
    {
        cin >> arr[i];
        presum[i] = arr[i] + presum[i-1];
        // if (maxpresum <= presum[i]){
        //     maxpresum = presum[i]; 
        //     // maxpind = i;
        // } if (minpresum >= presum[i]) {
        //     minpresum = presum[i]; 
        //     // minpind = i;

        // }
    }
    // if (maxpind < minpind) cout << minpresum - maxpresum;
    // else cout << maxpresum-minpresum;
    minpresum = presum[0]; // just left bound value.
    maxpresum = presum[1]; // right bound value.

    for (int i = 1; i < N+1; i++)
    {
        // !! min must be from before, can't keep the overall min.
        maxpresum = max(maxpresum, presum[i]-minpresum);
        minpresum = min(minpresum, presum[i]);
    }
    
    cout << maxpresum;
    

}