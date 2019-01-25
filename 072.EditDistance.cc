/*
 * 72. Edit Distance
 * Hard
 * 
 * Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
 * You have the following 3 operations permitted on a word:
 * Insert a character
 * Delete a character
 * Replace a character
 *
 * Example 1:
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation: 
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 * 
 * Example 2:
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation: 
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 * Accepted 150,808    Submissions 421,384
 */

#include <string>
using namespace std;

/* 分别比较每个字符，如果相等，比较下个字符，不等的话分别添加，删除和替换，添加的话不真正添加 */
/* 回溯法：用时3h，短些的可以计算，长些的如最后一个testcase会超时，Time Limit Exceeded */
/*
""
""
"algo"
""
""
"push"
"horse"
"ros"
"intention"
"execution"
"intentionintention"
"executionexecution"
*/
class Solution1 {
public:
    int minDistance(string word1, string word2) {
        int dist = 0, mindist = 0;
        dfs(word1, word2, dist, mindist);
        return mindist;
    }
    
    void dfs(string src, string dst, int dist, int &mindist) {
        int idx;
        
        for (idx = 0; idx < src.size() && idx < dst.size(); idx++) { /* 跳过相同的字符 */
            if (src[idx] != dst[idx])
                break;
        }
        
        if (idx == dst.size()) {
            dist += src.size() - idx; /* dst已经结束，如果src还有剩余，将剩余的进行delete操作 */
            if (dist < mindist || !mindist)
                mindist = dist;
            return;
        }
        
        dist++;
        /* 添加 */
        if (idx < dst.size()) /* 条件不成立的话，dst已经空了，没必要再添加了 */
            dfs(src.substr(idx), dst.substr(idx + 1), dist, mindist);
        if (idx < src.size()) { /* 删除和替换是src必须有元素才能操作 */
            /* 删除 */
            dfs(src.substr(idx + 1), dst.substr(idx), dist, mindist);
            /* 替换 */
            dfs(src.substr(idx + 1), dst.substr(idx + 1), dist, mindist);
        }
        dist--;
    }
};

int main()
{
    return 0;
}