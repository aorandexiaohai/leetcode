#include <string>
#include <iostream>
using namespace std;

class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        if (s.empty())
        {
            if (p.empty())
                return true;
            int idx = p.find("*");
            if (idx == 0)
            {
                return false;
            }
            else if (idx == 1)
            {
                p.erase(p.begin(), p.begin() + 2);
                return isMatch(s, p);
            }
            return false;
        }
        else if (p.empty())
        {
            return s.empty();
        }
        else if (p.size() >= 2)
        {
            // return process2(s,p);
            if (p[0] == '*')
            {
                //error input
                return false;
            }

            if (p[0] == '.')
            {
                if (p[1] != '*')
                {
                    s.erase(s.begin());
                    p.erase(p.begin());
                    return isMatch(s, p);
                }
                else
                {
                    //int beg = s[0];
                    p.erase(p.begin(), p.begin() + 2);
                    do
                    {
                        bool tmp = isMatch(s, p);
                        if (tmp)
                            return true;
                        if (s.empty())
                            break;
                        else
                            s.erase(s.begin());
                    } while (true);
                    return isMatch(s, p);
                }
            }
            else
            {
                if (p[1] != '*')
                {
                    if (s[0] != p[0])
                        return false;
                    s.erase(s.begin());
                    p.erase(p.begin());
                    return isMatch(s, p);
                }
                else
                {
                    int beg = p[0];
                    p.erase(p.begin(), p.begin() + 2);
                    do
                    {
                        bool tmp = isMatch(s, p);
                        if (tmp)
                            return true;
                        if (s.empty())
                            break;
                        else if (s[0] == beg)
                            s.erase(s.begin());
                        else
                            break;
                    } while (true);
                    return isMatch(s, p);
                }
            }
        }
        else if (p.size() == 1)
        {
            if (p[0] == '*')
                return false;
            else if (p[0] == '.')
            {
                s.erase(s.begin());
                p.erase(p.begin());
                return isMatch(s, p);
            }
            else
            {
                if (s[0] != p[0])
                    return false;
                s.erase(s.begin());
                p.erase(p.begin());
                return isMatch(s, p);
            }
        }
        return false;
    }
};

