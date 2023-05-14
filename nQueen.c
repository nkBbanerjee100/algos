 #include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n;
int x[10];

int place(int k,int i){
	int j;
	for(j=1;j<=k-1;j++){
		if(x[j]==i || abs(j-k)==abs(x[j]-i)) return 0;
	}
	return 1;
}

int count=0;
void nQueen(int k,int n){
	int i,j;
	for(i=1;i<=n;i++){
		if(place(k,i)){
			x[k]=i;
			if(k==n){
				count++;
				for(j=1;j<=n;j++){
					printf("%3d",x[j]);
				}
				printf("\n");
			}
			else nQueen(k+1,n);
		}
	}
}




int main(){
	printf("Enter no. of queens: ");
	scanf("%d",&n);
	nQueen(1,n);
	printf("Number of solution=%d\n",count);
	return 0;
}
