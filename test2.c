#include<iostream>
#include<algorithm>
#include<queue>
#define maxn 200010
using namespace std;

struct node
{
	int start, time;
	bool operator < (const node &a)const
	{
		return start < a.start;
	}
}nd[maxn];

int main()
{
	priority_queue<int, vector<int>, greater<int> >q;
	int n, sum=0;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> nd[i].start >> nd[i].time;
	}
	sort(nd, nd+n);
	
	int i, j, temp;
	int t[maxn] = {0};
	t[0] = nd[0].start;
	for (i=1, j=1; i<n; i++)
	{
		if (nd[i].start!=nd[i-1].start)
		{
			t[j] = nd[i].start;
			j++;
		}
	}
	int num = 0;
	int now = nd[0].start;
	for (i=0; i<j-1; i++)
	{
		while(num<n && nd[i].start==t[i])
		{
			q.push(nd[num].time);
			num++;
		}
		while(now<t[i+1])
		{
			if (!q.empty())
			{
				temp = q.top();
				q.pop();
				if (now+temp<=t[i+1])
				{
					now+=temp;
					sum+=now;
				}
				else
				{
					temp-=t[i+1]-now;
					now = t[i+1];
					q.push(temp);
				}
			}
			else
			{
				now = t[i+1];
				break;
			}
		}
	}
	while(num<n && nd[num].start==t[j-1])
		q.push(nd[num++].time);
	while(!q.empty())
	{
		now+=q.top();
		q.pop();
		sum+=now;
	}
	cout << sum;
}
