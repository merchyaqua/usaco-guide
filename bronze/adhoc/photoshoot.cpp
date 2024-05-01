#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string cows; int N;
    cin >> N >> cows; // shortened code - no such thing as line input lol
    string current = "XX";
    // scrapped below section. works just fine with linearInit 

    // find first occuring pair tha tmatters
    // for (int i = 0; i < N-1; i+=2)
    // {
    //     if (cows[i] != cows[i+1]){
    //         current = cows.substr(i, 2);
    //         break;
    //     }
    // }
    int count = 0;

    for (int i = 0; i < N-1; i+=2)
    {
        if (current == "XX") current = cows.substr(i, 2); // my linearinit
        if (cows[i] == current[1] && cows[i+1] == current[0]){
            // oh out of order here. we've been making everything go this other way
            // following line: actually no need to physically reverse since we're not looking back. was useful for debug purposes.
            // reverse(cows.begin(), cows.begin()+i); // yay
            current = cows.substr(i, 2); // new world order
            count ++;
        }
        // else ur good
    }
    
    if (current == "GH") { // need a final swap
        // reverse(cows.begin(), cows.end());
        count ++;
    }cout << count;

}