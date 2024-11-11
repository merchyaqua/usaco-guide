#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    int arr[n];
    map<int, int> pos; // map number to index. we do not worry about duplicate values since any solution is fine, so any index containing value needed is fine.
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        pos[num] = i;
        arr[i] = num;
    }
    sort(arr, arr+n); // sort but we have kept original record of positions, though not one to one accurately
    int p1 = 0;
    int p2 = 1;
    while (p2 < n)
    {
        int sum = arr[p1] + arr[p2];
        // cout << p1 << ' ' << p2 << endl;
        if (sum == x) break;
        if (sum < x) p2++;
        else p1++;
        if (p1 >=p2) break;
    }

    if (p1 >=p2) cout << "IMPOSSIBLE";
    else cout << pos[arr[p1]]+1 << ' ' << pos[arr[p2]]+1 << '\n';
    
    

}