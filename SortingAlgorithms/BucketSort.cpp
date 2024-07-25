const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

constexpr int LIMIT = 8;

class Solution {
    void bubble_sort(vector<int>& nums, const int begin, const int end) const {
        bool repeat = true;
        while (repeat) {
            repeat = false;
            for (int i = begin; i + 1 < end; i++) {
                if (nums[i + 1] < nums[i]) {
                    swap(nums[i + 1], nums[i]);
                    repeat = true;
                }
            }
        }
    }

    void bubble_sort(vector<int>& nums) const {
        bubble_sort(nums, 0, nums.size());
    }

    void select_sort(vector<int>& nums) const {
        for (int i = 0; i + 1 < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] < nums[i])
                    swap(nums[j], nums[i]);
            }
        }
    }

    void quick_sort(vector<int>& nums, vector<int>& data,
                    const int begin) const {
        if (data.size() < LIMIT) {
            bubble_sort(data);
            if (&nums == &data)
                return;
            int j = begin;
            for (int i = 0; i < data.size();)
                nums[j++] = data[i++];
            return;
        }

        const int PIVOT =
            (data[0] + data[data.size() / 2] + data[data.size() - 1]) / 3;

        vector<int> smaller;
        vector<int> equal;
        vector<int> greater;

        for (int i = 0; i < data.size(); ++i) {
            if (data[i] < PIVOT)
                smaller.push_back(data[i]);
            else if (PIVOT < data[i])
                greater.push_back(data[i]);
            else
                equal.push_back(data[i]);
        }

        int j = begin + smaller.size();
        for (int i = 0; i < equal.size();)
            nums[j++] = equal[i++];

        quick_sort(nums, smaller, begin);
        quick_sort(nums, greater, begin + smaller.size() + equal.size());
    }

    void quick_sort(vector<int>& nums) const { quick_sort(nums, nums, 0); }

    void merge_sort(vector<int>& nums, const int begin, const int end) const {
        if (end - begin < LIMIT) {
            bubble_sort(nums, begin, end);
            return;
        }

        const int half = (end - begin) / 2 + begin;

        merge_sort(nums, begin, half);
        merge_sort(nums, half, end);

        vector<int> tmp(nums.begin() + begin, nums.begin() + half);

        int i = 0;
        int j = half;
        int k = begin;
        while (i < tmp.size() and j < end) {
            if (tmp[i] < nums[j])
                nums[k++] = tmp[i++];
            else
                nums[k++] = nums[j++];
        }

        while (i < tmp.size())
            nums[k++] = tmp[i++];
    }

    void merge_sort(vector<int>& nums) const {
        merge_sort(nums, 0, nums.size());
    }

    void min_max(const vector<int>& nums, int& MIN, int& MAX) const {
        MIN = nums[0];
        MAX = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > MAX)
                MAX = nums[i];
            else if (nums[i] < MIN)
                MIN = nums[i];
        }
    }

    int index(const int MIN, const int MAX, const int size,
              const int val) const {
        return size * (long int)(val - MIN) / (MAX - MIN + 1);
    }

    void bucket_sort(vector<int>& nums, const int MIN, const int MAX) const {
        const int BUCKET = nums.size();
        vector<vector<int>> data(BUCKET);
        for (int i : nums)
            data[index(MIN, MAX, BUCKET, i)].push_back(i);

        int j = 0;
        for (auto& it : data) {
            counting_sort(it);
            for (int i : it)
                nums[j++] = i;
        }
    }

    void bucket_sort(vector<int>& nums) const {
        if (nums.size() < LIMIT) {
            bubble_sort(nums);
            return;
        }

        int MIN, MAX;
        min_max(nums, MIN, MAX);

        bucket_sort(nums, MIN, MAX);
    }

    void counting_sort(vector<int>& nums, const int MIN, const int MAX) const {
        const int BUCKET = MAX - MIN + 1;

        vector<int> data(BUCKET, 0);
        for (int i : nums)
            ++data[i - MIN];

        int k = 0;
        for (int i = 0; i < BUCKET; ++i) {
            for (int j = 0; j < data[i]; ++j)
                nums[k++] = i + MIN;
        }
    }

    void counting_sort(vector<int>& nums) const {
        if (nums.size() < LIMIT) {
            bubble_sort(nums);
            return;
        }

        int MIN, MAX;
        min_max(nums, MIN, MAX);

        counting_sort(nums, MIN, MAX);
    }

    void count_buck_sort(vector<int>& nums) const {
        if (nums.size() < LIMIT) {
            bubble_sort(nums);
            return;
        }

        int MIN, MAX;
        min_max(nums, MIN, MAX);

        if (MAX > nums.size() * log2(nums.size()) + MIN)
            bucket_sort(nums, MIN, MAX);
        else
            counting_sort(nums, MIN, MAX);
    }

public:
    vector<int> sortArray(vector<int>& nums) const {
        count_buck_sort(nums);
        //sort(nums.begin(), nums.end());
        return nums;
    }
};