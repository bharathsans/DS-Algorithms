#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0, mid = 0, r = nums.size() - 1;
        
        while(l <= r){

            mid = l + (r - l)/2;

            if(nums[mid] == target)
                return mid;

            // Mid is in left sorted portion...
            if(nums[mid] >= nums[l]) {

                if(target > nums[mid] || target < nums[l])
                    l = mid + 1;
                else
                    r = mid - 1;

            }
            // Mid is in right sorted portion...
            else{
                
                if(target < nums[mid] || target > nums[r])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }

        return -1;
    }
};


int main(){

    Solution solve;

    vector<int> nums;
    nums.push_back(7);
    nums.push_back(8);
    for(int i = 0; i < 3 ; i++)
        nums.push_back(i + 1);

    int target = 0;
    cout << solve.search(nums, target) << endl;
}