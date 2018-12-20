#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    void rotate(vector<vector<int>> &matrix) {
        int x, y, cur, next = 0;
        int tmpx;
        int len = matrix.size();
        float center = (len - 1) / 2.0;

        for (int i = 0; i < len / 2; i++) {
            for (int j = 0; j <= (len - 1) / 2; j++) {
                x = i;
                y = j;
                cur = matrix[i][j];
                for (int idx = 0; idx < 4; idx++) {
                    /* matrix[center + (y - center)][center - (x - center)] 为下一个 */
                    next = matrix[y][center - (x - center)];
                    matrix[y][center - (x - center)] = cur;
                    cur = next;

                    tmpx = x;
                    x = y;
                    y = center - (tmpx - center);
                }
            }
        }
    }
};

void print_vec(vector<vector<int>> &vvec)
{
    cout << '{' << endl;
    for (int i = 0; i < vvec.size(); i++) {
        cout << '{';
        for (int j = 0; j < vvec[i].size(); j++) {
            cout << vvec[i][j];
            cout << (j + 1 == vvec[i].size() ? "" : ",");
        }
        cout << '}' << endl;
    }
    cout << '}' << endl;
}

int main()
{
    Solution1 s;
    vector<vector<int>> v1 = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<vector<int>> v2 = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};

    s.rotate(v1);
    print_vec(v1);

    s.rotate(v2);
    print_vec(v2);

    return 0;
}
