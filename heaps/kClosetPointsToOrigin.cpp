class Solution
{
public:
  struct compare
  {
    bool operator()(vector<int> &p, vector<int> &q)
    {
      return (p[0] * p[0] + p[1] * p[1]) < (q[0] * q[0] + q[1] * q[1]);
    }
  };

  vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
  {
    vector<vector<int>> ans;

    // base case
    if (points.size() == 0 || K <= 0)
      return ans;

    // max heap
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;

    for (auto pt : points)
    {
      pq.push(pt);

      if (pq.size() > K)
        pq.pop();
    }

    while (pq.empty() == false)
    {
      ans.push_back(pq.top());
      pq.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};
