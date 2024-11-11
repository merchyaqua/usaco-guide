#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> algos(n);
    for (int i = 0; i < n; i++)
    {
        cin >> algos[i];
    }
    sort(algos.begin(), algos.end());
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (x - algos[i] >=0){
            x -= algos[i];
            count ++;
        } 
        if (x <= 0) {
            break;
        }
    }
    cout << count;
    


    
}