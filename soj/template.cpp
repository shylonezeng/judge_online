#include <iostream>
#include <fstream>
#include <cstring>

#define MAXSIZE 100

using namespace std;

int  main(int argc ,char **argv){
#ifdef _mydebug
	ifstream cin("input");
	#define debug_info "/****read data from file input****/\n"
#else
	#define debug_info ""
#endif
	
	cout<<debug_info;
	int m,d;
	while(cin>>m>>d){
		if(m==0 && d==0)
			return -1;
	}
	return 0;
}
