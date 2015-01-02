#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

#define MAXSIZE 100

using namespace std;
#define rows 1000
#define cols 10000
int log[rows][cols];
int knapsack(int *wths,int n, int cap){
	if(n==0 || cap==0)
		return 0;
	if(wths[n-1]>cap){
		if(log[n-1][cap]<0)
			log[n-1][cap]=knapsack(wths,n-1,cap);
		return log[n-1][cap];
	}else if(wths[n-1]==cap)
		return cap;
	else{
		int included=log[n-1][cap-wths[n-1]];
		int exclude=log[n-1][cap];
		if(included<0){
			included=knapsack(wths,n-1,cap-wths[n-1]);
			log[n-1][cap-wths[n-1]]=included;
		}
		if(exclude<0){
			exclude=knapsack(wths,n-1,cap);
			log[n-1][cap]=exclude;
		}
		return max(wths[n-1]+included,exclude);
	}
}

int  main(int argc ,char **argv){
#ifdef _mydebug
	ifstream cin("input_4_1000");
#define debug_info "/****read data from file input****/\n"
#else
#define debug_info ""
#endif
	cout<<debug_info;
	int cases;
	cin>>cases;
	for(int icase=0;icase<cases;++icase){
		int n,cap;
		cin>>n>>cap;
		int *wths=new int[n];
		for(int i=0;i<n;++i){
			cin>>wths[i];
		}
		memset(log,-1,sizeof(int)*rows*cols);
		cout<<knapsack(wths,n,cap)<<endl;
		delete[] wths;
	}
	return 0;
}
