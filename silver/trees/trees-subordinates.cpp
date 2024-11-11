#include <bits/stdc++.h>

using namespace std;
vector<int> children[2*100000+1];
int childcount[2*100000+1]{};

int countsub(int boss) {
    if (children[boss].size() == 0) return 0; // is leaf
    if (childcount[boss] > 0) return childcount[boss]; // not leaf but calculated alr
    int sum = 0;
    for (int child : children[boss]) {
        int hi = countsub(child);
        sum += hi+1;
    }
        childcount[boss] = sum;
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 2; i < n+1; i++) {
        int boss;
        cin >> boss;
        children[boss].push_back(i);
    }

    countsub(1);
    for (int i = 1; i < n+1; i++)
    {
        cout << childcount[i] <<' ';
    }
    

}