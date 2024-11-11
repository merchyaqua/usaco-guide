#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, n; cin >> x >> n;
    set<int> lights{0, x};
    multiset<int> dist{x};
    for (int l = 0; l < n; l++)
    {
        int pos;
        cin>> pos;

        auto it1 = lights.upper_bound(pos); // what's the first light after this new point
        auto it2 = it1;
        --it2; // what's the first light before this new point we're going to split
        lights.insert(pos); // now we assessed and pinpointed, we build
        dist.erase(dist.find(*it1 - *it2)); // we take out that big distance
        dist.insert(pos-*it2); // add in front section
        dist.insert(*it1-pos); // add in back section
        cout << *--dist.end() << ' '; // find out new biggest distance
    }
    






    // int maxDiff = x; // at first, you go the whole length without lights

    // priority_queue<int> positions;
    // for (int i = 0; i < n; i++)
    // {
    //     int pos; cin >> pos; // new light
    //     maxDiff = max(maxDiff, pos-positions.top()); //e.g. -2 - -3 = 1
    //     cout << maxDiff << ' ';
    // }
    
    // // count absolute difference and i wonder
    // int previous = positions.top(); positions.pop();
    // for (int i = 1; i < n; i++)
    // {

    // }

    

}