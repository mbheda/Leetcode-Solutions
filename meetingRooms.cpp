class Solution
{
public:
  static bool compare(const vector<int> &A, const vector<int> &B)
  {
    return A[0] < B[0];
  }

  bool canAttendMeetings(vector<vector<int>> &A)
  {
    if (A.size() == 0)
      return true;

    sort(A.begin(), A.end());

    for (int i = 1; i < A.size(); i++)
    {
      if (A[i][0] < A[i - 1][1])
        return false;
    }
    return true;
  }
};
