#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct node
{
    string name;
    int month, day, hour, minute,time,status;
};
bool cmp(node a, node b)
{
    return a.name != b.name ? a.name < b.name : a.time < b.time;
}
int rate[25]={0},n;
double billFromZero(node a)
{
    double total = 0;
    total += a.minute * rate[a.hour];
    for(int i = 0; i < a.hour; i++)
        total += rate[i] * 60;
    total += rate[24] * 60 * a.day;
    return total / 100;
}
int main()
{
    for(int i = 0; i < 24; i++)
    {
        scanf("%d",&rate[i]);
        rate[24] += rate[i];
    }
    scanf("%d",&n);
    vector<node> data(n);
    for(int i = 0; i < n; i++)
    {
        cin >> data[i].name;
        scanf("%d:%d:%d:%d",&data[i].month,&data[i].day,&data[i].hour,&data[i].minute);
        string temp;
        cin >> temp;
        data[i].status = (temp == "on-line") ? 1 : 0;
        data[i].time = data[i].day * 24 * 60 + data[i].hour * 60 + data[i].minute;
    }
    sort(data.begin(), data.end(), cmp);
    map<string, vector<node> > customer;
    for(int i = 1; i < n; i++)
    {
        if(data[i-1].status == 1 && data[i].status == 0 && data[i].name == data[i-1].name)
        {
            customer[data[i-1].name].push_back(data[i-1]);
            customer[data[i-1].name].push_back(data[i]);
        }
    }
    map<string, vector<node> >:: iterator it;
    for(it = customer.begin(); it != customer.end(); it ++)
    {
        cout << it->first;
        vector<node> temp = it->second;
        printf(" %02d\n", temp[0].month);
        double totalBill = 0;
        for(int i = 1; i < temp.size(); i +=2)
        {
            double total = 0;
            int t = temp[i].time - temp[i-1].time;
            total = billFromZero(temp[i]) - billFromZero(temp[i-1]);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",temp[i-1].day,temp[i-1].hour,temp[i-1].minute,temp[i].day,temp[i].hour,temp[i].minute,t,total);
            totalBill += total;
        }
        printf("Total amount: $%.2f\n", totalBill);
    }
    return 0;
}
