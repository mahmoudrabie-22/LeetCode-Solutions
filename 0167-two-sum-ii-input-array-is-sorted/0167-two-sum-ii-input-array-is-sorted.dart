class Solution {
  List<int> twoSum(List<int> numbers, int target) {
    int s = 0, e = numbers.length - 1;
    List<int> result = [];
    while (s < e) {
      if (numbers[s] + numbers[e] == target) {
        result.add(s+1);
        result.add(e+1);
        return result;
      } else if (numbers[s] + numbers[e] < target) {
        s++;
      } else
        e--;
    }
    return result;
  }
}