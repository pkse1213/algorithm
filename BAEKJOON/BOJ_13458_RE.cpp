/*
 13458. 시험감독
 
 굉장히 쉬운 문제인데 범위를 생각하지 못해서 계속 틀렸다ㅠㅠ
 */
#include <iostream>
#include <vector>
using namespace std;
int N, B, C, P;
vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> P;
        v.push_back(P);
    }
    cin >> B >> C;
    
    long long ad = 0;
    for(int i = 0; i < N; i++)
    {
        int st = v[i] - B;
        if(st <= 0) continue;
        ad += (st/C);
        if(st%C > 0) ad++;
    }
    cout << ad + N << '\n';
    return 0;
}
