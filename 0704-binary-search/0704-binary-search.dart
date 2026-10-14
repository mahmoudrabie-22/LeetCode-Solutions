class Solution {
  int search(List<int> nums, int target) {
    int s=0,e = nums.length -1;
    int mid = (s + e) ~/ 2;
    while (s <= e) {
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        s = mid + 1;
      } else {
        e = mid - 1;
      }
      mid = (s + e) ~/ 2;
    }
    return -1;
  }
}