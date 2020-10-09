class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &A)
  {
    vector<vector<string>> ans;

    if (A.size() == 0)
      return ans;

    unordered_map<string, vector<string>> hash;

    for (string s : A)
    {
      string temp = s;
      sort(temp.begin(), temp.end());
      hash[temp].push_back(s);
    }

    for (auto element : hash)
    {
      ans.push_back(element.second);
    }

    return ans;
  }
};
