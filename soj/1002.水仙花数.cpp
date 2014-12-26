#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>

#define MAXSIZE 100

using namespace std;

int getValue(int base,int *des,int *log){
	if(*log<0){
		*des=pow(base,3);
		*log=*des;
	}
	return *des;
}
int  main(int argc ,char **argv){
#ifdef _mydebug
	ifstream cin("input");
	#define debug_info "/****read data from file input****/\n"
#else
	#define debug_info ""
#endif
	
	cout<<debug_info;

	int max=10;
	int pows[10];
	memset(pows,-1,sizeof(int)*10);
	for(int i=0;i<max;++i)
		for(int j=i;j<max;++j)
			for(int k=j;k<max;++k){

				int a,b,c;
				a=pows[i];
				b=pows[j];
				c=pows[k];
				getValue(i,&a,&pows[i]);
				getValue(j,&b,&pows[j]);
				getValue(k,&c,&pows[k]);
				int sum=a+b+c;
				if(sum<100)
					continue;
				if(sum>999)
					return 0;
				cout<<i<<"+"<<j<<"+"<<k<<"=";
				cout<<sum<<endl;
			}
				
	return 0;
}
