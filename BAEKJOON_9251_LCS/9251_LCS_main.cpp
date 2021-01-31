/*
https://www.acmicpc.net/problem/9251

LCS

문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.




입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.


출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.



예제 입력 1
ACAYKP
CAPCAK


예제 출력 1
4

*/

#include <iostream>
#include <string>


using namespace std;
// matrix for save calculated result
int cnt[2][1001];
    
// input string s1, s2
string s1, s2;

int main() {
    cin >> s1 >> s2;
    int lnew = 1;
    int lold = 0;

    // traverse whole matrix with size s1.length() * s2.length()
    /* Sample shape of matrix for given testcase ACAYKP, CAPCAK
     *     A C A Y K P
     *   0 0 0 0 0 0 0 <- save only recent one row
     * C 0 0 1 1 1 1 1 <- new row
     * A 0 1 1 2 2 2 2
     * P 0 1 1 2 2 2 3
     * C 0 1 2 2 2 2 3
     * A 0 1 2 3 3 3 3
     * K 0 1 2 3 3 4 4
     */
    for (char i : s1) {
        for (int j = 0; j < s2.length(); j++) {
            if (i == s2[j]) {
                // if two character in matrix is equal, update calculated value to upper left diagonal + 1
                cnt[lnew][j + 1] = cnt[lold][j] + 1;
            }
            else {
                // otherwise, the calculated value is the larger of the left and top values
                cnt[lnew][j + 1] = max(cnt[lnew][j], cnt[lold][j + 1]);
            }
        }
        // update mark
        swap(lold, lnew);
    }
    cout << cnt[lold][s2.length()];
}