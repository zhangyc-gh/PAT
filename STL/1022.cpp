#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
#include<set>
using namespace std;
map<string, set<int> > title, author, keywords, publisher, year;
void query(map<string, set<int> > &mapp, string &temp)
{
    if(mapp.find(temp) != mapp.end())
    {
        for(set<int>::iterator it = mapp[temp].begin(); it != mapp[temp].end(); it ++)
            printf("%07d\n", *it);
            return;
    }
    else
        printf("Not Found\n");
}
int main()
{
    int n, m, id;
    scanf("%d", &n);
    string ttitle, tauthor, tkeywords, tpublisher, tyear;
    for(int i = 0; i < n; i ++)
    {
        scanf("%d\n", &id);
        getline(cin, ttitle); title[ttitle].insert(id);
        getline(cin, tauthor); author[tauthor].insert(id);
        while(cin >> tkeywords)
        {
            keywords[tkeywords].insert(id);
            char c = getchar();
            if(c == '\n') break;
        }
        getline(cin, tpublisher); publisher[tpublisher].insert(id);
        getline(cin, tyear); year[tyear].insert(id);
    }
    scanf("%d", &m);
    while(m --)
    {
        int q;
        string temp;
        scanf("%d: ", &q);
        getline(cin, temp);
        cout << q << ": " << temp << endl;
        if(q == 1) query(title, temp);
        if(q == 2) query(author, temp);
        if(q == 3) query(keywords, temp);
        if(q == 4) query(publisher, temp);
        if(q == 5) query(year, temp);
    }
    return 0;
}
