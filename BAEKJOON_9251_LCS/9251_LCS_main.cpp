/*
https://www.acmicpc.net/problem/9251

LCS

����
LCS(Longest Common Subsequence, ���� ���� �κ� ����)������ �� ������ �־����� ��, ����� �κ� ������ �Ǵ� ���� �� ���� �� ���� ã�� �����̴�.

���� ���, ACAYKP�� CAPCAK�� LCS�� ACAK�� �ȴ�.




�Է�
ù° �ٰ� ��° �ٿ� �� ���ڿ��� �־�����. ���ڿ��� ���ĺ� �빮�ڷθ� �̷���� ������, �ִ� 1000���ڷ� �̷���� �ִ�.


���
ù° �ٿ� �Է����� �־��� �� ���ڿ��� LCS�� ���̸� ����Ѵ�.



���� �Է� 1
ACAYKP
CAPCAK


���� ��� 1
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