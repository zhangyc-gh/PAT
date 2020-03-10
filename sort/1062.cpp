#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct node {int id, de, cai;};
bool cmp(node a, node b)
{
    if(a.de + a.cai != b.de + b.cai) return a.de + a.cai > b.de + b.cai;
    else if(a.de != b.de) return a.de > b.de;
    return a.id < b.id;
}
int main()
{
    int n, l, h;
    scanf("%d %d %d", &n, &l, &h);
    vector<node> v[4];
    node temp;
    int total = 0;
    for(int i = 0; i < n; i ++)
    {
        scanf("%d %d %d", &temp.id, &temp.de, &temp.cai);
        if(temp.de >= l && temp.cai >= l)
        {
            total ++;
            if(temp.de >= h && temp.cai >=h) v[0].push_back(temp);
            else if(temp.de >= h) v[1].push_back(temp);
            else if(temp.de >= temp.cai) v[2].push_back(temp);
            else v[3].push_back(temp);
        }
    }
    printf("%d\n", total);
    for(int i = 0; i < 4; i ++)
    {
        sort(v[i].begin(), v[i].end(), cmp);
        for(int j = 0; j < v[i].size(); j ++)
            printf("%d %d %d\n", v[i][j].id, v[i][j].de, v[i][j].cai);
    }
    return 0;
}
