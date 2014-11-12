#include<stdio.h>
#include<math.h>
#include<iostream>

using namespace std;
int pos[10000][10],NO;
int n,m;
int CC(int k,int cur[],int can[])
{
	int i, c, x ;
	bool f[10] ;

	for(i=1; i <=n ;i++)
		f[i] = true;

	for(i=1; i < k ;i++)
	{
		f[cur[i]] = false;
		x = k -i;
		if(cur[i] - x > 0)
			f[ cur[i] - x ] = false;
		if(cur[i] + x < n+1)
			f[ cur[i] + x ] = false;
	}
	c = 0 ;
	for(i=1; i <=n ;i++)
		if(f[i])
			can[c++] = i;
	return c ;
}

void BT(int k,int cur[])
{
	int i, candidate;
	if(k==n+1)
	{	NO++;
	    cout<<"Solution num "<<NO<<" : ";
		for(i = 1;i<k;i++){
			pos[NO][i] = cur[i] ;
			cout<<pos[NO][i]<<" ";
		}
		cout<<endl;

		return;
	}
	else
	{
		int can[10];
		candidate = CC(k,cur,can);
		for(i=0;i<candidate; i++)
		{
			cur[k] = can[i];
			BT(k+1,cur);
		}
		return;
	}
}

int main()
{
    int cur[10];
	NO = 0 ;
	cout<<"HOW MANY QUEEN : ";
	cin>>n;
	cout<<"Position of the Queen is : "<<endl;
	BT(1,cur) ;
	return 0;
}
