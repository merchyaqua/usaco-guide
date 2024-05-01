#include <bits/stdc++.h>

using namespace std;

int main(){
    // did i finish this?
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin ("milkorder.in");
    ofstream fout ("milkorder.out");

    int N, M, K;
    fin >> N >> M >> K;
    int order[N+1]= {0};
    bool placed[N+1]={false};
    vector<int> hierarchy;
    int h;
    for (int i = 0; i < M; i++)
    {
        fin >> h;
        hierarchy.push_back(h);
    }
    int positions[N+1]={0};
    for (int i = 0; i < K; i++)
    {
        int cow, pos;
        fin >> cow >> pos;
        positions[cow] = pos;
        order[pos] = cow;
        placed[cow] = true;
        if (cow == 1){
            fout << pos;
            return 0;
        }
    }
    // for (auto u:order) {
    //     cout << u;
    // }
    int j = N;
    while(j > 0 && hierarchy.size() >0)
    {
        int cow = hierarchy.back();
        hierarchy.pop_back();
        if (placed[cow]) j = positions[cow];
        else {
            if (order[j] == 0) {
                if (cow == 1){
                    fout << j;
                    return 0;
                }
                order[j] = cow;
                placed[cow] = true;
            }
            else hierarchy.push_back(cow);
        }
        j--;
    }
    for (int i = 1; i < N+1; i++)
    {
        if (order[i] == 0)
        {
            fout << i;
            break;
        }
        
    }
    
    
    

    


}