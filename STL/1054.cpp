#include<stdio.h>
#include<map>
using namespace std;
map<int, int> mapp;
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int half = m * n / 2;
    for(int i = 0; i < m; i ++)
        for(int j = 0; j < n; j ++)
    {
        int color;
        scanf("%d", &color);
        mapp[color] ++;
        if(mapp[color] > half)
        {
            printf("%d", color);
            return 0;
        }
    }
}
