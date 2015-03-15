#include <stack>
#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
      ListNode(int *list,int len){
          if(len<=0)
            return;
          val=list[0];
          ListNode *pre=this;
          ListNode *pnode;
          for(int i=1;i<len;i++){
              pnode=new ListNode(list[i]);
              pre->next=pnode;
              pre=pnode;
          }
          pnode->next=NULL;
          
      }
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p1=l1;
        ListNode *p2=l2;
        
        ListNode *rst=new ListNode(-1);
        ListNode **tail;//=new ListNode*;
        *tail=rst;
        
        int carry=0;
        while(p1!=NULL){
            int a=p1->val,b=0;
            int sum=0;
            if(p2!=NULL){
                b=p2->val;
                p2=p2->next;
            }
            else
                b=0;
            sum=a+b+carry;
            
            if(sum>9){
                carry=1;
                sum-=10;
            }else   carry=0;
            //insert one element        
            push(tail,sum);
          
            p1=p1->next;
        }
        while(p2!=NULL){
            int sum=p2->val+carry;
    
            if(sum>9){
                carry=1;
                sum-=10;
            }else   carry=0;
            
            //insert one element
           push(tail,sum);
         
            
           p2=p2->next;
        }
      
        if(carry){
            push(tail,1);
            
        }
        return rst->next;
   
    }
    void push(ListNode **tail,int elmt){
            ListNode *pnode=new ListNode(elmt);
            pnode->next=NULL;
            (*tail)->next=pnode;
            
            *tail=pnode;
    }

    
};


int main(int argc,char **argv){
    
    Solution slt;
    int l[]={9,9};
    ListNode p1(1);
    ListNode p2(l,2);
    
    ListNode *rst=slt.addTwoNumbers(&p1,&p2);
    
    /*print off result*/
    while(rst!=NULL){
        cout<<"->"<<rst->val;
        rst=rst->next;
    }
    
    return 0;
}
