#include<stdio.h>
#include<stdlib.h>
struct Edge{
    int v1, v2,weight;
};

struct Edge x[9]={{0,1,7},{1,2,6},{1,3,3},{0,3,8},{2,3,4},{2,4,2},{3,4,3},{2,5,5},{4,5,2}};
int noe=9;
void displayGraph(){
    int i;
    for(i=0;i<noe;i++){
        printf("%c->%c,%d\n",x[i].v1+'A',x[i].v2+'A',x[i].weight);
    }
}

void Sort(){
    int i,j;
    for(i=0;i<noe-1;i++){
        for(j=0;j<noe-1-i;j++){
            if(x[j].weight>x[j+1].weight){
                struct Edge temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
            }                
        }
    }
}

int treeEdge[100][2];
int parent[100];
int nov=6;

int find(int i){
    while(parent[i]>0) i=parent[i];
    return i;
}

int Union(int i,int j){
    int u=find(i);
    int v=find(j);
    parent[v]=u;
}
int countTreeEdge=0;

void Kruskal(){
    Sort();
    int i;
    for(i=0;i<nov;i++) parent[i]=-1;
    for(i=0;i<noe;i++){
        if(find(x[i].v1)!=find(x[i].v2)){
            treeEdge[countTreeEdge][0]=x[i].v1;
            treeEdge[countTreeEdge++][1]=x[i].v2;
            Union(x[i].v1,x[i].v2);
        }
    }
    countTreeEdge--;
}

void displaySpanningTreedge(){
    int i;
    for(i=0;i<countTreeEdge;i++)
        printf("%c->%c\n",treeEdge[i][0]+'A',treeEdge[i][1]+'A');
}

int main(){
    displayGraph();
    
    Kruskal();
    printf("\n\n");
    displaySpanningTree();
    return 0;
}

