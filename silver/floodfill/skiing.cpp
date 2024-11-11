#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
using namespace std;

int m, n;
const MAX_N =500;
int grid[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int startingi, startingj;
bool waypoints[MAX_N][MAX_N];
int waypoint_count;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin ("ccski.in");
    ofstream fout ("ccski.out");

    fin >> m >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fin >> grid[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fin >> (bool) waypoints[i][j];
            if (waypoints[i][j]) {
                startingi = i;
                startingj = j;
                waypoint_count ++;
            }
        }
    }

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            
        }
    }




    

    
}