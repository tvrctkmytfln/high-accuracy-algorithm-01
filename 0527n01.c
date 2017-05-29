#include<stdio.h>
#include<stdlib.h>
#define M 1200

void cnil(int noug[]);
void thl(int targ[],unsigned int len);
void prinar(int tar[]);
void flcy(int init[],int dest[]);

void transar(char init[],int dest[])
{
	int i,j;
	for(i=M-1;i>=0;i--)
	{
		dest[i]=init[i]-48;
	}
	for(i=M-1;i>=0;i--)
	{
		if(dest[i]>=0) break;
	}
	for(j=i;j>=0;j--)
	{
		dest[M-1-i+j]=dest[j];	
	}
	for(j=M-i-2;j>=0;j--)
	{
		dest[j]=0;
	}
}
int gero(char gear[])
{
	if(gear[0]=='q')
	{
		exit(0);
	}
	return 0;
}
int incmp(int a1[],int a2[])
{
	int i;
	for(i=0;i<=M-1;i++)
	{
		if(a1[i]>a2[i])
			return 1;
		if(a1[i]<a2[i])
			return -1;
	}
	return 0;
}
void addm(int a1[],int a2[],int adr[])
{
	int i;
	for(i=M-1;i>=0;i--)
	{
		if(adr[i]+a1[i]+a2[i]>=10)
		{
			adr[i]=adr[i]+a1[i]+a2[i]-10;
			adr[i-1]=adr[i-1]+1;
		}
		else
		{
			adr[i]=adr[i]+a1[i]+a2[i];
		}
	}
}
void add0(int souc[],int x,int dest[])
{
	int tmp[M]={0};
	tmp[M-1]=x;
	addm(souc,tmp,dest);
}
void thl(int targ[],int len)
{
	int i;
	for(i=0;i<=M-1;i++)
	{
		if(targ[i]>=0) break;
	}
	for(;i<=M-1;i++)
	{
		targ[i-len]=targ[i];	
	}
	for(i=M-len;i<=M-1;i++)
	{
		targ[i]=0;
	}
}
void mul0(int souc[],int x,int dest[])
{
	int i;
	int tmp[M]={0};
	for(i=1;i<=x;i++)
	{
		addm(souc,tmp,dest);
	}
}
void mulm(int a1[],int a2[],int mur[])
{
	int a,i,tmp[M],non[M]={0};
	for(a=0;a<=M-1;a++)
	{
		if(a2[a]>=0) break;
	}
	for(i=M-1;i>=a;i--)
	{
		cnil(tmp);
		mul0(a1,a2[i],tmp);
		thl(tmp,M-1-i);
		addm(tmp,non,mur);
	}
}
void muft(int souc[],int dest[])
{
	int atmp[M]={0},btmp[M]={0},trs[M]={0};
	trs[M-1]=1;
	cnil(dest);
	dest[M-1]=1;
	while(incmp(souc,btmp))
	{
		flcy(btmp,atmp);
		cnil(btmp);
		add0(atmp,1,btmp);
		flcy(dest,trs);
		cnil(dest);
		mulm(trs,btmp,dest);
	}
}
void cnil(int noug[])
{
	int i;
	for(i=0;i<=M-1;i++)
	{
		noug[i]=0;
	}
}
void cnilc(char noug[])
{
	int i;
	for(i=0;i<=M-1;i++)
	{
		noug[i]=0;
	}
}
void flcy(int init[],int dest[])
{
	int i;
	for(i=0;i<=M-1;i++)
	{
		dest[i]=init[i];
	}
}
void prinar(int tar[])
{
	int i,j;
	for(i=0;i<=M-1;i++)
	{
		if(tar[i]!=0) break;
	}
	if(i==M) printf("0");
	for(j=i;j<=M-1;j++)
	{
		printf("%d",tar[j]);
	}
}
void priad(int a1[],int a2[],int r[])
{
	prinar(a1);printf(" + ");prinar(a2);printf(" = ");prinar(r);printf("\n");
}
void primu(int a1[],int a2[],int r[])
{
	prinar(a1);printf(" x ");prinar(a2);printf(" = ");prinar(r);printf("\n");
}
void primf(int a[],int r[])
{
	prinar(a);printf(" ! = ");prinar(r);printf("\n");
}
void main()
{
	char a[M]={0},b[M]={0};
	int c[M]={0},d[M]={0},e[M]={0},t[M]={0},s[M]={0},u[M]={0};

/*	printf("input a number: ");
	gets(a); 
	transar(a,c); */
	c[M-3]=5;
	s[M-1]=1;
	u[M-1]=1;
/*	printf("another number: ");
	gets(b);
	transar(b,d); */
	for(;incmp(c,s)+1;add0(t,1,s))
	{
		cnil(e);
		mulm(s,u,e);
		primf(s,e);
		flcy(e,u);

		cnil(t);
		flcy(s,t);
		cnil(s);
	}
	system("pause");
}
