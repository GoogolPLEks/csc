#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>


std::vector<int> merge(std::vector<int> arr1, std::vector<int> arr2) {

    unsigned long arr1_size = arr1.size();
    unsigned long arr2_size = arr2.size();

    std::vector<int> merged_arr(arr1_size + arr2_size);

    unsigned long i=0, j=0;

    while ((i < arr1_size) and (j < arr2_size)) {
        if (arr1[i] <= arr2[j]) {
            merged_arr[i + j] = arr1[i];
            i++;
        } else {
            merged_arr[i + j] = arr2[j];
            j++;
        }
    }

    if (i == arr1_size) {
        while (j < arr2_size) {
            merged_arr[i + j] = arr2[j];
            j++;
        }
    }
    if (j == arr2_size) {
        while (i < arr1_size) {
            merged_arr[i + j] = arr1[i];
            i++;
        }
    }

    assert(merged_arr.size() == arr1_size + arr2_size);

    return merged_arr;

}


std::vector<int> merge_sort(std::vector<int> &arr, unsigned long l, unsigned long r) {
    if (l + 1 < r) {
        unsigned long m = l + (r - l) / 2;
        std::vector<int> left = merge_sort(arr, l, m);
        std::vector<int> right = merge_sort(arr, m, r);
        return merge(left, right);
    } else {
        unsigned long m = l + (r - l) / 2;
        std::vector<int> helper(1);
        helper[0] = arr[m];
        return helper;
    }

}


int count_inverse(std::vector <int> &arr) {

    std::vector<int> sorted_array = merge_sort(arr, 0, arr.size());

    for (auto ar: sorted_array) {
        std::cout << ar << " ";
    }

    return 0;
}


int main() {
    unsigned int n;
    std::cin >> n;

    std::vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int answer = count_inverse(arr);

    std::cout << answer;

    return 0;
}


