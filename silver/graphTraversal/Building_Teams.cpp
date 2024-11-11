#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> group;


bool dfs(int pupil){
    int opposite = group[pupil] == 1 ? 2 : 1;
    
    for (int mate : adj[pupil]){
        if (group[mate] == 0){
            group[mate] = opposite;
            // rerun checks for violation, if we messed it up
            if (!dfs(mate)) return false;
            // group[mate] = group[pupil]+1; // even to odd, odd to even
        } 
        else if (group[mate] == group[pupil]){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    adj.resize(n);
    group.resize(n);
    int m; cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    for (int pupil = 0; pupil < n; pupil++)
    {
        if (group[pupil] == 0){
            group[pupil] = 1;
        }
        if (!dfs(pupil)){
            cout << ("IMPOSSIBLE");
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << group[i] << ' ';
    }
    
    

    

}