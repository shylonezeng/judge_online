#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>

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
	cout<<"lagerst integer:"<<std::numeric_limits<int>::max()<<endl;
	cout<<"lagerst long integer:"<<std::numeric_limits<long int>::max()<<endl;
	int m,d;
	while(cin>>m>>d){
		if(m==0 && d==0)
			return -1;
	}
	return 0;
}
