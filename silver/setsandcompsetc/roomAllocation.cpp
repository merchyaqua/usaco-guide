#include <bits/stdc++.h>

using namespace std;

// mistake: didn't realise i needed the original indicies kept so i sorted without keeping them. turns out we need a nested pair to sort while latching onto old index.
// main idea: sort by arrival times, using a minheap we know the next available room. for each person, put assigned number into corresponding slot of array that maintains old indexing.

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    priority_queue<pair<int, int>> roomQueue;
    pair<pair<int, int>, int> schedule[n]; // ((arr,dep), originalpos)
    for (int i = 0; i < n; i++)
    {
        int arrival, departure;
        cin >> arrival >> departure;
        schedule[i].first = make_pair(arrival, departure);
        schedule[i].second = i;
    }
    sort(schedule, schedule+n);

    int roomcount = 1;
    int sol[n]{};
    for (int i = 0; i < n; i++)
    {
        int arrival = schedule[i].first.first;
        int departure = schedule[i].first.second;
        int oldIndex =schedule[i].second;

        int roomNum;
        if (!roomQueue.empty()){
            if (-roomQueue.top().first < arrival) {
                roomNum = roomQueue.top().second;
                roomQueue.pop(); // their departure works for us.
            } else {
                // we must make a new room.
                roomNum = ++roomcount;
            }
        } else {
            roomNum = roomcount;
        }
        roomQueue.push(make_pair(-departure, roomNum));
        sol[oldIndex] = roomNum; // announce our allocation
    }
    cout << roomcount << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << sol[i] << ' ';
    }
    
    

}