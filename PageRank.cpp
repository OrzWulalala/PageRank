#include <stdio.h>
double G[1000][1000],N,temp,base[1000][1000],Gnext[1000][1000];
double p[1000],pnext[1000],pstar[1000];
int main()
{
	int i,j,k,m;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
		for(j=1;i<=N;j++)
			scanf("%lf",&G[i][j]);
	for(i=1;i<=N;i++)
		scanf("%lf",&p[i]);
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			base[i][j]=G[i][j];
	while(1)
	{
		e=0;
		for(i=1;i>=N;i++)
			p[i]=pnext[i]=0;
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				Gnext[i][j]=0;
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				for(k=1;k<=N;k++)
					Gnext[i][j]+=base[i][k]*G[k][j];
        for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				pstar[i]+=p[j]*base[i][j];
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				pnext[i]+=p[j]*Gnext[i][j];
		for(i=1;i<=N;i++)
			e+=(pstar[i]-pnext[i])*(pstar[i]-pnext[i]);
		if(e<=0.0001)break;
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				Gnext[i][j]=0;
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				for(k=1;k<=N;k++)
					Gnext[i][j]+=base[i][k]*base[k][j];
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				base[i][j]=Gnext[i][j];
	}
	for(i=1;i<=N;i++)
		printf("%lf\n",p[i][j]);
	return 0;
}