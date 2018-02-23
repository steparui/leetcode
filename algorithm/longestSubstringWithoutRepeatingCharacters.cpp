// Source : https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : shirui
// Data : 2018-02-06

// Given a string, find the length of the longest substring without repeating characters.
// Examples:
// Given "abcabcbb", the answer is "abc", which the length is 3.
// Given "bbbbb", the answer is "b", with the length of 1.
// Given "pwwkew", the answer is "wke", with the length of 3. 
// Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            if(s == "")
                return 0;
        
            vector<string> total;
			
	    for (int i = 0; i <= s.size() - 1; i++)		
	    {
                string temp;
                for(int j = i; j <= s.size() - 1; j++)
                {
                    if (temp.empty())
                    {
                        temp = s[j];
                        continue;
                    } 

                    string::iterator iter = find(temp.begin(), temp.end(), s[j]);
                    if (iter == temp.end())
                        temp += s[j];
                    else
                    {
                        total.push_back(temp);
                        break;
                    }
                }
                total.push_back(temp);
			}

			int length = 0;
			for (auto it : total)
			{
				if (it.size() > length)
					length = it.size();
			}
			return length;
    };
};
