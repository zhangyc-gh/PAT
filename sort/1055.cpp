#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
struct node
{
    char name[10];
    int age, worth;
};
bool cmp(node a, node b)
{
    if(a.worth != b.worth) return a.worth > b.worth;
    else if(a.age != b.age) return a.age < b.age;
    else return strcmp(a.name, b.name) < 0;
}
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	vector<node> vt(n), v;
    for(int i = 0; i < n; i ++)
    	scanf("%s %d %d", vt[i].name, &vt[i].age, &vt[i].worth);
    sort(vt.begin(), vt.end(), cmp);
    vector<int> book(205, 0);
    for(int i = 0; i < n; i ++)
    {
        if(book[vt[i].age] < 100)
    	{
    		v.push_back(vt[i]);
    		book[vt[i].age] ++;
    	}
    }
    for(int i = 0; i < k; i ++)
    {
    	int m, amin, amax;
    	vector<node> t;
    	scanf("%d %d %d", &m, &amin, &amax);
    	for(int j = 0; j < v.size(); j ++)
    	{
    	    if(v[j].age >= amin && v[j].age <=amax)
    			t.push_back(v[j]);
    	}
    	bool flag = 0;
    	printf("Case #%d:\n", i + 1);
    	for(int j = 0; j < m && j < t.size(); j ++)
    	{
    		printf("%s %d %d\n", t[j].name, t[j].age, t[j].worth);
    		flag = 1;
    	}
    	if(!flag) printf("None\n");
    }
    return 0;
}
