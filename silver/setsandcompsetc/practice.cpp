#include <bits/stdc++.h>

using namespace std;

struct Person
    {
        int height;
        int weight;
        string name;
    } p1, p2, p3;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Person p;
    p.height = 60;
    
    p.weight=100;
    p1.name = "one";
    p2.name = "to";
    p3.name = "tre";
    p1.height = 10;
    p2.height = 30;
    p3.height = 10;
    p1.weight = 10;
    p2.weight = 29;
    p3.weight = 90;
    Person people[3] = {p1, p2, p3};
    sort(people, people+3, [](Person a, Person b){
        if (a.height == b.height)
            return a.weight < b.weight;
        return a.height < b.height;
    });
    for (int i = 0; i < 3; i++){
        cout << people[i].name << endl;
    }
    // cout << p.height;
    // cout << &p;
    // Person* ptr = &p;
    // (*ptr).height = 50;
    // cout << (*ptr).height;



    

}