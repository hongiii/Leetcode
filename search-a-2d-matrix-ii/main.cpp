#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    int bSearch(vector<vector<int>>& matrix, int target, int flag, int row, int col)
    {
        int res = -1;
        if(flag == 0)//按行找，找到第一个小于target的
        {
            int left = 0, right = col;
            int mid;
            while(left <= right)
            {
                mid = (left+right)>>1;
                if(matrix[0][mid] <= target)
                {
                    res = mid;
                    left = mid+1;
                }
                else
                {
                    right = mid-1;
                }
            }
        }
        else
        {
            int left = 0, right = row;
            int mid;
            while(left <= right)
            {
                mid = (left+right)>>1;
                if(matrix[mid][col] < target)
                {
                    left = mid+1;
                }
                else if(matrix[mid][col] > target)
                {
                    right = mid-1;
                }
                else
                {
                    res = mid;
                    break;
                }
            }
        }
        return res;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool res = false;
        int row = matrix.size();
        if(row <= 0) return res;
        int col = matrix[0].size();
        int j = bSearch(matrix, target, 0, 0, col-1);
        if(j == -1)
            return res;
        for(;j >= 0; j--)
        {
            int check = bSearch(matrix, target, 1, row-1, j);
            if(check != -1)
            {
                res = true;
                break;
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,   4,  7, 11, 15},{2,   5,  8, 12, 19},{3,   6,  9, 16, 22}
    ,{10, 13, 14, 17, 24},{18, 21, 23, 26, 30}};
    Solution s;
    cout << s.searchMatrix(matrix, 5) << endl;
    return 0;
}
