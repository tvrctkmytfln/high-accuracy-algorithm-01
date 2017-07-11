#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 20000
#define CM 80000

void trscar(char init[],int dest[])
{
	int j,i=strlen(init)%4,n=strlen(init)/4;
	switch(i)
	{
		case 0:break;
		case 1:dest[0]=init[0]-48;break;
		case 2:dest[0]=10*init[0]+init[1]-528;break;
		case 3:dest[0]=100*init[0]+10*init[1]+init[2]-5328;break;
	}
	for(j=i!=0,n-=i==0;j<=n;i+=4,j++)
	{
		dest[j]=1000*init[i]+100*init[i+1]+10*init[i+2]+init[i+3]-53328;
	}
	for(i=M-1,j-=1;i>=0;i--,j--)
	{
		dest[i]=(j>=0)*dest[j];
	}
}
int incmp(int a1[],int a2[])
{
	int i;
	for(i=0;i<M;i++)
	{
		if(a1[i]>a2[i])
			return 1;
		if(a1[i]<a2[i])
			return -1;
	}
	return 0;
}
void flcy(int init[],int dest[])
{
	int i;
	for(i=0;i<M;i++)
	{
		dest[i]=init[i];
	}
}
void cnil(int noug[])
{
	int i;
	for(i=0;i<M;i++)
	{
		noug[i]=0;
	}
}
void thln(int targ[],int len)
{
	int  i;
	for(i=0;i<M;i++)
	{
		targ[i]=(i<M-len)*targ[i+len];
	}
}
void add3(int a1[],int a2[],int adr[])
{
	int i,j=0;
	while(!a2[j]) j++;
	for(i=M-1;i>0;i--)
	{
		if(adr[i]+a1[i]+a2[i]>9999)
		{
			adr[i]+=a1[i]+a2[i]-10000;
			adr[i-1]++;
		}
		else
		{
			adr[i]+=a1[i]+a2[i];
		}
	}
}
void add2(int a1[],int a2,int adr[])
{
	int tmp[M]={0};
	tmp[M-1]=a2;
	add3(a1,tmp,adr);
}
void mul2(int a1[],int a2,int mur[])
{
	int i,j=0,tmp;
	while(!a1[j]) j++;
	for(i=M-1;i>=j;i--)
	{
		tmp=mur[i]+a1[i]*a2;
		mur[i]=tmp%10000;
		mur[i-1]+=tmp/10000%10000;
	}
}
void mul3(int a1[],int a2[],int mur[])
{
	int i,j=0,tmp[M],non[M]={0};
	while(!a2[j]) j++;
	for(i=M-1;i>=j;i--)
	{
		cnil(tmp);
		mul2(a1,a2[i],tmp);
		thln(tmp,M-1-i);
		add3(tmp,non,mur);
	}
}
void muf(int x,int mfr[])
{
	int i,tmp[M]={0};
	tmp[M-1]=1;
	if(x!=0)
	{
		for(i=1;i<=x;i++)
		{
			cnil(mfr);
			mul2(tmp,i,mfr);
			flcy(mfr,tmp);
		}
	}
	else
	{
		cnil(mfr);
	}
}
void prinar(int tar[])
{
	int i=0,j;
	while(!tar[i]) i++;
	if(i<M)
	{	
		printf("%d",tar[i]);
		while(i<M-1)
		{
			i++;
			j=(tar[i]>9)+(tar[i]>99)+(tar[i]>999);
			switch(j)
			{
				case 3:printf("%d",tar[i]);break;
				case 2:printf("0%d",tar[i]);break;
				case 1:printf("00%d",tar[i]);break;
				case 0:printf("000%d",tar[i]);break;
			}
		}
	}
	else printf("0");
}
void priad3(int a1[],int a2[],int adr[])
{
	prinar(a1);printf(" + ");prinar(a2);printf(" = ");prinar(adr);printf("\n");
}
void primu3(int a1[],int a2[],int mur[])
{
	prinar(a1);printf(" x ");prinar(a2);printf(" = ");prinar(mur);printf("\n");
}
void primuf(int x,int mur[])
{
	printf("%d ! = ",x);prinar(mur);printf("\n");
}


/*
void main()
{
	char a1[CM]={0},a2[CM]={0};
	int i1[M]={0},i2[M]={0},adr[M]={0};
	gets(a1);gets(a2);
	trscar(a1,i1);trscar(a2,i2);
	mul3(i1,i2,adr);
	primu3(i1,i2,adr);
	
}
*/
void main()
{
	int x,r[M];
	scanf("%d",&x);
	if(x>=0&&x<=10000)
	{
		muf(x,r);
		primuf(x,r);
	}
	else
	{
		puts("error");
	}
}
