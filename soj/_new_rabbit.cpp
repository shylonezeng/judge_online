#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <deque>
#include <queue>

#define MAXSIZE 100

using namespace std;
typedef string nrabbit_type;
/*task:calculate f and s;
 *test status: ok;
 * */   
void bigdata_plus(string f,string s ,string &res){
	int flen,slen;
	flen=f.size();
	slen=s.size();
	int fp=flen-1,sp=slen-1;
	int reserved_sum[MAXSIZE];
	memset(reserved_sum,0,sizeof(int)*MAXSIZE);
	int sump=0;
	bool over_bit=false;
	while(fp>=0 || sp>=0){
		int first,second;
		if(fp<0)
			first=0;
		else
			first=(int)(f[fp]-'0');
		if(sp<0)
			second=0;
		else
			second=(int)(s[sp]-'0');
		int bit_sum=first+second;
		if(over_bit)
			bit_sum+=1;
		reserved_sum[sump]+=(bit_sum%10);
		//judge if over carry next bit
		if(bit_sum>9)
			over_bit=true;
		else 
			over_bit=false;	

		fp--;	sp--;
		sump++;
	}
	if(over_bit)
		reserved_sum[sump++]=1;
	
// 	nrabbit_type temp_sum;
// 	if(fp>=0)
// 		temp_sum=string(f,0,fp);
// 	if(sp>=0)
// 		temp_sum=string(s,0,sp);
//  	if(reserved_sum[sump]>0)
//  		temp_sum+=(char)(reserved_sum[sump]+'0');
//  	
	sump--;
	res="";
	for(int i=sump;i>=0;--i)
		res+=(char)(reserved_sum[i]+'0');
}

string simulate(int m,int d,nrabbit_type &res)
{
	nrabbit_type adult="1";
	if(d<=m){
		char temp_res[MAXSIZE];
		sprintf(temp_res,"%d",d+1);
		res=temp_res;
		return res;
	}
	deque<nrabbit_type> dq(m,"1");
	queue<nrabbit_type> queue(dq);
	/**/
	for(int i=m;i<d;++i){
		nrabbit_type  front=queue.front();
		queue.pop();
		
		nrabbit_type new_adult;
		bigdata_plus(adult,front,new_adult);
		queue.push(new_adult);

		adult=new_adult;
	}
	/*caolculate sum of all rabbits*/	
	res=adult;
	while(!queue.empty()){
		nrabbit_type front=queue.front();
		queue.pop();

		bigdata_plus(res,front,res);
	}
	return res;
}

int  main(int argc ,char **argv){
#ifdef _mydebug
	ifstream cin("input");
	#define debug_info "read data from file input\n"
#else
	#define debug_info ""
#endif
	
	cout<<debug_info;
// 	cout<<"hello, oj template"<<endl;
	int m,d;
	while(cin>>m>>d){
		if(m==0 && d==0)
			return -1;
		string ret;
		simulate(m,d,ret);
		cout<<ret<<endl;
	}
	return 0;
}

/*for test
int main(){
	string res;
	string a,b;
	while(cin>>a>>b){
		bigdata_plus(a,b,res);
		cout<<res<<endl;
	}
}*/
