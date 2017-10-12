//从左下角开始搜索，如果比taget小往右移动，比taget大往左移动
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rows = array.size();
        int cols = array[0].size();
        int i,j;
        for(i = rows-1, j = 0; i >=0 && j < cols; )
        {
            if(array[i][j] == target){
                return true;
            }
            else if(array[i][j] > target){
                i--;
                continue;
            }
            else{
                j++;
                continue;
            }
        }
        return false;
    }
};

//最简单的遍历
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int len = array.size();
        for (int i = 0; i < len; ++i)
        {
            int len1 = array[i].size();
            for (int j = 0; j < len1; ++j)
                if (array[i][j] == target)
                    return true;
        }
        return false;
    }
};
