#include <bits/stdc++.h>

using namespace std;

#include <cstdio>
void setio() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
}
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    setio();

    int n, q;
    cin >> n >> q;

    int breedcount[4][100001]{};

    for (int i = 1; i < n+1; i++){
        int cow;
        cin >> cow;
        for (int breed = 1; breed < 4; breed++){
            if (breed == cow) breedcount[breed][i] = breedcount[breed][i-1] + 1;
            else breedcount[breed][i] = breedcount[breed][i-1];
        }
    }

    for (int j = 0; j < q; j++){
        int start, end;
        cin >> start >> end;
        for (int breed = 1; breed < 4; breed++){
            cout << breedcount[breed][end] - breedcount[breed][start-1];
            if (breed != 3) cout << ' ';
        }
        if (j != q-1) cout << '\n';
    }
}