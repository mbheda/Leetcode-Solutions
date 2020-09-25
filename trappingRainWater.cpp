class Solution
{
public:
  int trap(vector<int> &A)
  {
    if (A.size() == 0)
      return 0;

    int ans = 0;
    int N = A.size();
    vector<int> leftHeight(N, 0);
    vector<int> rightHeight(N, 0);

    int buildingWidth = 1;

    // compute the max height seen so far each building to its left side
    leftHeight[0] = A[0];
    for (int i = 1; i < N; i++)
    {
      leftHeight[i] = max(A[i], leftHeight[i - 1]);
    }

    // compute the max height seen so far for each building to its right side
    rightHeight[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
      rightHeight[i] = max(A[i], rightHeight[i + 1]);
    }

    // calculate the water stored on top of each building. And, sum it up
    for (int i = 0; i < N; i++)
    {
      int perBuildingWater = abs(min(leftHeight[i], rightHeight[i]) - A[i]) * buildingWidth;
      ans += perBuildingWater;
    }

    return ans;
  }
};
