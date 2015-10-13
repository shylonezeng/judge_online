#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iterator>

using namespace std;



vector<int> kmp(string pattern ,string src){
	int pt_len=pattern.length();
	//简历next数组
	map<char,int> mmap;
	
	for(int i=0;i<pt_len;++i){
						char key=pattern[i];

		if(0==1){
			char key=pattern[0];
			mmap[key]=0;
		}
		else{
			int j;
			for(j=pt_len-1;j>0;j--){
					string pre_str=pattern.substr(1,j);
					string post_str=pattern.substr(pt_len-j,j);
					if(pre_str==post_str)
					{
						mmap[key]=j;
						break;
					}			
			}
			if(0==j)
				mmap[key]=0;
		}
	}
	vector<int> result;
	//开始匹配
	int plen=pattern.length();
	int slen=src.length();
	for(int i=0;i<slen;){
		int ok_count=0;
		int step=1;  //移动步数
		
		int j=1;
		for(j=0;j<plen;++j){
			if(pattern[j]==src[i+j])
				ok_count+=1;
			else{
				int step= ok_count-mmap[pattern[j]];
				break;
			}
		}
		if(plen==j)
			result.push_back(i);
		i+=step;
	}

	return  result;
}
int main(void){
#ifdef _mydebug
#define dinfo "read data specified file\n"
    ifstream cin("input");
#else
#define dinfo ""
#endif
	string  a,b;
	while(cin>>a>>b){
		vector<int> rt=kmp(a,b);
		copy(rt.begin(),rt.end(),ostream_iterator<int>(cout," "));
	}
}
