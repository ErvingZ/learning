#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param nums: an array of integers
     * @param k: an integer
     * @return: the number of unique k-diff pairs
     */
    int findPairs(vector<int> &nums, int k) {
        // Write your code here
        if(nums.size()<2)
            return 0;
        sort(nums.begin(),nums.end(),[](int a,int b)->bool{return a<=b;});
        int biggerThan = nums[0]-1;
        int left = 0;
        int right = 1;
        int res=0;
        while(left<nums.size()-1 && right<nums.size())
        {
            while(left<nums.size()-1 && nums[left]<=biggerThan)
                left++;
            if(left == nums.size()-1)
                break;
            if(right<=left)
                right = left+1;
            if(nums[right]-nums[left] == k)
            {
                biggerThan = nums[left];
                res++;
            }
            else if(nums[right]-nums[left] < k)
                right++;
            else
                left++;
        }
        return res;
    }
};
int main()
{
    Solution a;
    vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int res = a.findPairs(nums,0);
    cout << res <<endl;
}   