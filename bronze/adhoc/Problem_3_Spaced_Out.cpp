#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int grid[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    int maxans = 0;
    for (int row = 0; row < n; row++)
    {
        int temp1 = 0;
        int temp2 = 0;

        for (int i = 0; i < n; i+=2)
        {
            temp1 += grid[row][i];
        }

        for (int i = 1; i < n; i+=2)
        {
            temp2 += grid[row][i];
        }
        maxans += max(temp1, temp2);
        
    }
    int maxans2 = 0;

    for (int col = 0; col < n; col++)
    {
        int temp = 0;
        int temp2 = 0;

        for (int i = 0; i < n; i+=2)
        {
            temp += grid[i][col];
        }

        for (int i = 1; i < n; i+=2)
        {
            temp2 += grid[i][col];
        }
        maxans2 += max(temp, temp2);
        
    }
    cout << max(maxans,maxans2);

}