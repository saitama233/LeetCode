#include <stdarg.h>
#include <iostream>
#include <vector>
using namespace std;

//用cnt来标明后面要比较的个数，不然va_arg好像无法判断参数是否没有了
int minimum(int cnt, ...)
{
    int tmp, min;
    va_list ap;
    va_start(ap, cnt);

    min = va_arg(ap, int);
    for (int i = 0; i < cnt - 1; i++) {
        tmp = va_arg(ap, int);
        if (tmp < min)
            min = tmp;
    }
    return min;
}

//vector没法像数组那样直接用nums1+div，就多加了两个参数，看起来麻烦了很多
double findkth(int k, vector<int> &nums1, int idx1, 
        vector<int> &nums2, int idx2)
{
    if (!(nums1.size() - idx1))
        return nums2[idx2+k-1];
    else if (!(nums2.size() - idx2))
        return nums1[idx1+k-1];

    if (k == 1)
        return minimum(2, nums1[idx1], nums2[idx2]);
    
    int div = minimum(3, k/2, nums1.size()-idx1, nums2.size()-idx2);
    if (nums1[idx1+div - 1] < nums2[idx2+div - 1]) {
        return findkth(k - div, nums1, idx1+div, nums2, idx2);
    } else if (nums1[idx1+div - 1] > nums2[idx2+div - 1]) {
        return findkth(k - div, nums1, idx1, nums2, idx2+div);
    } else {
        return nums1[idx1+div - 1];
    }
}

class Solution1 {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            double median;
            int totallength = nums1.size() + nums2.size();
            int idx1 = 0, idx2 = 0;
            if (totallength % 2) {
                median = findkth(totallength / 2 + 1, nums1, idx1, 
                        nums2, idx2);
            } else {
                double a = findkth(totallength / 2, nums1, idx1, 
                        nums2, idx2);
                double b = findkth(totallength / 2 + 1, nums1, idx1, 
                        nums2, idx2);
                // cout << totallength / 2 - 1 << endl;
                // cout << totallength / 2 << endl;
                // cout << a << endl;
                // cout << b << endl;
                median = (a + b) / 2; 
            }
            return median;
        }
};

int main(void)
{
    vector<int> nums1 = {10, 30, 50, 60, 90};
    // vector<int> nums1 = {10};
    // vector<int> nums2 = {20, 40, 60, 100, 120, 130, 140};
    vector<int> nums2 = {20};
    double median;

    Solution1 s1;
    // int min = minimum(5, 10, 2, 30, 5, 6);
    // cout << "minimum: " << min << endl;
    median = s1.findMedianSortedArrays(nums1, nums2);
    cout << "Median is: " << median << endl;
    return 0;
}
