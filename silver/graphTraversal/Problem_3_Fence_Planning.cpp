#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;

struct Cow
{
    int x, y;
};


vector<bool> visited;
vector<vector<int>> adj;
vector<Cow> cows;

ll dfs(int cow, int minx, int miny, int maxx, int maxy){
    // goes through each element of a connected component and return the perimeter of its rectangular span
    
    visited[cow] = true;
    minx = min(minx, cows[cow].x);
    miny = min(miny, cows[cow].y);
    maxx = max(maxx, cows[cow].x);
    maxy = max(maxy, cows[cow].y);
    ll perimeter = 2*(maxx-minx + maxy-miny); // our current perimeter
    for (auto neighbour : adj[cow]){
        if (!visited[neighbour]){
            // perimeter is updated if this new cow and its friends stretch out the fence
            perimeter = max(perimeter, dfs(neighbour, minx, miny, maxx, maxy));
        }
    }
    return perimeter;
    // if no neigbours, it is updated with the calculation while preserving the entire min max series
}
#include <cstdio>
using namespace std;
void setio() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
}
int main(){
    setio();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    cows.resize(n);
    visited.resize(n);
    adj.resize(n);
    for (int i = 0; i < n; i++)
    {
        Cow curr;
        cin >> curr.x >> curr.y;
        cows[i] = (curr);
        visited[i] = (false);
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a); // lol so dumb forgot to do two way
    }

    ll ans = 1e16;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i]){
            ans = min(ans,dfs(i, 1e8, 1e8, 0, 0));
        }
    }
    cout << ans;
    
    

    


}