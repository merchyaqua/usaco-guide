#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ticketcount, customercount;
    cin >> ticketcount >> customercount;
    multiset<int>tickets; // MISTAKE 3 - CRUCIAL - FORGOT YOU CAN HAVE MANY OF THE SAME TICKETS AND A NORMAL SET WOULDN'T KEEP IT
    for (int i = 0; i < ticketcount; i++)
    {
        int tick;
        cin >> tick;
        tickets.insert(tick);
    }

    for (int j = 0; j < customercount; j++)
    {
        // if (tickets.size() == 0) {
        //     cout << -1 << '\n';
        //     continue;// !! mistake again for missing this. we are screwed we have nothjing left and the below cases won't handle it elegantly. it was outputting 0.

        // }
        int cust;
        cin >> cust;

        auto it = tickets.upper_bound(cust); // first ticket exceeding price
        
        if (it == tickets.begin()) { 
            // !! mistake: forget to check that the smallest ticket didn't happen to be just the right ticket.
            // the smallest ticket is above budget
            // CORRECTION: NO. upper bound points to the element AFTERthe one that's just right. so the one before is the one just right. what's before begin? nothing.
            // this eliminates the need for seeing when 0 tickets left. see, when you patchwork, some fundamental understanding is missing
            
            cout << -1 << '\n';
            // if (*it > cust) cout << -1 << '\n';
            // else cout << *it << '\n'; // mistake 2: forgot that you can't decrease a begin
        } else{
            // if you get end, that's fine it means you are so rich above all tickets
            cout << *(--it) << '\n'; // take the ticket just below the one over budget
            tickets.erase(it);
        }
    }
    // i struggled with upper and lower bound for a bit. very good exercise for understanding set iterators.

    
    

}