#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
struct node
{
    int id, score;
    char name[10]; // 考虑到读取问题
};
int c;
bool cmp(node a, node b)
{
    if(c == 1) return a.id < b.id;
    if(c == 2) return strcmp(a.name, b.name) == 0 ? a.id < b.id : strcmp(a.name, b.name) <= 0;
    if(c == 3) return a.score == b.score ? a.id < b.id : a.score <= b.score;
}
int main()
{
    int n;
    scanf("%d%d",&n,&c);
    vector<node> stu(n);
    for(int i = 0; i < n; i ++)
        scanf("%d%s%d",&stu[i].id,stu[i].name,&stu[i].score);
    sort(stu.begin(),stu.end(),cmp);
    for(int i = 0; i < n; i ++)
        printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].score);
    return 0;
}
