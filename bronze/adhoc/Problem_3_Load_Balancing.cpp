#include <bits/stdc++.h>

using namespace std;


int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);
    int n, b;
    cin >> n >> b;
    int x[n];
    int y[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    int minAns = n;

    // for each cow try fencing right next to it WRONG - for each existing x and y fence next to it.
    for (const int& a : x)   {
        // int a = cow.first+1; // actually having 2 is meaningless. the left hand side would've been covered by previous cow.
        // int b = cow.second +1;
        // check each cow's position now
        for (const int& b : y)   {

            int I = 0, II = 0, III = 0, IV = 0;
            // splitting by quadrants
            for (int i = 0; i < n; i++)   {
                if (x[i] > a && y[i] > b+1) I ++;
                else if (x[i] > a+1 && y[i] < b+1) II ++;
                else if (x[i] < a+1 && y[i] < b+1) III ++;
                else if (x[i] < a+1 && y[i] > b+1) IV ++;
            }
            // cout << a << ' ' << b << ":\n";
            // cout << I << ' ' << II << ' ' <<III << ' ' << IV << '\n';
            // find the largest pain and update best
            minAns = min(minAns, max({I, II, III, IV}));
        }   
            
    }
    cout << minAns<<'\n';
    
    

}