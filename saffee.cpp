#include<iostream>
#include<conio.h>
#include<queue>
using namespace std;

int main()
{
	int allocated[5][4]={{0,0,1,2},{1,0,0,0},{1,3,5,4},{0,6,3,2},{0,0,1,4}};
	int maxm[5][4]={{0,0,1,2},{1,7,5,0},{2,3,5,6},{0,6,5,2},{0,6,5,6}};
	int available[1][4]={1,5,2,0};
	
	int need[5][4];
	for(int i=0;i<5;i++)
	{   
	    for(int j=0;j<4;j++)
	    {
	    	need[i][j]=maxm[i][j]-allocated[i][j];
		}
	}
	
	cout<<"    PROCESS       ALLOCATED        MAXIMUM            NEED  "<<endl;
	cout<<"                 ";
	int m=65;
	for(int i=0;i<1;i++)
	{   int p=65;
		for(int j=0;j<4;j++)
		{
			cout<<char(p++)<<"  ";
		}
		cout<<"     ";
		int q=65;
		for(int j=0;j<4;j++)
		{
			cout<<char(q++)<<"  ";
		}
		cout<<"     ";
		int r=65;
		for(int j=0;j<4;j++)
		{
			cout<<char(r++)<<"  ";
		}
	}
	cout<<endl;
	
		for(int i=0;i<5;i++)
	{   cout<<"     P"<<i<<"          ";
	    for(int j=0;j<4;j++)
	    {
	      cout<<allocated[i][j]<<"  ";    
		}
		cout<<"     ";
		for(int j=0;j<4;j++)
	    {
	      cout<<maxm[i][j]<<"  ";    
		}
		cout<<"     ";
		for(int j=0;j<4;j++)
	    {
	      cout<<need[i][j]<<"  ";    
		}
		cout<<endl;
	}
	
	cout<<" \n AVAILABLE"<<endl;
		for(int i=0;i<1;i++)
	{    int p=65;
		for(int j=0;j<4;j++)
		{
			cout<<char(p++)<<"  ";
		}
		cout<<endl;
	    for(int j=0;j<4;j++)
	    {
	    	cout<<available[i][j]<<"  ";
		}
	}
	
	cout<<endl;
	int seq[5];
	 queue<int>q;
	for(int i=0;i<=4;i++)
	{
		q.push(i);
	}
	
	int count=0;
	while(!q.empty())
	{  int x=q.front();
	   
	   if(need[x][0]<=available[0][0] &&
	      need[x][1]<=available[0][1] &&
		  need[x][2]<=available[0][2] &&
		  need[x][3]<=available[0][3])
		  {  seq[count++]=x;
		   available[0][0]=available[0][0]+allocated[x][0];
		   available[0][1]=available[0][1]+allocated[x][1];
		   available[0][2]=available[0][2]+allocated[x][2];	
		   available[0][3]=available[0][3]+allocated[x][3];	
		 }
		 else
		 {
		 	q.push(x);
		 }
		 
		 q.pop();
		
	}
	
	cout<<" \n SAFE SEQUENCE IS:"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<" PROCESS P"<<seq[i];
		if(i!=4)
		{cout<<"---------->";
		}
	}
	
	
	

}
