#include <bits/stdc++.h>

using namespace std;

int add(int a, int b){
    
    while (b > 0) // we do this til no more carries
    {
        int carry = a & b;
        a ^= b; // store XOR results in a for accumulator
        // now our new operand is the carry. we move the and result to the left for the actual resulting bit.
        b = carry << 1;
    }
    return a;
}

int multiply(int a, int b){
    int result = 0;
    while (b > 0) {
        if ((b & 1) == 1){ // we want to multiply by this - we skip if we get 0
            result = add(result, a);
        }
        a <<= 1; // 
        b >>= 1; // look at the next bit we're multiplying everything by
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a = 10;
    int b = 2;
    int result;
    

    cout << a;

}