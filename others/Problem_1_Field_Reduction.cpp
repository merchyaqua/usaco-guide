#include <bits/stdc++.h>

using namespace std;



    /* KEY: there are 4 possible boundary points for each side of the rectangle: 
    You can remove 3, 2, 1 or 0 points from each side.
    E.g. top edge, removing 3 highest points leaves you with the 4th highest point on the boundary (to squeeze out the area to minimum)
    Removing 0 points leaves you with the highest point as boundary.
    Similarly, in between, removing 2 -> 3rd highest on boundary etc.

    We don't worry about removing too many points - our area function deals with it.
    However, if you dictate the number of points removed here
    ...you wouldn't be able to manually tell if you've removed 1 or more points on the same line
    so this is a nice catch-all. */

    /* My initial idea was to go through every point and calculate its distance from every other point to determin the outlier, but that would be n^2 -> 2.5*10^9.
    This method gives 4*4*4*4 (sets of 4 edges to check) * n (points to check for each set). Worst case this would be 4^4 * 50000 = 1.28*10^7 operations. 
    Usually, under 10^8 is acceptable. USACO grader can do 10^8 per second. Time limit is 2s.
    */



// initialise globals with maximum values of N - max 50000 points as input.
int pointsX[50001]; // stores the x-coordinates of each point
int pointsY[50001]; // stores y-coordinates of each point.
// initally I wanted to use a pair<int, int> but I hate the idea of using point.first, point.second.
// it was a mistake I had made in the past due to comfort in Python tuples just being indexed, 
// instead of having to type out things.

const long long area_max = 2500000000; // maximum area is the whole field space - 50,000 squared.
vector<int> Xarr; // these store indicies of points that are going to be on the boundary.
vector<int> Yarr;
int n;

long long area(int top, int bottom, int left, int right){
    // this calculates the area of a rectangle given the edges' values.
    int offcount = 0; // this counts how many of the points get left out
    for (int i = 0; i < n; i++) // iterate through all the points - 50,000 is 5 x 10^4.
    {
        if (left <= pointsX[i]&&pointsX[i] <= right && top >= pointsY[i] && pointsY[i] >= bottom){
            continue; // ensure the point has coordinates within the boundaries.
            // when this malfunctioned I opened up desmos and plotted all the test cases.
            // turns out the problem was, at some point I passed in edges where top < bottom or left> right,
            // resulting in negative area.
        } else offcount++; // count this out of bounds point
        if (offcount > 3) return area_max; // FJ can't sell more than 3 cows. Ensure this doesn't get considered as best answer since we take min
    }
    long long result = (top-bottom) * (right-left); // y-length times x-length
    if (result <= 0) return area_max; // negative area remedy

    return result;
}

// these two custom comparators help sort the points based on X and Y values.
bool Xcmp(int a, int b){
    return pointsX[a] <pointsX[b]; // we are arranging the indicies of the points.
    // so we look at index a's point, look at it's X value and compare that to b's stuff
}

bool Ycmp(int a, int b){
    return pointsY[a] < pointsY[b];
}

int main(){
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    // file io, fast io
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // take the points in 
        cin >> pointsX[i] >> pointsY[i];
        // in the meantime, record the indicies of the point taken in.
        Xarr.push_back(i);
        Yarr.push_back(i);
        // for (int j = 0; j < 4; j++)
        // { 
        //     // go through from most to leastintense, discarding smallest element each time
        //     if (tops[j]==0 || tops[j] < pointsY[i]){
        //         tops.erase(tops.begin()+3);
        //         tops.insert(tops.begin()+j, pointsY[i]);
        //     }else if (bottoms[j]==0 || bottoms[j] > pointsY[i]){
        //         bottoms.erase(bottoms.begin()+3);
        //         bottoms.insert(bottoms.begin()+j, pointsY[i]);
        //     }if (lefts[j]==0 || lefts[j] > pointsX[i]){
        //         lefts.erase(lefts.begin()+3);
        //         lefts.insert(lefts.begin()+j, pointsX[i]);
        //     }else if (rights[j]==0 ||rights[j] < pointsX[i]){
        //         rights.erase(rights.begin()+3);
        //         rights.insert(rights.begin()+j, pointsX[i]);
        //     }
        // }   
    }

    // arrange the indicies. 
    


    // This is so that we can use the first element of Xarr as index into points[X] to find the minimum X value.
    // Didn't just use min_element() because we want 4 of these.
    sort(Xarr.begin(), Xarr.end(), Xcmp);
    // pass in the relevant "slice" indicies to this new vector - copies over that range.
    vector<int> lefts(Xarr.begin(), Xarr.begin()+4);
    vector<int> rights(Xarr.end()-4, Xarr.end());
    // -4 here because -1 gets you the last element

    sort(Yarr.begin(), Yarr.end(), Ycmp);
    vector<int> tops(Yarr.end()-4, Yarr.end());
    vector<int> bottoms(Yarr.begin(), Yarr.begin()+4);

    // Initialise a value that is guaranteed to be overwritten by correct answer
    long long minArea = area_max;
    // look through every possible combination of these edges. Ugly nested loop I know...
    for (const int& top : tops){
        for (const int& bottom : bottoms ){
            for (const int& left : lefts ){
                for (const int& right : rights){
                    // const int& used for read-only ref and doesn't copy things over, just feels nicer imo 
                    minArea = min(minArea, area(pointsY[top], pointsY[bottom], pointsX[left], pointsX[right]));
                }
            }
        }
    }
    cout << minArea << '\n';

    // cout << "lol" << '\n';



    

    

}