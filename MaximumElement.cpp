#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> stack;
    for(int i=0;i<n;i++){
        int type;
        cin>>type;
        if(type==1){
            int x;
            cin>>x;
            if(stack.empty()){
                stack.push_back(x);
            }
            else{
                int top=stack[stack.size()-1];
                stack.push_back(max(x,top));
            }
        }
        else if(type==2){
            auto itr=stack.end();
            itr--;
            stack.erase(itr);
        }
        else{
            cout<<stack[stack.size()-1]<<endl;
        }
    }
}
