#include <bits/stdc++.h>

using namespace std;
string spotty[500];
string plain[500];
unordered_map<string, bool> thing;


bool test(int one, int two, int three){

    string combo;
    // go through spotty of this threepos combo
    for (string cow : spotty){
        combo = cow[one] + cow[two] + cow[three];
        thing[combo] = true;
    }

    for (string cow2 : plain){
        combo = cow2[one] + cow2[two] + cow2[three];
        if (thing[combo] ) return false;
    }
    return true;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> spotty[i];     
    }

    for (int i = 0; i < N; i++)
    {
        cin >> plain[i];
    }
    int count = 0;
    //  go through position combos of 3
    for (int g = 0; g < M; g++)
    {
        for (int g2 = g+1; g2 < M; g2++)
        {
            for (int g3 = g2+1; g3 < M; g3++)
            {
                // cout << g << g2 << g3 << '\n';
                if (test(g, g2, g3)) count ++;
                thing.clear();

            }
            
        }
        
    }
    
    cout << count << '\n';
    

}