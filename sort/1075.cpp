#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
    int  id, rank, passNum = 0, total = 0;
    bool show = false;
    int score[6] = {-2,-2,-2,-2,-2,-2};
};
bool cmp(node a, node b)
{
    if(a.total != b.total) return a.total > b.total;
    else if(a.passNum != b.passNum) return a.passNum > b.passNum;
    return a.id < b.id;
}
int main()
{
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    int full[k + 1];
    node v[n+1];
    for(int i = 1; i <= k; i ++)
        scanf("%d", &full[i]);
    while(m --)
    {
        int id, num, score;
        scanf("%d %d %d", &id, &num, &score);
        v[id].score[num] = max(v[id].score[num], score);
        if(score != -1) v[id].show = true;
        v[id].id = id;
    }
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= k; j ++)
        {
            if(v[i].score[j] != -1 && v[i].score[j] != -2)
                v[i].total += v[i].score[j];
            if(v[i].score[j] == full[j])
                v[i].passNum ++;
        }
    }
    sort(v + 1, v + n + 1, cmp);
    v[1].rank = 1;
    for(int i = 2; i <= n; i ++)
        v[i].rank = (v[i].total == v[i-1].total) ? v[i].rank = v[i-1].rank : i;
    for(int i = 1; i <= n; i ++)
    {
        if(v[i].show)
        {
            printf("%d %05d %d ", v[i].rank, v[i].id, v[i].total);
            for(int j = 1; j <= k; j ++)
            {
                if(v[i].score[j] == -1 || v[i].score[j] == 0) printf("0");
                else if(v[i].score[j] != -2) printf("%d",v[i].score[j]);
                else printf("-");
                if(j < k) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
