#include <bits/stdc++.h>

using namespace std;

struct Cow
{
    int x, y, power;
};

vector<Cow> cows;
vector<vector<int>> adj;
vector<bool> heard;


float distance(int a, int b){
    int dx = (cows[a].x - cows[b].x);
    int dy = (cows[a].y - cows[b].y);

    float result = sqrt(dx*dx + dy*dy);
    // cout << a << " to " << b << '=' <<result << endl;
    return result;
}

int broadcast(int from){
    int reach = 1;
    heard[from] = true;
    for (int u : adj[from]){
        if (!heard[u]){
            reach += broadcast(u);
        }
    }
    return reach;
}

// #include <cstdio>

void setio() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setio();
    int n; cin >> n;
    cows.resize(n);
    adj.resize(n);
    heard.resize(n);

    for (int i = 0; i < n; i++)
    {
        // FATAL MISTAKE - DIDN'T READ WHAT THE INPUT ORDER IS
        int p, x, y;
        cin >> x >> y >> p;
        Cow c;
        c.power = p;
        c.x = x;
        c.y = y;
        cows[i] = c;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i== j) continue;
            if (cows[i].power >= distance(i,j)){
                adj[i].push_back(j);
            }
        }
    }
    
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        fill(heard.begin(), heard.end(), false);
        int nu = broadcast(i);
        // cout << nu << '\n';
        ans = max(ans, nu);
    }
    cout << ans;
    

}