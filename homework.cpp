#include<iostream>
#include<set>
using namespace std;
int group[10000];

int find_root(int x,int count);
int main(){
    int t,n,temp;
    cin>>t;
    while(t--){
        set<int> final_group;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>group[i];
            group[i]--;//減1來符合題目要求
            
        }
        for(int i=0;i<n;i++){
            temp=find_root(group[i],0);
            if(final_group.count(temp)==false){//若set內沒有temp，表示為新的一組
                final_group.insert(temp);
            }
        }
        cout<<final_group.size()<<endl;
    }
    
}
int find_root(int x,int count){
    if(group[x]==x){
        return x;
    }
    if(count>x+1000){//若找不到源頭1000次，使group[x]=x;
        group[x]=x;
        return x;
    }
    int root=find_root(group[x],count+1);//將途中經過的所有人組別改成與源頭同一組
    
    group[x]=root;
    return root;
};
