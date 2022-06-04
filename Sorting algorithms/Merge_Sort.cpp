class Solution {
public:
    int n;
    vector<int>arr;

    vector<int> sortArray(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        mergeSort(0, n - 1);
        return arr;
    }

    void mergeSort(int l, int r) {
        if (l < r) {
            int mid = (l + r) / 2;
            mergeSort(l, mid);
            mergeSort(mid + 1, r);
            merge(l, mid, r);
        }
    }

    void merge(int l, int mid, int r) {
        vector<int>mergedArr;
        int i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                mergedArr.push_back(arr[i]);
                i++;
            }
            else {
                mergedArr.push_back(arr[j]);
                j++;
            }
        }

        while (i <= mid) mergedArr.push_back(arr[i]), i++;
        while (j <= r)  mergedArr.push_back(arr[j]), j++;

        int id = l;
        for (auto val : mergedArr) {
            arr[id++] = val;
        }
    }
};