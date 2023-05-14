#include<stdio.h>
int n,w[10][10];
void readGraph()
{
	FILE *fp;
	fp=fopen("graph.txt","r");
	if(fp==NULL)
	{
		printf("File open failed\n");
		return;
	}
	fscanf(fp,"%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fp,"%d",&w[i][j]);
		}
	}
	fclose(fp);
}

void showGraph()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%3d",w[i][j]);
		}
		printf("\n");
	}
}

int dist[10];
int parent[10];
int sptSet[10];

int minKey(){
	int min=9999;
	int minIndex=-1,i;
	for(i=0;i<n;i++)
	{
		if(sptSet[i]==0)
		{
			if(min>dist[i])
			{
				min=dist[i];
				minIndex=i;
			}
		}
	}
	return minIndex;
}

void dijkstra(int r)
{
	int i,v;
	for(i=0;i<n;i++)
	{
		dist[i]=9999;
		parent[i]=-1;
		sptSet[i]=0;
	}
	dist[r]=0;
	for(i=0;i<n;i++)
	{
		int u=minKey();
		sptSet[u]=1;
		for(v=0;v<n;v++)
		{
			if(w[u][v]!=0){
				if(dist[u]+w[u][v]<dist[v] && sptSet[v]==0)
				{
					dist[v]=dist[u]+w[u][v];
					parent[v]=u;
				}
			}
		}
	}
}

/*void showTree(){
	int i;
	for(i=0;i<n;i++)
	{
		if(parent[i]!=-1)
		printf("%c->%c,%d\n",parent[i]+'A',i+'A',w[parent[i]][i]);
	}
}*/
void showPath(int dest)
{
	if(dest==-1)
		return ;
	else
	{
		showPath(parent[dest]);
		printf("%4c->",dest+'A');
	}
}

int main()
{
	readGraph();
	showGraph();
	dijkstra(0);
	showPath('F'-'A');
	printf("\nCost=%d",dist['F'-'A']);
	return 0;
}
