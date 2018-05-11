#include <iostream>
#include <string>
#include <set>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 1005;
char str[maxn];
int matrix[maxn][maxn] = {0};

int solve(int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            matrix[i][j] = matrix[i + 1][j] + matrix[i][j - 1] - matrix[i + 1][j - 1];
            if (str[i] == str[j])
                matrix[i][j] = (matrix[i][j] + matrix[i + 1][j - 1] + 1);
        }
    }
    return matrix[0][n - 1];
}

int main()
{   
    scanf("%s", str);
    int n = strlen(str);
    printf("%d\n", solve(n));
    return 0;
}