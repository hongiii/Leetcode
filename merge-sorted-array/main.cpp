#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;
        if(n == 0)
            return;
        int cnt = m+n-1;
        int p1 = m-1;
        int p2 = n-1;
        while(p1 >= 0 && p2 >= 0)
        {
            if(nums1[p1] < nums2[p2])
            {
                nums1[cnt--] = nums2[p2];
                p2--;
            }
            else
            {
                nums1[cnt--] = nums1[p1];
                p1--;
            }
        }
        if(p1 < 0)
        {
            for(int i = p2; i >= 0; i--)
                nums1[cnt--] = nums2[i];
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
