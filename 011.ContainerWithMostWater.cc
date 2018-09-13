#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// 类似于sliding window，j不断向右遍历，不断的判断此时是否比最大值大，
// 大的话则更新max并移动右边界
// 只有右边界比左边界大的时候才试图向左移动左边界并更新max
class solution1 {
public:
    int maxarea(vector<int>& height) {
        int left = 0, right = 0, max = 0, tmp = 0;
        int h = 0;
        int size = height.size();
        // j和右面的边界相关
        for (int j = 1; j < size; j++) {
            h = height[left] < height[j] ? height[left] : height[j];
            tmp = (j-left) * h;
            if (tmp > max) {
                max = tmp;
                right = j;
            }
            // 这样可以减少暴力枚举的次数，只有右边界比左边界大才试图
            // 把左边界往右移动
            if (height[right] > height[left]) {
                // i和左面的边界相关
                for (int i = left; i < right; i++) {
                    h = height[i] < height[right] ? 
                        height[i] : height[right];
                    tmp = (right-i) * h;
                    if (tmp > max) {
                        max = tmp;
                        left = i;
                    }
                }
            }
        }
        return max;
    } 
};

// 扫了一眼网上的思路，自己写的，效率和网上的比起来差一些
class solution2 {
public:
    int maxarea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int i = left, j = right;
        int h = height[left] < height[right] ? height[left] : height[right];
        int max = h * (right - left);
        int tmp;

        while (i < j) {
            while (i < right) {
                h = height[i] < height[right] ? height[i] : height[right];
                tmp = h * (right - i);
                if (tmp > max) {
                    max = tmp;
                    left = i;
                    break;
                }
                i++;
            }
            while (j > left) {
                h = height[left] < height[j] ? height[left] : height[j];
                tmp = h * (j - left);
                if (tmp > max) {
                    max = tmp;
                    right = j;
                    break;
                }
                j--;
            }
        }
        return max;
    }
};

// 网上的答案
class solution3 {
public:
    int maxarea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int res = 0;
        int tmp = 0;
        while (left < right) {
            tmp = min(height[left], height[right]) * (right - left);
            res = max(res, tmp);
            height[left] < height[right] ? left++ : right--;
        }
        return res;
    }
private:
    int max(int a, int b) {
        return a > b ? a : b;
    }
    int min(int a, int b) {
        return a < b ? a : b;
    }
};

int main(void)
{
    vector<int> array;
    int num;
    solution3 s;

    srand(time(0));
    while (1) {
        cout << "Ctrl+c to quit" << endl;
        cout << "Please input the size:" << endl;
        cin >> num;
        // 最开始用的是array.empty()来清空数据，搞错了
        array.clear();
        for (int i = 0; i < num; i++) {
            array.push_back(rand()%100);
        }
        cout << "The array is:\n";
        for (int i = 0; i < num; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
        cout << "The maxarea is:" << s.maxarea(array) << endl;
    }
    return 0;
}
