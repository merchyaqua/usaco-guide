#include <bits/stdc++.h>

using namespace std;

int ask(string op, int a, int b){
    int res;
    cout << op<<" " << a <<' '<<b<<endl;
    cin >> res;
    return res;
}

int add(int i, int j){
    // get the carry bits - the ands, and multiplying by 2 = left shifting to get real carried value
    int anded = ask("and", i, j);
    int carrys = 2*anded;
    int xorsums = ask("or", i, j) & ~anded;
    return xorsums+carrys;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int r = add(1,0);
    // cout << r;
    int n, k; cin >> n >> k;
    int one = add(3, 1);
    int two = add(3, 2);
    int three = add(1, 2);
    int third = (one+two+three-(2*three))/2;
    vector<int> numbers{one-third, two-third,third};
    for (int i = 4; i < n; i++)
    {
        numbers.push_back(add(i, 3) - third);
    }
    sort(numbers.begin(), numbers.end());
    
    

    cout << "finish "<< numbers[k-1] << endl;
    

}