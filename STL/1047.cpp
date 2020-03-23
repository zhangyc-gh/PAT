#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
char name[40010][5];
bool cmp(int a, int b) {return strcmp(name[a], name[b]) < 0;}
vector<int> v[2510];
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i ++)
    {
        int m, id;
        scanf("%s %d", name[i], &m);
        for(int j = 0; j < m; j ++)
        {
            scanf("%d", &id);
            v[id].push_back(i);
        }
    }
    for(int i = 1; i <= k; i ++)
    {
        sort(v[i].begin(), v[i].end(), cmp);
        printf("%d %d\n", i, v[i].size());
        for(int j = 0; j < v[i].size(); j ++)
            printf("%s\n", name[v[i][j]]);
    }
    return 0;
}
