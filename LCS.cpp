#include <stdio.h>
char M[100],N[100];
int M1[100][100]={0},N1[100][100]={0};
int m,n;
void f(int N1[][100],int i,int j) {
	if(i==0 || j==0){
		return;
	}
	if(N1[i][j]==2){
		f(N1,i-1,j-1);
		printf("%c ",M[i]);
	}
	else if(N1[i][j]==1) {
		f(N1,i-1,j);
	}
	else{
		f(N1,i,j-1);
	}
}
void LM1S(int m,int n,char M[],char N[],int M1[][100],int N1[][100]){
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;++j){
			if(M[i]==N[j]){
				M1[i][j]=M1[i-1][j-1]+1;
				N1[i][j]=2;
			}
			else
			{
				if(M1[i-1][j]>M1[i][j-1])
				{
					M1[i][j]=M1[i-1][j];
					N1[i][j]=1;
				}
				else {
					M1[i][j]=M1[i][j-1];
					N1[i][j]=0;
				}
			}
		}
	}
	f(N1,m,n);
}
int main(){
	printf("请分别输入两个序列的长度:");
	scanf("%d %d",&m,&n);
	printf("请分别输入两个序列:\n");
	for(int i=1;i<=m;i++){
		scanf(" %c",&M[i]);
	}
	for(int i=1;i<=n;i++){
		scanf(" %c",&N[i]);
	}
	LM1S(m,n,M,N,M1,N1);
}

