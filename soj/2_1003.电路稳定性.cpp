#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

#define MAXSIZE 100

using namespace std;

// double recurse(string str, vector<double> &pi){
// // 	cout<<"string:"<<str<<endl;
// 	int len=str.size();
// 	if(len==0)
// 		return 0;
// 	vector<double> sub_parallel;	//suposing that series components come behind parallel ones
// 	vector<double> sub_series;
// 	queue<char> cqueue;
// 	string substr;
// 	bool substr_last=false;
// 
// 	int p=0;
// 	while(p<len){
// 		char ch=str[p];
// 		if(substr_last)
// 			substr+=ch;
// 
// 		switch(ch){
// 			case '(':
// 				{
// 				
// 					if(cqueue.empty())
// 						substr_last=true;
// 					cqueue.push(ch);
// 				}
// 				break;
// 			case ')':
// 				cqueue.pop();
// 				if(cqueue.empty()){
// 					substr_last=false;
// 					//begin solving sub probelem
// 					substr.erase(substr.end()-1);
// 					double sub_result=recurse(substr,pi);			
// 					sub_parallel.push_back(sub_result);
// 					
// 					substr.clear();	
// 				}
// 
// 				break;
// 			case ',':
// 				break;
// 			default:
// 				if(!substr_last){
// 					sub_series.push_back(pi[ch-'A']);
// 				}
// 				break;				
// 		}
// 
// 		p++;
// 	}
// 	double prlpart_result=1;
// 	//
// 	vector<double>::iterator iter=sub_parallel.begin();
// 	while(iter!=sub_parallel.end()){
// 		prlpart_result*=(*iter);
// 		iter++;
// 	}
// 
// 	if(sub_parallel.empty())
// 		prlpart_result=0;
// // 	cout<<"parallel part:"<<prlpart_result<<endl;
// 	// 	double result=1;
// 	double ok=1-prlpart_result;
// 	iter=sub_series.begin();
// 	while(iter!=sub_series.end()){
// 		ok*=1-(*iter);
// 		iter++;
// 	}
// // 	cout<<"sub prolbem res:"<<1-ok<<endl;
// 
// 	return 1-ok;	
// }
enum optype_t{	
	PARALLEL=1,
	SERIES=2
};
double Operator(double first ,double second, int op_flag){
	double result=0;
	string opstr="PARALLEL";
	if(op_flag==SERIES)
	{
		result=first+second-first*second;
	}
	else{
		result=first*second;
		opstr="PARALLEL";
	}
#ifdef _mydebug
	cout<<first<<opstr<<second;
	cout<<" = "<<result<<endl;
#endif
	return result;
}
double recurse(string str, vector<double> &pi){
	// 	cout<<"string:"<<str<<endl;
	int len=str.size();
	if(len==0)
		return 0;
	vector<double> sub_parallel;	//suposing that series components come behind parallel ones
	vector<double> sub_series;
	queue<char> cqueue;
	string substr;
	bool substr_last=false;

	stack<int> opstack; 
	stack<double> numstack;

	int p=0;
	while(p<len){
		char ch=str[p];
		switch(ch){
			case '(':
				opstack.push(-1);
				break;
			case ')':
				{	
					int op=opstack.top();
					opstack.pop();
					while(op>0){
						double first=numstack.top();
						numstack.pop();

						double second=numstack.top();
						numstack.pop();
						numstack.push(Operator(first,second,op));

						op=opstack.top();
						opstack.pop();
					}

					int next=p+1;			
					if(next<len && str[next]=='(')
						opstack.push(PARALLEL);
				}		
				break;
			case ',':
				{
					int op=-2;
					if(!opstack.empty())
						op=opstack.top();
					while(op==PARALLEL){
						opstack.pop();

						double first=numstack.top();
						numstack.pop();

						double second=numstack.top();
						numstack.pop();
						numstack.push(Operator(first,second,op));

						if(opstack.empty())
							break;
						op=opstack.top();	
					}

					opstack.push(SERIES); //not operate currently, delayed for ')' or after this loop
				}
				break;
			default:
				numstack.push(pi[ch-'A']);
				break;				
		}

		p++;
	}

	while(!opstack.empty()){
		int op=opstack.top();	
		opstack.pop();
		if(op>0){
			double first=numstack.top();
			numstack.pop();
			double second=numstack.top();
			numstack.pop();
			numstack.push(Operator(first,second,op));
		}
	}

	return numstack.top();

}
//

int  main(int argc ,char **argv){
#ifdef _mydebug
	ifstream cin("input");
#define debug_info "/****read data from file input****/\n"
#else
#define debug_info ""
#endif

	cout<<debug_info;
	int cmp_num;
	while(cin>>cmp_num){
		if(cmp_num==0)
			return -1;
		string einfo;
		cin>>einfo;
		vector<double> pi;
		for(int i=0;i<cmp_num;++i){
			double p;
			cin>>p;
			pi.push_back(p);
		}
		double  res=recurse(einfo,pi);
		std::cout.precision(4);
		printf("%.4lf\n",res);
		// 		5sprintf(sres,"%.4f\n",res);
		// 
		// 		string::iterator iter=sres.end()-1;
		// 		while(*iter=='0') iter--;
		// 		sres.erase(iter+1,sres.end());
		// 		cout<<sres<<endl;

		//input data
	}
	return 0;
}
