#include <stdio.h>

char s[1000];
double p[30];

double series(double a,double b)
{
	return a+b-a*b;
}

double parallel(double a,double b)
{
	return a*b;
}

double numstack[1000];
int    opestack[1000],ope=0,num=0;
const int PARA=1,SERI=2;
//(=-1 para=1 seri=2

double operate(int flag,double a,double b)
{
	if (flag==PARA) return parallel(a,b);
	else return series(a,b);
}

int main()
{
	int n;
	scanf("%d",&n);gets(s);
	gets(s);
	for (int i=0;i<n;i++)
		scanf("%lf",&p[i]);
		
	for (int i=0;s[i]!=0;i++)
	{
		if (s[i]=='(')
		{
			opestack[++ope]=-1;
			continue;
		}
		if (s[i]==')')
		{
			while (opestack[ope]>0)
				numstack[num-1]=operate(opestack[ope],numstack[num],numstack[num-1]),
				num--,ope--;
			if (ope>0) ope--;
						
			if (s[i+1]=='(')
			{
				i++;
				opestack[++ope]=PARA;				
				opestack[++ope]=-1;
			}
			continue;
		}
		if (s[i]==',')
		{
			while (opestack[ope]==PARA)
				numstack[num-1]=parallel(numstack[num],numstack[num-1]),
				num--,ope--;
				
			opestack[++ope]=SERI;
			continue;
		}
		numstack[++num]=p[s[i]-'A'];
	}
	while (opestack[ope]>0)
		numstack[num-1]=operate(opestack[ope],numstack[num],numstack[num-1]),
		num--,ope--;
	printf("%.4lf\n",numstack[1]);
}
