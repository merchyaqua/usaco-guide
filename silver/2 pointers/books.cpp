#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // books, time available, books.
    // two initial pointers at 0. moves end to right if we can take more. keeps moving til hit end.

    int n, t;
    cin >> n>> t;
    int books[n];
    // int presum[n+1];
    // books[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> books[i];
        // presum[i] = presum[i-1] + books[i];
    }
    int start = 0, end = -1;
    int sum = 0;
    int maxlen = 0;
    while (end < n)
    {
        // don't let 1 2 1 = 4 stop you from arriving at 1 1 1 1
        while (end < n){
            // get comfy with this put in take out thing
            sum += books[end++];
            if ()
        }

    }
    cout << maxlen;
    
    

}