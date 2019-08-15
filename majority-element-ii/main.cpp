#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

//最多有两个元素
class Solution {
public:
    vector<int> res;
    bool times(vector<int>& nums, int num)
    {
        size_t cnt = 0;
        for(auto i: nums)
        {
            if(i == num)
                cnt++;
        }
        return cnt > nums.size()/3;
    }
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return res;
        if(len == 1)
        {
            res.push_back(nums[0]);
            return res;
        }
        int candidate1 = nums[0], candidate2 = nums[0];
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < len; i++)
        {
            if(nums[i] == candidate1)
            {
                cnt1++;
                continue;
            }
            if(nums[i] == candidate2)
            {
                cnt2++;
                continue;
            }
            if(cnt1 == 0)
            {
                candidate1 = nums[i];
                cnt1 = 1;
                continue;
            }
            if(cnt2 == 0)
            {
                candidate2 = nums[i];
                cnt2 = 1;
                continue;
            }
            cnt1--;
            cnt2--;
        }
        if(times(nums, candidate1))
            res.push_back(candidate1);
        if(candidate1 != candidate2 && times(nums, candidate2))
            res.push_back(candidate2);
        cout << candidate1 << " " << candidate2 << endl;
        return res;
    }
};

int main()
{
    int a[10] = {0,3,4,0};
    vector<int> vec(a, a+4);
    Solution s;
    s.majorityElement(vec);
    return 0;
}
