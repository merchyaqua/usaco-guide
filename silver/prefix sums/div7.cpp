#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin ("div7.in");
    ofstream fout ("div7.out");
    int N;
    fin >> N;
    // would've tried complete search if it wasn't an exercise
    long long presum[N+1];
    presum[0] = 0;
    int ans = 0;
    int ids[N+1];
    for (int i = 1; i < N+1;i++){
        fin >> ids[i];
        presum[i] = presum[i-1] + ids[i];
    }

    // for all possible lengths, find the sections but we can sum up in o(1)
    for (int i = N; i > 0; i--){
        for (int j = 1; j < N+2-i; j++) {
            long long current = presum[j+i-1] - presum[j-1]; // larger-smaller BUT move down 1 - binomial CD ;) include ids[j]!
            if (current%7 == 0) {
                ans = i;
                fout << ans;
                return 0;
            }
        }
    }

    fout << ans;



}