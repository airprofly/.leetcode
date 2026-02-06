<div align="center">
  <h1>刷题技巧总结</h1>
</div>

<p align="center">
  <a href="https://opensource.org/licenses/MIT"><img src="https://img.shields.io/badge/License-MIT-yellow.svg" alt="License: MIT" /></a>
</p>

> 本仓库用于记录在刷题过程中总结的一些技巧和经验，方便日后复习和参考。
----

# 技巧列表

## 中间节点 
### 对半分下标问题(思考的时候直接使用 2n 或 2n-1 作为下标带进去算比一下较好理解)
- 当对半分`0~n`下标的问题时，如果为`奇数`,则`i<=(n-1)/2`是不包含中间节点,即后半部分比前半部分多一个节点的;`i<=n/2`则包含中间节点,前面比后面多一个中间节点。
### `快慢指针`可以实现 n 等分问题
- `快慢指针`用于寻找链表的中间节点时,当为`奇`数时,`慢指针`最终指向中间节点;
    ```c++
        if(head==nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 当链表长度为奇数时，slow 指向中间节点
        
        // 可以直接通过 if(fast->next != nullptr) 判断链表长度为偶数还是奇数
        if(fast->next != nullptr){
            // 链表长度为偶数
        } else {
            // 链表长度为奇数，slow 指向中间节点
        }
    ```
    **思路**：`0`号节点废了，后面走的时候，每次走的时候`fast`指针指向的下标都是`slow`指针的`两倍`,所以当最后一个节点下标是`2n`时,则`slow`指针指向`n`号节点,即中间节点.

## 链表
- **痛点**：
  - 无法高效获取长度，无法根据偏移快速访问元素
  - 处理链表时，常常需要使用`哨兵节点(虚拟头节点)`来简化边界条件的处理。
- **双(快慢)指针** 经常用来解决链表中的无法随机访问的问题。
  - **中间**节点 
  - **环形**链表: 
    - **快慢指针**：如果有环，只要一直跑，`快指针`一定会追上`慢指针`,即两指针会相遇,但**不保证**相遇的点是环的入口点,可以使用数学等式推到出位置,看`leetcode 142`题。
       
       - 除了官方数学推理，还可以在相遇时，让一个指针继续走一圈，计算出环的长度 `C`。然后重头开始,让一个指针多走 `C` 步，再让两个指针同时走，最终会在环的入口点相遇。
       
       - 环前面的长度可以直接按照官方解，在相遇后，让一个指针回到头节点，然后两个指针同时走，计算步数，最终会在环的入口点相遇。
    - **标记**：如果节点中数据有范围，可以使用将**走过**(一般使用在原处`标记`或者使用`容器(unorder set等)记录并查找判断`下来)的节点数据标记为一个特殊值(如`INT_MAX`),如果再次遇到该值,则说明有环。即走过的路径`做标记`或者`染色`。
  - **倒数第K**个节点


## 选择 `unorder_map`、`map` 还是`vector(数组)`进行存储
- `map`:
  - 适用于`键值对`中`键`为`非整数`类型的情况，如字符串、浮点数等。
  - 键为`整数`时,但`分布稀疏,范围较大`时也适用。
  - 实现基于`红黑树`，查询、插入、删除的时间复杂度为`O(log n)`。
