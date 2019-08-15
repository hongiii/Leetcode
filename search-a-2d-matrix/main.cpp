#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool res = false;
        int row = matrix.size();
        if(row <= 0)
            return res;
        int col = matrix[0].size();
        for(int j = col-1; j >= 0; j--)
        {
            if(matrix[0][j] <= target)
            {
                for(int i = 0; i < row; i++)
                {
                    if(matrix[i][j] > target)
                        break;
                    if(matrix[i][j] == target)
                    {
                        res = true;
                        break;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30, 34,50}};
    Solution s;
    cout << s.searchMatrix(matrix, 13) << endl;
    return 0;
}
