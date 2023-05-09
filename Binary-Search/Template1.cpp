#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>& nums, int find){

    int low = 0, high = nums.size() - 1;
    while(low <= high){

        int mid = low + (high - low) / 2;
        if(nums[mid] == find){
            return mid;
        }
        else{
            if(find > nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {1, 2, 5, 8};
    sort(nums.begin(), nums.end());
    int ind = binarySearch(nums, 5);
    if( ind == -1 )
        cout << "NOT FOUND";
    else
        cout << "FOUND AT : " << ind ;
}