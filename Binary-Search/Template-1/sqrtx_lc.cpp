// https://leetcode.com/problems/sqrtx/description/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
        
    int mySqrt(int x) {
        
        int low = 0;
        int high = x / 2 + 1;

        while(low <= high){

            long long mid = low + (high - low)/2;

            long long square = mid * mid;
            if(square == x)
                return mid;
            
            if(square < (long long)x)
                low = mid + 1;
            else
                high = mid - 1;
        }

        // when breaking out high < low. We want the floor (lesser value)...
        return high;
    }
};

int main() {
    Solution solve;
    int num = rand() % 100;

    cout << "Input: "<< endl;
    cout << num << endl;



    cout << "Output: " << endl;
    cout << solve.mySqrt(num) << endl;
}