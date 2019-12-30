/*
 BAEKJOON
 SW Expert Academy
 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#define MAX 500
using namespace std;
int map[MAX][MAX];

int n, m;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
int answer = 0;

void input()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> map[i][j];
        }
    }
}

int main(int argc, char** argv)
{
    input();
    
    cout << answer;
    return 0;
}
