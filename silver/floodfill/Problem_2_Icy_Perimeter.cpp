#include <bits/stdc++.h>

using namespace std;

vector<string> grid;
int n; 
int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};

pair<int, int> floodfill(int r, int c) {

    int area = 1, perimeter = 4;
    grid[r][c] = 'X'; // steven halim's method of marking as visited
    for (int d = 0; d < 4; d++)
    {
        int nr = r+ dr[d];
        int nc = c+ dc[d];
        if (nr >=n ||nr <0||nc>=n||nc<0) continue;
        if (grid[nr][nc] != '.') perimeter--;
        if (grid[nr][nc] == '#'){ // not empty
            auto np = floodfill(nr, nc);
            area += np.first;
            perimeter += np.second;
        }


    }
    

    return make_pair(area, perimeter);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen ("perimeter.in","r",stdin);
    freopen ("perimeter.out","w",stdout);
    cin >> n;
    grid.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    pair<int,int> max_pair = make_pair(0,0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '#') {
                auto newpair = floodfill(i, j); 
                newpair.second = -newpair.second;
                max_pair = max(max_pair, newpair);
                

            }
        }
        
    }
    cout << max_pair.first << ' ' << -max_pair.second;
    

    


}