#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
    long long int no;
    int score, finalrank, localrank, local;
};
bool cmp(node a, node b)
{
    return (a.score == b.score) ? a.no < b.no : a.score > b.score;
}
int main()
{
    int n,m;
    scanf("%d",&n);
    vector<node> fin;
    for(int i = 1; i<= n; i ++)
    {
        int k;
        scanf("%d",&m);
        vector<node> v(m);
        for(int j = 0; j < m; j ++)
        {
            scanf("%lld%d",&v[j].no,&v[j].score);
            v[j].local = i;
        }
        sort(v.begin(),v.end(),cmp);
        v[0].localrank = 1;
        fin.push_back(v[0]);
        for(int j = 1; j < m; j++)
        {   //²»Ð´if elseÓï¾ä
            v[j].localrank = (v[j].score == v[j-1].score) ? v[j-1].localrank : j + 1;
            fin.push_back(v[j]);
        }
    }
    sort(fin.begin(),fin.end(),cmp);
    fin[0].finalrank = 1;
    printf("%d\n",fin.size());
    for(int i = 1; i < fin.size(); i++)
        fin[i].finalrank = (fin[i].score == fin[i-1].score) ? fin[i-1].finalrank : i + 1;
    for(int i = 0; i < fin.size(); i++)
        printf("%013lld %d %d %d\n",fin[i].no,fin[i].finalrank,fin[i].local,fin[i].localrank);
    //²¹Ç°µ¼0£¡£¡
    return 0;
}
