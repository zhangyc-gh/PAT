#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
    int id,score[4],ranks[4],best;
}stu[2010];
int in[1000000]={0};
char Best[4] = {'A','C','M','E'};
int flag,n,m;
bool cmp(node a, node b)
{
    return a.score[flag] > b.score[flag];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&stu[i].id,&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
        stu[i].score[0] = stu[i].score[1]+stu[i].score[2]+stu[i].score[3];
    }
    for(flag=0;flag<4;flag++)
    {
        sort(stu,stu+n,cmp);
        stu[0].ranks[flag] = 1;
        for(int i=1;i<n;i++)
        {
            if(stu[i].score[flag] == stu[i-1].score[flag])
                stu[i].ranks[flag] = stu[i-1].ranks[flag];
            else
                stu[i].ranks[flag] = i+1;
        }
    }
    for(int i=0;i<n;i++)
    {
        in[stu[i].id] = i + 1;
        stu[i].best = 0;
        for(int j=0;j<4;j++)
        {
            if(stu[i].ranks[stu[i].best]>stu[i].ranks[j])
                stu[i].best = j;
        }
    }
    for(int i=0;i<m;i++)
    {
        int stuid;
        scanf("%d",&stuid);
        int temp = in[stuid];
        if(temp)
        {
            printf("%d %c\n",stu[temp-1].ranks[stu[temp-1].best],Best[stu[temp-1].best]);
        }
        else
            printf("N/A\n");
    }
    return 0;
}
