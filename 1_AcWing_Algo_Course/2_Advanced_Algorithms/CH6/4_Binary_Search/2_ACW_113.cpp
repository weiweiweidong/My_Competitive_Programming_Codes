// 备注：这是一道交互题

// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

// 👇因为会报错，这里把代码整个注释掉了
/*

class Solution {
   public:
    vector<int> specialSort(int N) {
        vector<int> res(1, 1);

        // 从2开始，将每个数字找到位置并插入到res中
        for (int i = 2; i <= N; i++) {
            int l = 0, r = res.size() - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                // 判断 res[mid] 与当前值 i 的关系
                if (compare(res[mid], i))
                    // 若为true，说明 res[mid] 小于 i，应该往右边继续找
                    l = mid;
                else
                    // 若为false，说明 res[mid] 大于 i，应该往右边继续找
                    r = mid - 1;
            }

            // res 扩一个位置
            res.push_back(i);
            // 从后往前，把插入的i逐渐转到对应的位置去
            for (int j = res.size() - 2; j > r; j--)
                swap(res[j], res[j + 1]);
            // 最后判断一下 r 位置的值
            if (compare(i, res[r]))
                swap(res[r], res[r + 1]);
        }

        return res;
    }
};

*/
