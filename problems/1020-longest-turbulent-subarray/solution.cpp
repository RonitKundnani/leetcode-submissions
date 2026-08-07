class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int left = 0;
    int best = 1;
    int prev_direction = 0;
    for (int right = 0; right < static_cast<int>(arr.size()) - 1; ++right) {
      if (arr[right] > arr[right + 1]) {
        if (!(prev_direction < 0)) {
          left = right;
        }
        prev_direction = 1;
        best = std::max(best, (right + 1) - left + 1);
      } else if (arr[right] < arr[right + 1]) {
        if (!(prev_direction > 0)) {
          left = right;
        }
        prev_direction = -1;
        best = std::max(best, (right + 1) - left + 1);
      } else if (arr[right] == arr[right + 1]) {
        left = right + 1;
        prev_direction = 0;
      }
    }
    return best;
    }
};
