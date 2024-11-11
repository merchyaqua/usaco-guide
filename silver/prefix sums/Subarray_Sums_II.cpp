#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    long long psum[n+1]{};
    map<long long, int> exists;
    exists[0] = 1;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        psum[i] += num;
        // exists[psum[i]] += 1;
        // cout << exists[psum[i]];
        // THAT WAS SO DANGEROUS! it meant that you tried to look at the prefix sums after you, which made no sense!
        psum[i+1] += psum[i];
    }
    long long count = 0;
    for (int i = 0; i < n; i++)
    {
            count += exists[psum[i]-x]; // we count how many candidates we can use as starting point for up to here, that will all give x.
            // cout << psum[i] << endl; 
            // gosh, the long long issues in this
            exists[psum[i]] ++; // at this point we have this prefix sum and we know it exists as far as we're looking, so at our next iteration, we can consider this as a starting point for our range.
    }
    cout << count;
    

}