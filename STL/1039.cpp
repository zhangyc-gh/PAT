#include<stdio.h>
#include<set>
using namespace std;
const int maxn = 26 * 26 * 26 * 10;
set<int> v[maxn];
int str2num(char name[])
{
    int total = 0;
    for(int i = 0; i < 3; i ++)
        total = total * 26 + name[i] - 'A';
    total = total * 10 + name[3] - '0';
    return total;
}
int main()
{
    int n, k, na;
    char name[5];
    scanf("%d %d", &n, &k);
    while(k --)
    {
        int id, num;
        scanf("%d %d", &id, &num);
        while(num --)
        {
            scanf("%s",name);
            na = str2num(name);
            v[na].insert(id);
        }
    }
    while(n --)
    {
        scanf("%s", name);
        printf("%s ",name);
        na = str2num(name);
        if(v[na].size() != 0)
        {
            printf("%d", v[na].size());
            for(set<int>::iterator it = v[na].begin(); it !=v[na].end(); it ++)
                printf(" %d", *it);
            printf("\n");
        }
        else
            printf("0\n");
    }
    return 0;
}
