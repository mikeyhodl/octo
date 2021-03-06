#include <iostream>
#include<string>
using namespace std;
int max(int a, int b)
{
 if (a > b)
 return a;
 else
 return b;
}
int LCS(string s1, string s2)
{
 int x = s1.length();
 int y = s2.length();
 int m[x + 1][y + 1];
 for (int i = 0; i <= y; i++)
 {
 m[0][i] = 0;
 }
 for (int j = 0; j <= x; j++)
 {
 m[j][0] = 0;
 }
 for (int i = 1; i <= s1.length(); i++)
 {
 for (int j = 1; j <= s2.length(); j++)
 {
 if (s1[i - 1] == s2[j - 1])
 {
 m[i][j] = 1 + m[i - 1][j - 1];
 }
 else
 {
 m[i][j] = max(m[i - 1][j], m[i][j - 1]);
 }
 }
 }
 int r = m[x][y];
 cout << "Length of longest common subsequence is: \n" << r << endl;
 int j = x;
 int i = y;
 char s3[x];
 int in = 0;
 int la;
 if (x > y)
 la = x;
 else
 la = y;
 for (int k = la; k > 0; k--)
 {
 if (r == m[j][i - 1] || r == m[j - 1][i])
 {
 if (r == m[j][i - 1])
 i--;
 else
 j--;
 }
 else
 {
 s3[in] = s2[i - 1];
 i--; j--;
 r = m[j][i]; in++;
 }
 }
 cout << "Longest common subsequence of given two string is: " << endl;
 for (int i = x; i >= 0; i--)
 cout << s3[i];
 return 0;
}
int main()
{
 string s1, s2;
 cout << "Enter first string:" << endl;
 getline(cin, s1);
 cout << "Enter second string:" << endl;
 getline(cin, s2);
 LCS(s1, s2);
 return 0;
}
