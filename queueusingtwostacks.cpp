#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        vector<int> stack1;
        vector<int> stack2;
        if(t==1){
            int x;
            cin>>x;
            stack1.push_back(x);
        }
        else if(t==2){
            if(!stack2.empty()){
                auto itr1=stack2.end();
                itr1--;
                stack2.erase(itr1);
            }
            else{
                for(int i=0;i<(int)stack1.size();i++){
                    stack2.push_back(stack1[i]);
                }
                auto itr2=stack2.end();
                itr2--;
                stack2.erase(itr2);
            }
        }
        else{
            if(!stack2.empty()){
                cout<<stack2.back()<<endl;
            }
            else{
                for(int i=0;i<(int)stack1.size();i++){
                    stack2.push_back(stack1[i]);
                }
                cout<<stack2.back()<<endl;
            }
        }
    }
}
