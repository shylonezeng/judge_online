#include <iostream>
#include <fstream>
#include <cstring>
#include <utility>
#include <list>
#define MAXSIZE 100

using namespace std;
typedef pair<long int,long int> Boy_t;
typedef	list<Boy_t > BoyList_t;


bool MyCompare(Boy_t a,Boy_t b){
	return a.second<b.second;
}

int  main(int argc ,char **argv){
#ifdef _mydebug
	ifstream cin("input");
	#define debug_info "/****read data from file input****/\n"
#else
	#define debug_info ""
#endif
	
	cout<<debug_info;
	int n,s;
	while(cin>>n>>s){
		if(n==0 && s==0)
			return -1;
		BoyList_t boys;
		for(int i=0;i<n;++i){
			long int has,remain;
			cin>>has>>remain;
			boys.push_back(Boy_t(has,remain));
			
		}	
		
		boys.sort(MyCompare);
		long int sys_rss=s;
		while(!boys.empty()){
			BoyList_t::iterator  ftb=boys.begin();	
			if(sys_rss< ftb->second)
				break;
			sys_rss+=ftb->first;
			boys.erase(ftb);
		}
		if(boys.empty())
			cout<<"YES"<<endl;
		else 
			cout<<"NO"<<endl;
	}
	return 0;
}
