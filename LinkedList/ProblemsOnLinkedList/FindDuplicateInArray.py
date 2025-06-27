'''
287. Find the Duplicate Number

https://leetcode.com/problems/find-the-duplicate-number/

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and using only constant extra space.

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3

Example 3:
Input: nums = [3,3,3,3,3]
Output: 3



EXPLANATION:

 This is a classic use case for applying **Floyd’s Tortoise and Hare cycle detection** algorithm, but instead of using a linked list explicitly, you'll **treat the array as if it defines a linked list** by interpreting the values as pointers. Here’s how to visualize it:

### # 🧠 Linked List Analogy from the Array

Given the array:
```
nums = [1, 3, 4, 2, 2]
          ↑  ↑  ↑  ↑  ↑
          0  1  2  3  4  <-- indices
```

You can think of each index `i` as a *node*, and the value at `nums[i]` as a pointer to the *next node*. So,
```
0 → nums[0] = 1  
1 → nums[1] = 3  
3 → nums[3] = 2  
2 → nums[2] = 4  
4 → nums[4] = 2  ← cycle
```

So the *path* would be:
```
0 → 1 → 3 → 2 → 4 → 2 → ...
```

There's your **cycle**, and the duplicate number (`2`) is the **entry point to the cycle**.

---

### 🐢 Applying Floyd’s Tortoise and Hare

**Phase 1: Find intersection point**
```python
slow = nums[0]
fast = nums[0]

# Move slow by 1 step, fast by 2 steps until they meet
while True:
    slow = nums[slow]
    fast = nums[nums[fast]]
    if slow == fast:
        break
```

**Phase 2: Find entrance to the cycle (duplicate)**
```python
slow = nums[0]
while slow != fast:
    slow = nums[slow]
    fast = nums[fast]
```

At this point, `slow` (or `fast`) is at the **duplicate number**.

---

This works because the duplicate causes multiple indices to point to the same value, which naturally creates a **cycle in the graph** defined by the array.

'''
class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        slow = fast = nums[0]

        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]

            if slow == fast:
                break
        
        # the point now is the time taken for slow and fast pointer to meet is the same, 
        # so lets re-run slow from begininng, and the fast (both slowly) from the cycle, and they would meet again at the cycle start
        slow = nums[0]

        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]
        
        return slow