class Solution {
  List<List<int>> threeSum(List<int> nums) {
    List<List<int>> res = [];
    nums.sort();
    for (var i = 0; i < nums.length; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      int s = i + 1, e = nums.length - 1;
      while (s < e) {
        if (nums[s] + nums[e] == -nums[i]) {
          res.add([nums[i], nums[s], nums[e]]);
          s++;
          e--;
          while (s < e && nums[s] == nums[s - 1]) {
            s++;
          }
          while (e > s && nums[e] == nums[e + 1]) {
            e--;
          }
        } else if (nums[s] + nums[e] < -nums[i]) {
          s++;
        } else {
          e--;
        }
      }
    }
    return res;
  }
}