- `unorder_map`:
    - 适用于`键`为`整数`类型，且`范围较大但`分布较密集`的情况。
    - 实现基于`哈希表`，查询、插入、删除的时间复杂度为`O(1)`的平均时间复杂度，但在最坏情况下可能退化为`O(n)`。
- `vector(数组)`:
  - 适用于`键`为`整数`类型,且`范围较小且分布较密集`的情况。可以实现`O(1)`的查询(通过索引直接访问)。

## 反序问题：反转字符串/数组的方法
- 使用`双指针`法:
  ```cpp
  void reverseString(vector<char>& s) {
      int left = 0, right = s.size() - 1;
      while (left < right) {
          swap(s[left], s[right]);
          left++;
          right--;
      }
  }
  ```
- 使用`标准库`函数:
  ```cpp
  #include <algorithm>
  void reverseString(vector<char>& s) {
      reverse(s.begin(), s.end());
  }
  ```
- 使用`栈`: 栈可以实现`反序`问题,使用`递归`函数也可以,因为递归本质上也是利用了`系统栈`的特性。
  ```cpp
  #include <stack>
  void reverseString(vector<char>& s) {
      stack<char> st;
      for (char c : s) {
          st.push(c);
      }
      for (int i = 0; i < s.size(); i++) {
          s[i] = st.top();
          st.pop();
      }
  }
  ```
## 对于 `字母异位词` 的处理优化方法
**字母异位词**：
> 是指两个有序组合中所有元素相同，但排列顺序不同的组合。比如 "listen" 和 "silent" 就是字母异位词。

**优化技巧**：
- 让这些组合以某个`规则`(如字母升序、降序)进行`排序`，即可以将`字母异位词` 归类到一起，方便后续处理。
  - 这里的`排序`可以优化：
    - 通常使用`快速排序sort()`，时间复杂度为 O(n log n)。
    - 但对于`元素多而值域少，即相同元素重复较多`的情况，可以使用`计数排序`(`桶排`)，时间复杂度可优化至 O(n)。
- `简单但低效`的方法：直接使用`multiset`进行存储和比较
- `hash+链式(vector)`方法：直接使用`各元素值累加`(或者其他去除`位置因素`的计算方法)作为索引,初步缩小搜索范围,优化搜索效率，然后再逐一元素比较。
   - **优点**：
      - 不用考虑位置因素
      - 不用多次比较，只需要计算一次 hash 值，比较一次 hash 数值即可。
   - **注意**：不能直接使用 `hash `值进行比较，因为不同的组合(如`af`和`be`)可能会产生相同的 hash 值（哈希冲突），只能缩小范围，不能直接作为唯一标识。
- **桶排计数**：
  - 对于值域较小(如`字母串`)，可以使用桶排计数`每个字母出现的次数`作为唯一标识;
  - 如果值域范围大，可以使用`哈希函数`对计数结果进行压缩，得到一个较小的唯一标识，利用`unorder_map`进行存储和比较,因为`unorder_map`底层实现就是`hash`，可以实现`O(1)`的平均时间复杂度。

## 枚举所有选择`两个`边界的方法即 $C_n^{2}$
- **双循环枚举(定一(后边界)法)** 内循环从开始到达外循环当前位置，即可枚举所有`两个`边界组合且不重复。可以理解为将`两个动变边界`转化为`定住一个结尾边界,枚举另一个起始边界`的问题。
```cpp
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {// 当 以 i 作为结尾边界时，枚举所有起始边界 j
        // 处理边界 (j, i)
    }
}
```

- **双指针枚举(夹逼法)** 双指针分别指向`两个边界`,根据某种条件移动`左/右`指针,实现剪枝优化。
```cpp
int left = 0, right = n - 1;
while (left < right) {
    int h = min(height[left], height[right]);
    area = max(area, (right - left) * h);  
    while (height[left] <= h && left < right) left++; // 一定不满足条件，移动左指针，实现剪枝优化
    while (height[right] <= h && left < right) right--; // 一定不满足条件，移动右指针，实现剪枝优化
}
```

## 凑出两个数的和为目标值的方法
- **双指针法**：
  - 排序成`有序`数组、
  - 通过`左右指针`向中间移动，寻找符合条件的两个数。
```cpp
sort(nums.begin(), nums.end()); 
vector<vector<int>> res;
int left = 0, right = nums.size() - 1;
while (left < right) {
    int sum = nums[left] + nums[right];
    if (sum == target) { // 找到一组解
        res.push_back({nums[left], nums[right]});
        while (left < right && nums[left] == nums[left + 1]) left++; // 跳过重复元素
        while (left < right && nums[right] == nums[right - 1]) right--; 
        left++;
        right--;
    } else if (sum < target) { // 和小于目标值，左指针右移增大和
        left++;
    } else {  // 和大于目标值，右指针左移减小和
        right--;
    }
}
```

## 单调栈
- **单调栈** 是一种特殊的栈结构，栈内元素保持单调递增或单调递减的顺序。
- **特点**：
  - **存储顺序**：栈内元素按照某种顺序排列（递增或递减）。
  - **操作规则**：在入栈时，若新元素违反了单调性，则弹出栈顶元素，直到栈内元素重新满足单调性,这样相当于将前面比当前元素小的元素都"清除"掉了，直接压缩掉了不必要的比较，后面比较时就不需要再考虑这些元素了，只需要直接考虑这个大的元素即可。
  - **应用场景**：
    - 常用于解决需要频繁查询`最大值`或`最小值`的问题，如滑动窗口最大值、柱状图中的最大矩形面积等。
    - 栈中元素存储都是大于当前元素的元素，即可以查询前面`大于`当前元素的`最近`元素,因为`出栈压缩`处理省去了很多不必要的比较。
```C++
for(int i=0;i<nums.size();i++){
    while(!st.empty()&&st.top()<=nums[i]){
        st.pop(); 
    }
    st.push(nums[i]); // 技巧: 如果需要存储的值有序,可以存储索引而不是值本身，存索引相当于存了值，因为可以通过运行时间接访问获取值。
} 
```
- **典型应用**：
  - **229.滑动窗口最大值**
    - **思路**：固定大小的滑动窗口，寻找每次滑动时的最大值。则定住`右边界`，维护一个单调栈，则单调栈里维护的都是比`当前右边界值`大的元素，每次要实现进一步`修改(突破)`的元素的时候所需要访问的元素(因为栈顶是比当前元素大的最近的元素，如果需要再突破，就要走到栈顶倒数第二元素的位置才有可能增大了，突破了)。由于有窗口大小限制，所以在栈里面存索引，方便判断是否在窗口内，而且是升序，在栈里找在索引范围内的可以可以实现**突破**的依次索引值，其中第一个在索引范围内的就是当前窗口的最大值。
    ```cpp
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
          vector<int> st;
          vector<int> ret;
          for(int i=0;i<nums.size();i++){
              while(!st.empty()&&nums[st.back()]<=nums[i]){
                  st.pop_back();
              }
              st.push_back(i);
              if(i<k-1)continue;
              vector<int>::iterator it=lower_bound(st.begin(),st.end(),i-k+1);
              ret.push_back(nums[*it]);
          }
          return ret;
      }
    ```  
    - 这个题目还可以**理解**为：以**右边界**这个数为起点，不断向**左**突破`k`个数，找到`k`个数中最大的那个数。

## 稀疏表(Sparse Table,st 表)
- **稀疏表** 是一种用于高效查询**静态(不动态修改值)**数组区间最值(`RMQ`,静态区间最值查询)的数据结构.
- **实现步骤**：
  - **预处理**：构建稀疏表，时间复杂度为 O(n log n)。
  ![alt text](images/image.png)
  - **查询**：使用预处理好的稀疏表进行区间最值查询，时间复杂度为 O(1)。
  ![alt text](images/image-1.png)
  ```C++
  #include <iostream>
  #include <vector>
  #include <cmath>
  #include <algorithm>

  using namespace std;

  const int MAXN = 100005;
  const int K = 20; // 2^20 > 100000，足够覆盖最大长度

  int st[MAXN][K]; // ST表数组
  int lg[MAXN];    // 预处理 log 值，避免使用 std::log2 函数太慢,而且经常访问

  // 1. 预处理 Log 数组 (求 log2(i) 向下取整)
  void initLog(int n) {
      lg[1] = 0;
      for (int i = 2; i <= n; i++)
          lg[i] = lg[i / 2] + 1; // log(i)=log(i/2*2)=log(i/2)+1
  }

  // 2. 构建 ST 表
  void buildST(const vector<int>& arr) {
      int n = arr.size();

      // 初始化长度为 1 的区间
      for (int i = 0; i < n; i++)
          st[i][0] = arr[i];

      // 倍增计算
      // j 代表长度指数，i 代表起点
      for (int j = 1; j <= K; j++) {
          for (int i = 0; i + (1 << j) - 1 < n; i++) {
              st[i][j] = max(st[i][j-1], st[i + (1 << (j-1))][j-1]);
          }
      }
  }

  // 3. 查询
  int query(int L, int R) {
      int k = lg[R - L + 1];
      // 两个区间：从 L 开始长 2^k，和从 R 结尾长 2^k
      return max(st[L][k], st[R - (1 << k) + 1][k]);
  }

  int main() {
      vector<int> nums = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
      initLog(nums.size());
      buildST(nums);

      cout << "Max in [2, 6] (5, 7, 9, 2, 4): " << query(2, 6) << endl; // 输出 9
      return 0;
  }
  ```
- **适用场景**：
  - 适用于需要频繁查询数组区间(区间可以**变化**)`最值`的场景，且数组内容不发生变化的情况。
  ![alt text](images/image-2.png)
  - 这里每一个`j`层对应处理不同区间长度的查询。如果查询长度是`固定`的,可以不用构建完整的稀疏表,只需要构建对应长度的那一层即可,节省空间和预处理时间,不过有稍微`改动`.采用`滑动窗口最大值`的思路,或者`分块+预处理`的方法即可。
  即：先将分块成`n[nk]~n[n(k+1)-1]`，然后每次查询必落在两块之间，即`max(preMax[r], sufMax[l])`，其中`preMax`表示每块的前缀最大值，`sufMax`表示每块的后缀最大值。
    ```cpp
    class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> prefixMax(n), suffixMax(n);
            for (int i = 0; i < n; ++i) {
                if (i % k == 0) {
                    prefixMax[i] = nums[i];
                }
                else {
                    prefixMax[i] = max(prefixMax[i - 1], nums[i]);
                }
            }
            for (int i = n - 1; i >= 0; --i) {
                if (i == n - 1 || (i + 1) % k == 0) {
                    suffixMax[i] = nums[i];
                }
                else {
                    suffixMax[i] = max(suffixMax[i + 1], nums[i]);
                }
            }

            vector<int> ans;
            for (int i = 0; i <= n - k; ++i) {
                ans.push_back(max(suffixMax[i], prefixMax[i + k - 1]));
            }
            return ans;
        }
    };
    ```

## 树状数组
- **树状数组** (Fenwick Tree) 是一种用于高效处理`数组前缀(区间和)`和查询和`单点更新`的数据结构。
![alt text](images/image-3.png)
同`lowbit`的节点属于同一层，属于兄弟，父节点为`lowbit`的两倍,每个节点管理着`lowbit`个元素。

- **注意**: 开始必须`索引从1开始`,即`tree[0]`不存储任何值,方便计算父节点和子节点。
- **实现步骤**：
  - **初始化**：构建树状数组，时间复杂度为 O(n log n)。
  - **更新**：更新数组中的某个元素，时间复杂度为 O(log n)。
  - **查询**：查询数组的前缀和，时间复杂度为 O(log n)。
  ```C++
  class FenwickTree {
  private:
      vector<int> tree;
      int n;
  public:
      FenwickTree(int size) : n(size) {
          tree.resize(n + 1, 0); // 树状数组索引从1开始
      } 
      // 更新操作: 在索引 idx 处增加 delta
      void update(int idx, int delta) {
          while (idx <= n) {
              tree[idx] += delta;
              idx += idx & -idx; // 移动到下一个节点
          }
      }
      // 查询操作: 获取前缀和 [1, idx]
      int query(int idx) {
          int sum = 0;
          while (idx > 0) {
              sum += tree[idx];
              idx -= idx & -idx; // 移动到父节点
          }
          return sum;
      }
      // 获取区间和 [left, right]
      int rangeQuery(int left, int right) {
          return query(right) - query(left - 1);
      }
  };
  ```
  - **适用场景**：
    - 适用于需要频繁进行`前缀和(区间和)`查询、`区间最大值`和`单点更新`的场景，如动态数组求和、频率统计等。
    - 如果需要处理`区间更新`和`区间查询`，可以考虑使用`差分数组`结合树状数组，或者使用`线段树`.

## 线段树
**线段树** (Segment Tr) 是一种用于高效处理`数组区间查询`和`区间更新`的数据结构。

**应用场景**：
- `动态修改`数组中的元素值。
- 频繁查询数组的`区间和`、`区间最值`等。
- 适用于需要处理`区间更新`和`区间查询`的场景,`树状数组`无法满足需求时使用。
**实现步骤**：

- **构建**：构建线段树，时间复杂度为 O(n)
- **更新**：更新数组中的某个元素，时间复杂度为 O(log n)
- **查询**：查询数组的区间和，时间复杂度为 O(log n)
```C++
class SegmentTree {
private:
    vector<int> tree;
    int n;
public:
    SegmentTree(int size) : n(size) {
        tree.resize(4 * n, 0); // 线段树大小一般为 4n
    }
    void pushUp(int node) {
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    // 构建线段树
    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            pushUp(node);
        }
    }
    // 更新操作: 在索引 idx 处更新为 val
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;  
            if (idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            pushUp(node);
        }
    }
    // 查询操作: 获取区间和 [L, R]
    int query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return 0; // 区间不重叠
        }
        if (L <= start && end <= R) {
            return tree[node]; // 区间完全重叠
        }
        int mid = (start + end) / 2;
        int p1 = query(2 * node, start, mid, L, R);
        int p2 = query(2 * node + 1, mid + 1, end, L, R);
        return p1 + p2; // 合并结果
    }
};
```
### 区间修改
![alt text](images/image-4.png)
- **区间修改**：如果需要对一个区间内的所有元素进行加法、赋值等操作，并且仍然要求高效的区间查询，线段树需要支持**懒惰标记（Lazy Propagation）**。
- **懒惰标记**：当对某个区间进行修改时，暂时不递归修改所有子节点，而是打上标记，等到需要用到子节点时再进行下传和更新，避免重复操作，提高效率。

**示例：区间加法的懒惰标记线段树实现（伪代码）**：

```cpp
class SegmentTree {
private:
  vector<int> tree, lazy;
  int n;
public:
  SegmentTree(int size) : n(size) {
    tree.resize(4 * n, 0);
    lazy.resize(4 * n, 0);
  }
  void pushUp(int node) {
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
  void pushDown(int node, int start, int end) {
    if (lazy[node] != 0) {
      int mid = (start + end) / 2;
      tree[2 * node] += (mid - start + 1) * lazy[node];
      tree[2 * node + 1] += (end - mid) * lazy[node];
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
      lazy[node] = 0;
    }
  }
  // 区间加法更新 [l, r] 区间加 val
  void updateRange(int node, int start, int end, int l, int r, int val) {
    if (r < start || end < l) return;
    if (l <= start && end <= r) {
      tree[node] += (end - start + 1) * val;
      lazy[node] += val;
      return;
    }
    pushDown(node, start, end);
    int mid = (start + end) / 2;
    updateRange(2 * node, start, mid, l, r, val);
    updateRange(2 * node + 1, mid + 1, end, l, r, val);
    pushUp(node);
  }
  // 区间查询 [L, R]
  int query(int node, int start, int end, int L, int R) {
    if (R < start || end < L) return 0;
    if (L <= start && end <= R) return tree[node];
    pushDown(node, start, end);
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, L, R) + query(2 * node + 1, mid + 1, end, L, R);
  }
};
```
- **适用场景**：需要频繁对区间进行加法、赋值等操作，并且需要高效查询区间和、区间最值等。

## 区间最值、区间和、区间修改总结
- **动态修改**：(`线段树`或者`树状数组`)
  - **单点修改**：使用`树状数组`或`线段树`，时间复杂度 O(log n)
  - **区间修改**：使用`线段树`(带懒惰标记)，时间复杂度 O(log n)
- **静态**:(不修改数组值)
  - **在线查询**：使用`稀疏表`，时间复杂度 O(1)
  - **离线查询**：使用`单调栈`,预先指导所有要查询的区间即称为`离线查询`，时间复杂度 O(n)
- **区间查询**：
  - **区间和**：使用`树状数组`或`线段树`，时间复杂度 O(log n)
  - **区间最值**：使用`稀疏表`(静态数组)或`线段树`(动态数组)，时间复杂度 O(1) 或 O(log n)

| 数据结构 | 适用场景及对应复杂度|
| --- | --- | 
| 线段树 | 1. 区间和 O(log n) 2.区间最值 O(log n) 3.**区间修改**(独有)O(log n) |
| 树状数组 | 1. 区间和 O(log n) 2.**单点修改** O(log n) |
| 稀疏表 | 1. **区间最值** O(1) (静态数组) |
| 单调栈 | 1. **区间最值** O(n) (**离线**查询) |
| 前缀和数组 | 1. **区间和** O(1) (静态数组) |
| 差分数组 | 1. **区间修改** O(1) (静态数组) |