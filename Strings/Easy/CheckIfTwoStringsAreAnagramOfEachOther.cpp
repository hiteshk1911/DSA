Problem Statement: Given two strings, check if two strings are anagrams of each other or not.

Examples:

Example 1:
Input: CAT, ACT
Output: true
Explanation: Since the count of every letter of both strings are equal.

Example 2:
Input: RULES, LESRT
Output: false
Explanation: Since the count of U and T  is not equal in both strings.

//Solution 1
Time Complexity: O(nlogn) since sorting function requires nlogn iterations.
Space Complexity: O(1)

bool CheckAnagrams(string str1, string str2)
{
  // Case 1: when both of the strings have different lengths
  if (str1.length() != str2.length())
    return false;

  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());

  // Case 2: check if every character of str1 and str2 matches with each other
  for (int i = 0; i < str1.length(); i++)
  {
    if (str1[i] != str2[i])
      return false;
  }
  return true;
}

//Solution 2
Time Complexity: O(n) where n is the length of string
Space Complexity: O(1)

bool CheckAnagrams(string str1, string str2)
{
  // when both of the strings have different lengths
  if (str1.length() != str2.length())
    return false;

  int freq[26] = {0};
  for (int i = 0; i < str1.length(); i++)
  {
    freq[str1[i] - 'A']++;
  }
  for (int i = 0; i < str2.length(); i++)
  {
    freq[str2[i] - 'A']--;
  }
  for (int i = 0; i < 26; i++)
  {
    if (freq[i] != 0)
      return false;
  }
  return true;
}