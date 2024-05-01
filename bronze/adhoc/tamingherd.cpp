#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    int minusStreak = 0;
    int lastrealval = 0;
    int lastrealInd = 0;
    int minbreak = 1; int maxbreak=1;
    bool invalid = false;
    for (int i = 0; i < n; i++)
    {
        int day;
        cin >> day;
        if (i == 0) {
            if (day != -1 && day != 0) invalid = true;
            continue; // we're all set up for this
        }


        if (day == -1 && i != 0) minusStreak++;
        else {
            // !! MISTAKE: 0 DIDN'T ALLOW FOR ACCOUNTING PREVIOUS MINSTREAK OOPS
            // if (day == 0) { // must be a new breakout
            //     minbreak++;
            //     maxbreak++;
            // } else {
                // check indicies and days vals line up
                if (day-lastrealval == i-lastrealInd) {
                    // ignore
                } else {
                    if (day-lastrealval > i-lastrealInd) {
                        // we got told there are these many days between them, yet we don't have remotely enough?
                        invalid = true;
                    }
                    // there's at least one new breakout

                    minbreak++;
                    maxbreak++;
                    // we allocate whatever the current day needs to consume up to a 0, then the rest can be considered as not continuations of the lastreal but their own daily breakouts.
                    maxbreak += minusStreak-day;
                    // cout << day << " got extra of " << minusStreak-day << '\n';

                }
            // }
            // resetting
            lastrealInd = i;
            lastrealval = day;
            minusStreak = 0;

        }
    }
    if (minusStreak != 0) {
        // ended with a stream of -1s. this either continues legacy for nothing for min 
        // or each of them contributes to max.
        maxbreak += minusStreak;
    }

    if (invalid) cout << -1;
    else cout << minbreak << ' ' << maxbreak;
    
}