#include <bits/stdc++.h>

using namespace std;
// http://www.usaco.org/index.php?page=viewproblem2&cpid=104
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    int haybales[N+1]{}; 
    int stacks[N+2]{}; // indicate the start/end of ranges. +1 for start, -1 for ending of a stackrun
    for (int i = 0; i < K; i++)
    {
        int start, finish;
        cin >> start >> finish;  
        stacks[start] ++; // we have one more haybale starting here
        stacks[finish+1] --; // here is end of a range - don't keep going bessie
    }
    int currentRunningStack = 0;
    for (int i = 1; i < N+1; i++)
    {
        // currentrunningstack will depend on the ranges we marked just now.
        // if +, we have a new task open and running (bit like parenthenses but not)
        currentRunningStack+=stacks[i];
        haybales[i] = currentRunningStack;
    }
    

    sort(haybales, haybales + N+1);

    cout << haybales[N/2+1];
    

}