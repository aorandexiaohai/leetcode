#include <string>
#include <iostream>
using namespace std;

class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        int size = s.size();
        if (size == 0)
            return 0;
        int max_length = 0;
        EliminatePair(&(s[0]), 0, size, &max_length);
        return max_length;
    }
    void EliminatePair(char *str, int bi, int ei, int* max_length)
    {
        *max_length = 0;
        if (ei - bi <= 1)
            return;
        auto base_bi = bi;
        while (base_bi < ei - 1)
        {
            int pi = -1;
            int ni = -1;
            for (int i = base_bi; i < ei - 1; i++)
            {
                if (str[i] == '(' && str[i + 1] == ')')
                {
                    pi = i;
                    ni = i + 1;
                    break;
                }
            }
            if (pi == -1)
                break;
            while (pi >= 0 && ni < ei)
            {
                if (!(str[pi] == '(' && str[ni] == ')'))
                    break;
                str[pi] = '.';
                str[ni] = '.';
                while (pi - 1 >= 0 && str[pi - 1] == '.')
                {
                    pi--;
                }
                pi--;
                while (ni + 1 < ei && str[ni + 1] == '.')
                {
                    ni++;
                }
                ni++;
            }
            int tmp_length = ni-pi-1;
            if(*max_length < tmp_length)
                *max_length = tmp_length;

            base_bi = ni;
        }
    }
};

int main()
{
    Solution().longestValidParentheses("(()())");
}