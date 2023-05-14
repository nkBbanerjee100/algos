#include<stdio.h>
struct Edge{
    int v1;
    int v2;
    int weight;
};

int noE;
int noV;
int n,w[10][10];
struct Edge edge[noE];
int dist[20];
int pred[20];

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

void Bellman_Ford(int src){
    for(int i=0;i<noV;i++){
        dist[i]=999;
        pred[i]=-1;
    }
    dist[src]=0;
    for(int i=1;i<=noV-1;i++){
        for(int j=0;j<noE;j++){
            int u=edge[j].v1;
            int v=edge[j].v2;
            if(dist[u]+w[u][v]<dist[v]){
                dist[v]=dist[u]+w[u][v];
                pred[v]=u;
            }
        }
    }
}

void displayPath(int i){
    if(i==-1) return;
    else{
        displayPath(pred[i]);
        //cout<<"    "<<(char)(i+'A');
        printf("%c",i+'A');
    }
}
int main(void)
{
	int i,j;
	printf("Enter no. of vertices: ");
	scanf("%d",&noV);
	printf("Enter no. of edges: ");
	scanf("%d",&noE);
	printf("Enter elements in  graph: ");
	readGraph();
	showGraph();
    Bellman_Ford(0);
    displayPath(3);
    //cout<<endl;
    //cout<<"cost="<<dist[3]<<endl;
    printf("\nCost=%d",dist[3]);
    return 0;
}
