#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int n; cin >> n;
    int cows[n]; 
    for (int i = 0; i < n; i++ ){
        cin >> cows[i];
    }
    int unsorted = n;
    for (int i = n-1; i >= 0; i--){
        unsorted --;
        if (cows[i] < cows[i-1]){
            // next guy unsorted!
            break;
        }
    }
    cout << unsorted << '\n';



}