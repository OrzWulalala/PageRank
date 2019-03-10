#include <stdio.h>
#define N 1010
#define alpha 0.85
double G[N][N];
int n;
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%lf",&G[i][j]);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			if(G[i][j]!=0)break;
		if(j>n)
		{
			for(j=1;j<=n;j++)
				G[i][j]=(1.0)/n;
		}
	}
	for(i=1;i<=n;i++)
		G[i][j]=alpha*G[i][j]+(1-alpha);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%lf ",G[i][j]);
		printf("\n");
	}
	return 0;
}