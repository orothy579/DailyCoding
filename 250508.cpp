// 수 정ㅕ하기 2
// 2751번
// merge sort

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
  int n;   // 입력받을 수의 개수
  int num; // 입력하는 수
  vector<int> nums;

  cin >> n;

  // 입력
  for (int i = 0; i < n; i++)
  {
    cin >> num;
    nums.push_back(num);
  }

  for (int width = 1; width < n; width *= 2)
  {
    vector<int> tmp;

    for (int left = 0; left < n; left += 2 * width)
    {
      int mid = min(left + width, n);
      int right = min(left + 2 * width, n);
      int i = left, j = mid;

      // 병합
      while (i < mid && j < right)
      {
        if (nums[i] <= nums[j])
          tmp.push_back(nums[i++]);
        else
          tmp.push_back(nums[j++]);
      }

      while (i < mid)
        tmp.push_back(nums[i++]);
      while (j < right)
        tmp.push_back(nums[j++]);
    }

    nums = tmp;
  }

  for (int i = 0; i < n; i++)
  {
    cout << nums[i] << "\n";
  }
}