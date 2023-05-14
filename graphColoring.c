#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int x[10]={0};
int n=4,m;
int count=0;
int G[5][5]={{0,0,0,0,0},
			 {0,0,1,0,1},
             {0,1,0,1,0},
             {0,0,1,0,1},
             {0,1,0,1,0}};
             
void print(int x[]){
	for(int i=1;i<=n;i++){
		printf("%3d",x[i]);
	}
	printf("\n");
}

void  nextValue(int k)
{
	int j;
	while(1)
	{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
			return;
		for(j=1;j<=k-1;j++)
		{
			if(G[j][k]==1 && x[j]==x[k])
				break;
		}
		if(j==k)
			return;
	}
	
}

int mColoring(int k)
{
	int i;
	while(1)
	{
		nextValue(k);
		if(x[k]==0)
			return n;
		if(k==n)
		{	
			count++;
			for(i=1;i<=n;i++)
			{
				printf("%3d",x[i]);
			}
			printf("\n");
		}
		else
		{
			mColoring(k+1);
		}
	}
}
int main ()
{
	printf("Enter no. of colors: ");
	scanf("%d",&m);
	mColoring(1);
	printf("Number of solution=%d\n",count);
}
