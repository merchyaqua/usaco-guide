#include <bits/stdc++.h>
using namespace std;

int main (){
    int N, Q;
    cin >> N >> Q;
    long long arr[N+1]{0};

    long long presum[N+1]{0};
    presum[0] = 0;

    for (int i = 1; i < N+1; i++) {
        cin >> arr[i];
        // cout << arr[i];
        presum[i] = presum[i-1] + arr[i];
    }
    for (int q = 0; q < Q; q++) {
        int l, r;
        cin >> l >> r;
        l ++;
        r++;
        cout << presum[r-1] - presum[l-1] << '\n';
    }

}