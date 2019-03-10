#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    void nextPermutation(vector<int> &nums)
    {
        int size = nums.size();
        if(size == 0) return ;
        if(!nextPermutationInner(&(nums[0]),0,size))
        {
            std::sort(nums.begin(), nums.end());
        }
    }
protected:
    bool nextPermutationInner(int* arr, int bi, int ei)
    {
        int len = ei-bi;
        if(len <= 1) return false;
        if(!nextPermutationInner(arr, bi+1, ei))
        {
            int min_index = -1;
            for(int i=bi+1; i<ei; i++)
            {
                if(arr[i]> arr[bi] && (min_index==-1 || arr[min_index]>arr[i]))
                {
                    min_index = i;
                }
            }
            if(min_index>=0)
            {
                std::swap(arr[bi], arr[min_index]);
                std::sort(arr+bi+1, arr+ei);
                return true;
            }
            else return false;
        }
        else return true;
    }
};

int main()
{
    std::vector<int> vi{1, 2, 3};
    Solution().nextPermutation(vi);
    for(auto&& data : vi)
        std::cout<<data<<" ";
}