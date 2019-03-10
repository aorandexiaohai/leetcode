#include <string>
#include <iostream>
using namespace std;

class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        return isMatchInner(s.c_str(), 0, s.size(), p.c_str(), 0, p.size());
    }

    bool isMatchInner(const char *s, int sb, int se, const char *p, int pb, int pe)
    {
        if (p[pb] == '*')
            return false;
        int plen = pe - pb;
        int slen = se - sb;
        if (slen == 0)
        {
            if (plen == 0)
                return true;
            if (plen >= 2 && p[pb + 1] == '*')
            {
                return isMatchInner(s, sb, se, p, pb + 2, pe);
            }
            return false;
        }
        else if (plen == 0)
        {
            return slen == 0;
        }
        else if (plen >= 2)
        {
            if (p[pb] == '.')
            {
                if (p[pb + 1] != '*')
                {
                    return isMatchInner(s, sb + 1, se, p, pb + 1, pe);
                }
                else
                {
                    pb += 2;
                    do
                    {
                        bool tmp = isMatchInner(s, sb, se, p, pb, pe);
                        if (tmp)
                            return true;
                        if (sb == se)
                            break;
                        else
                        {
                            sb++;
                        }
                    } while (true);
                    return isMatchInner(s, sb, se, p, pb, pe);
                }
            }
            else
            {

                if (p[pb + 1] != '*')
                {
                    if (s[sb] != p[pb])
                        return false;
                    return isMatchInner(s, sb + 1, se, p, pb + 1, pe);
                }
                else
                {
                    int beg = p[pb];
                    pb += 2;
                    do
                    {
                        bool tmp = isMatchInner(s, sb, se, p, pb, pe);
                        if (tmp)
                            return true;
                        if (sb == se)
                            break;
                        else if (s[sb] == beg)
                            sb++;
                        else
                        {
                            break;
                        }
                    } while (true);
                    return isMatchInner(s, sb, se, p, pb, pe);
                }
            }
        }
        else if (plen == 1)
        {
            if (p[pb] == '.')
            {
                return isMatchInner(s, sb + 1, se, p, pb + 1, pe);
            }
            else
            {
                if (s[sb] != p[pb])
                    return false;
                return isMatchInner(s, sb + 1, se, p, pb + 1, pe);
            }
        }
        return false;
    }
};
