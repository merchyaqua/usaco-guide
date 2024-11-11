#include <bits/stdc++.h>

using namespace std;
// https://codeforces.com/contest/1826/problem/D

void solve(){
    /* the gist: rearrange the formula bl+br+bm-(r-l) 
    where b is the beauty array,
    r and l are indices of the start and end points
    and m is the index of the best sight between end points.
    get (bl+l) + (br-r) + bm.
    to maximise this equation, we find the maximum values of the three items.
    therefore we calculate and store values for the first two for each sight.
    one approach could be to iterate over each pair of bounds which is too slow.
    so we iterate through each middle element and determine the best bounds for them.
    using our computed arrays we do not worry about the indices anymore,
    so we can choose the maximum possible to the left and maximum possible to the right 
    for our bounds.
    which means we need 'prefix maximum' and 'suffix maximum'.
    so for each i in the prefix maximum, we store what is the best possible starting value.
    however this must be the one before i because we can't choose itself as the bound.
    suffix is similar but start comparing from the right of the array, for the maximum from right.
    */
    int n; cin >> n;
    int beauty[n];
    for (int i = 0; i < n; i++)
    {
        cin >> beauty[i];
        // cout << psum[i] <<' ';
    }

    int bl_plus_l[n]{};
    int br_minus_r[n]{};
    int premaxl[n]{};
    int sufmaxr[n]{}; // it's always worth the initialisation.
    for (int i = 0; i < n; i++) // set up the calculated arrays
    {
        bl_plus_l[i] = beauty[i] + i+1; 
        br_minus_r[i] = beauty[i] -(i+1); 
    }
    for (int i = 0; i < n; i++) // run through for maximums
    {
        if (i == 0) premaxl[i] = bl_plus_l[i]; // starting
        else
        premaxl[i] = max(bl_plus_l[i], premaxl[i-1]);
    }
    
    for (int i = n-1; i >= 0; i--) // run reverse for maximums
    {
        if (i == n-1) sufmaxr[i] = br_minus_r[i];
        else
        sufmaxr[i] = max(br_minus_r[i], sufmaxr[i+1]); // little bug - copy pasted i-1 here. caused very large numbers because of pulling undefined.
    }
    int maxBeauty = 0;

    // try middle element between
    for (int i = 1; i < n-1; i++)
    {
        int nu = premaxl[i-1] + beauty[i] + sufmaxr[i+1];
        maxBeauty = max(maxBeauty, nu);
        // cout << nu << endl;
    }
    
    

    // int maxBeauty = 0;
    // for (int range = 2; range <= n; range++)
    // {
    //     for (int l = 1; l <= n-range; l++)
    //     {
    //         int r = l+range;
    //         int beauty = psum[r]-psum[l-1];
    //         cout << l << ' ' << r << ' ' << beauty-range << '\n';
    //         maxBeauty = max(maxBeauty, beauty-range);
    //     }
        
    // }
    cout << maxBeauty << '\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    

}