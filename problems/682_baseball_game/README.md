# 題目名稱

## 題目連結

- LeetCode:https://leetcode.com/problems/baseball-game/description/
- Source issue:https://github.com/tiffanyfan1015/leetcode_practice/issues/29

## 解題思路
stack

## 演算法
1. 建立 vector<int> scores
2. 依序處理每個 operation
3. 根據 operation 更新 scores
4. 最後將 scores 全部加總

## 複雜度

- Time:O(n)
- Space:O(n)

## 實作細節
```
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        for(int i = 0;i<operations.size();i++){
            if(operations[i] == "+"){
                scores.push_back(scores[scores.size() - 1] + scores[scores.size() - 2]);
            }
            else if (operations[i] == "D"){
                scores.push_back(scores.back() * 2);
            }
            else if (operations[i] == "C"){
                scores.pop_back();
            }
            else {
                scores.push_back(stoi(operations[i]));
            }
        }
        int sum = 0;
        for (int i = 0;i <scores.size();i++){
            sum += scores[i];
        }
        return sum;
    }
};
```

## 易錯點
- `operations` 裡面是 string
- `scores` 裡面是 int
- 只有從 `operations` 讀數字時需要 `stoi()`