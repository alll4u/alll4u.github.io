---
layout: post
title: LeetCode 300. Longest Increasing Subsequence
category: project
description: Dinge von Hand gemacht.
---
看了一个动态规划的题[Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/description/)

* [LeetCode题解O(nlogn)](https://leetcode.com/problems/longest-increasing-subsequence/discuss/74824/JavaPython-Binary-search-O(nlogn)-time-with-explanation)

以下是一位印度小哥[Tushar Roy](https://www.youtube.com/channel/UCZLJf_R2sWyUtXSKiKlyvAw)的两个Youtube题解视频

* [O(n^2)的算法](https://www.youtube.com/watch?v=CE2b_-XfVDk)的算法
* [O(nlogn)的算法](https://www.youtube.com/watch?v=S9oUiVYEq7E)

印度小哥的英文还是蛮容易听懂的。

这个问题暴力计算是O(2^N)，即列举所有的子序列，判断其是否为上升子序列，找出最大的。
O(N^2)，O(nlogn)的算法，都是Dynamic Programming问题，这是后者的额外数组恰好是有序的，可通过二分查找来确定更新位置。算法细节可以通过服用视频及LeetCode题解获取。

* O(n^2)算法 C++ Code
```
int lengthOfLIS(vector<int>& nums) {
        int result=0;
        int right=1, left=0;
        const auto length = nums.size();
        vector<int> tmp(length, 1);
        for(right=1; right < length; right++){
            for(left=0;left<right;left++){
                if(nums[left]<nums[right] &&
                        tmp[right]<(tmp[left]+1)){
                    tmp[right]=tmp[left]+1;
                }
            }
        }
        for(auto e:tmp){
            result=(e>result)?e:result;
        }
        return result;
    }
```
* O(nlogn)算法 Java Code
```
public int lengthOfLIS(int[] nums) {
    int[] tails = new int[nums.length];
    int size = 0;
    for (int x : nums) {
        int i = 0, j = size;
        while (i != j) {
            int m = (i + j) / 2;
            if (tails[m] < x)
                i = m + 1;
            else
                j = m;
        }
        tails[i] = x;
        if (i == size) ++size;
    }
    return size;
}
```