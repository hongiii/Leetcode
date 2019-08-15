#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool ismorethanhalf(vector<int>& nums, int index)
    {
        vector<int>::iterator it;
        unsigned int cnt = 0;
        auto len = nums.size();
        for(it = nums.begin(); it != nums.end(); ++it)
        {
            if(*it == nums[index])
                cnt++;
            if(cnt*2 > len)
                return true;
        }
        return false;
    }
    int partition(vector<int>& nums, int start, int end)
    {
        if(start > end)
            return -1;
        int pivot = (start+end)>>1;
        int i = start, j = end, tmp;
        while(i < j)
        {
            while(nums[j] >= nums[pivot] && i < j)
                j--;
            while(nums[i] <= nums[pivot] && i < j)
                i++;
            if(i < j)
            {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        tmp = nums[i];
        nums[i] = nums[pivot];
        nums[pivot] = tmp;
        return i;
    }

    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        if(len <= 0)
            return -1;
        int start = 0, end = len-1;
        int index = partition(nums, start, end);
        while(index != len/2)
        {
            if(ismorethanhalf(nums, index))
                return nums[index];
            if(index > len/2)
            {
                end = index-1;
                index = partition(nums, start, end);
            }
            else
            {
                start = index+1;
                index = partition(nums, start, end);
            }
        }
        return nums[index];
    }
};


int main()
{
    int a[7] = {6, 6, 6, 7, 7};
    int b[3] = {3,2,3};
    vector<int> vec(a, a+5);
    Solution s;
    cout << s.majorityElement(vec) << endl;
    vec.clear();
    vec.assign(b, b+3);
    cout << s.majorityElement(vec) << endl;
    return 0;
}
