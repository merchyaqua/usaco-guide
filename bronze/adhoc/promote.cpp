#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // a trickle down the divisions approach: at plat, there's a new cow.
    // this means it must've come from gold.
    // when you check differences though, 1-1=0 - no cow had left gold.
    // check silver, same - no cow left silver.
    // so it must've left from bronze.
    // at each divison increment the count of each.
    int differences[4]{};
    for (int i = 0; i < 4; i++)
    {
        int before, after;
        cin >> before >> after;
        int diff = after-before;
        differences[i] = diff;
    }
    int tracing = differences[3];
    for (int i = 3; i > 0; i--)
    {
        tracing = differences[i]; // add them onto the after bit
        differences[i-1] += tracing;
    }

    for (int i = 1; i < 4; i++)
    {
        cout << differences[i] << '\n';
    }
    
    
    

}