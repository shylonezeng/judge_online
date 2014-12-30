#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <list>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>

#define MAXSIZE 100

using namespace std;
typedef struct HaffNode_t{
	HaffNode_t *left;
	HaffNode_t *right;
	//available to leaf node
	char data;
	int num;
}HaffNode_t ;
/**/
template<typename A ,typename B>
std::pair<B,HaffNode_t*> flip_pair(const std::pair<A,B> &p){
	HaffNode_t* hnode=new HaffNode_t();
	hnode->left=NULL;
	hnode->right=NULL;
	hnode->data=p.first;
	hnode->num=p.second;
	return std::pair<B,HaffNode_t*>(p.second,hnode);
	
}
template<typename A,typename B>
std::multimap<B,HaffNode_t*> flip_map(const std::map<A,B> &src){
	multimap<B,HaffNode_t*> dst;
	transform(src.begin(),src.end(),std::inserter(dst,dst.begin()),flip_pair<A,B>);
	return dst;
}

template<typename A>
void ShowMap(A &s){
		typename A::iterator iter=s.begin();
		while(iter!=s.end()){
// 			cout<<"first:"<<iter->first<<"\tsecond:"<<iter->second<<endl;
// 			cout<<"value:"<<iter->first<<"\tleft:"<<iter->second->left->num<<"\tright:"<<iter->second->right->num<<iter->second->right->data<<endl;
			iter++;
		}
}

// typedef struct EncodedNode{
// 	HaffNode_t *q
// 	string ;
// }
bool travel(HaffNode_t *root,string code){
	if(root==NULL)
		return false;
// 	if(root->left!=NULL){
// 		string l_code=code;
// 		l_code+='0';
// 		travel(root->left,l_code);
// 	}
// 	if(root->right!=NULL){
// 		string r_code=code;
// 		r_code+='1';
// 		travel(root->right,r_code);
// 	}
	typedef pair<HaffNode_t*,string> Item_HaffEncode;
	typedef queue<Item_HaffEncode> HaffEncode; ;
	HaffEncode queue;
	queue.push(Item_HaffEncode(root,""));
	
// 	typedef map<HaffNode_t*,string> 
	while(!queue.empty()){
		Item_HaffEncode hfcode=queue.front();
		queue.pop();
		
		if(hfcode.first->right!=NULL){
			string rcode=hfcode.second+'1';
			queue.push(Item_HaffEncode(hfcode.first->right,rcode));
		}
		if(hfcode.first->left!=NULL){
			string lcode=hfcode.second+'0';
			queue.push(Item_HaffEncode(hfcode.first->left,lcode));
		}
		if(hfcode.first->left==NULL && hfcode.first->right==NULL)
			cout<<hfcode.first->data<<" "<<hfcode.first->num<<" "<<hfcode.second<<endl;
	}
	return true;
}

int  main(int argc ,char **argv){
#ifdef _mydebug
	ifstream cin("input");
	#define debug_info "/****read data from file input****/\n"
#else
	#define debug_info ""
#endif
	
	cout<<debug_info;
	int n;
	while(cin>>n){
		if(n<=0)
			return -1;
		typedef map<char,int> ChMap_t;
		ChMap_t chs;
		for(int i=0;i<n;++i){
			char ch;
			cin>>ch;
			ChMap_t::iterator iter=chs.find(ch);
			if(iter==chs.end()){
				chs[ch]=1;
			}
			else {
				chs[ch]+=1;
			}
		}
// 		ShowMap<ChMap_t>(chs);

		typedef multimap<int ,HaffNode_t*> RMap_t;
		RMap_t rchs=flip_map<char,int>(chs);
		/*create haffman tree*/
// 		RMap_t::iterator iter=rchs.begin();
		while(rchs.size()>1){
			
			RMap_t::iterator iter=rchs.begin();
			int new_first=iter->first;
			HaffNode_t* n_node=new HaffNode_t;
			n_node->data=' ';
			n_node->left=(iter->second);
			rchs.erase(iter);
#ifdef _mydebug
			cout<<"top one:first:"<<iter->first<<"\tsecond:"<<iter->second->data<<endl;
#endif

			iter=rchs.begin();
			new_first +=iter->first;
			n_node->num=new_first;
			n_node->right=(iter->second);	
			rchs.erase(iter);	
#ifdef _mydebug
			cout<<"top two:first:"<<iter->first<<"\tsecond:"<<iter->second->data<<endl;
#endif
			//add new elment to multimap
			rchs.insert(pair<int,HaffNode_t*>(new_first,n_node));	
		}
		ShowMap<RMap_t>(rchs);
		/*travel created haffman tree*/
		HaffNode_t *root;
		if(rchs.empty())
			root=NULL;
		else
			root=(rchs.begin()->second);
		string code;
 		travel(root,code);		
	}
	return 0;
}
