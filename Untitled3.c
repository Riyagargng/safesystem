#include<stdio.h>
#include <stdlib.h>
 
#include "queue.h";
int main()
{
	int avail[4]={1,5,2,0}; //available resources
	
	int alloc[5][4]={{0,0,1,2},  //p0  //allocation matrix
	           {1,0,0,0},        //p1
			   {1,3,5,4},        //p2
			   {0,6,3,2},        //p3
			   {0,0,1,4}};       //p4
			   
	int max[5][4]={{0,0,1,2},    //p0  //maximum matrix
	         {1,7,5,0},          //p1
			 {2,3,5,6},          //p2
			 {0,6,5,2},          //p3
			 {0,6,5,6}};         //p4	   
			 
	int need[5][4];
	
	int i,j,k=5;
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<4;j++)
		{
			need[i][j] = max[i][j] - alloc[i][j];
			
		}
	}
	
	printf("\nALLOCATION MATRIX\n");
		for(i=0;i<5;i++)
	{
		printf("\n p%d",i);
		for(j=0;j<4;j++)
		{
			printf("  %d",alloc[i][j]);
			
		}
		
	}
	
		printf("\n\nMAXIMUM MATRIX\n");
		for(i=0;i<5;i++)
	{
		printf("\n p%d",i);
		for(j=0;j<4;j++)
		{
			printf("  %d",max[i][j]);
			
		}
		
	}


	printf("\n\nNEED MATRIX\n");
		for(i=0;i<5;i++)
	{
		printf("\n p%d",i);
		for(j=0;j<4;j++)
		{
			printf("  %d",need[i][j]);
			
		}
		
	}


	printf("\n\nAVAILABLE MATRIX\n");
		
	
	
		for(j=0;j<4;j++)
		{
				printf("\n p%d",j);
			printf("  %d",avail[j]);
			
		}
	
	int seq[5];
	 queue<int>q;
	for(int i=0;i<=4;i++)
	{
		q.push(i);
	}
	
	int count=0;
	while(!q.empty())
	{  int x=q.front();
	   
	   if(need[x][0]<=avail[0][0] &&
	      need[x][1]<=avail[0][1] &&
		  need[x][2]<=avail[0][2] &&
		  need[x][3]<=avail[0][3])
		  {  seq[count++]=x;
		   avail[0][0]=avail[0][0]+alloc[x][0];
		   avail[0][1]=avail[0][1]+alloc[x][1];
		   avail[0][2]=avail[0][2]+alloc[x][2];	
		   avail[0][3]=avail[0][3]+alloc[x][3];	
		 }
		 else
		 {
		 	q.push(x);
		 }
		 
		 q.pop();
		
	}
	
    printf(" \n SAFE SEQUENCE IS:");
	for(int i=0;i<5;i++)
	{
		printf(" PROCESS P",seq[i]);
		if(i!=4)
		{
		printf("--->");
		}
	}
}
