
#include <iostream>
#include <set>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    set<char> Set;
    int max = 0;
    int start = 0;
    int end = 0;
    while (start < s.size())
    {
        auto it = Set.find(s[start]);
        if (it == Set.end())
        {
            if (start - end + 1 > max)
                max = start - end + 1;
            Set.insert(s[start]);
            start++;
        }
        else
        {
            Set.erase(s[end]);
            end++;
        }
    }
    return max;
}
int main()
{
    string s = "abcabcba";
    int len = lengthOfLongestSubstring(s);
    cout <<"Length of longest substring is : "<< len;
    return 0;
}