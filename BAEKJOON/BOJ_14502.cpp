/*
 BAEKJOON
 14502. 연구소

 실수
 110번째 줄에서 cnt--;를 해줘야 된다고 생각했다
 매개변수로 cnt+1을 던져주지만
 돌아왔을 때 cnt값은 그대로이기 때문에 안해줘도 된다
 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 9
using namespace std;
struct node {
    int r, c;
    node();
    node(int _r, int _c): r(_r), c(_c) {}
};

int origin_map[MAX][MAX];
int tmp_map[MAX][MAX];
int n, m;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
int answer = 0;

queue<node> virus;

void input()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> origin_map[i][j];
        }
    }
}

void copy_map()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            tmp_map[i][j] = origin_map[i][j];
            if(origin_map[i][j] == 2) virus.push(node(i, j));
        }
    }
}

int add_blank()
{
    int res = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(tmp_map[i][j] == 0) res++;
        }
    }
    return res;
}

// 바이러스 확산
void virus_spread()
{
    copy_map();
    
    while(!virus.empty())
    {
        for(int k=0; k<4; k++)
        {
            int nr = virus.front().r + dr[k];
            int nc = virus.front().c + dc[k];
            // 확산되는 경우
            if(!(nr < 0 || nc < 0 || nr > n-1 || nc > m-1) && tmp_map[nr][nc] == 0)
            {
                tmp_map[nr][nc] = 2;
                virus.push(node(nr,nc));
            }
        }
        virus.pop();
    }
    
    answer = max(answer, add_blank());
}

// 벽 세우기
void dfs_create(int cnt)
{
    if(cnt == 3)
    {
        virus_spread();
        return;
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(origin_map[i][j] == 0)
            {
                origin_map[i][j] = 1;
                dfs_create(cnt+1);
                origin_map[i][j] = 0;
            }
        }
    }
}


int main(int argc, char** argv)
{
    input();
    dfs_create(0);
    cout << answer;
    return 0;
}
