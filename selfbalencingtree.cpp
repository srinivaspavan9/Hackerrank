/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

int height(node* root)
{
    if(root==NULL) return -1;
    return 1+max(height(root->left),height(root->right));
}

node* newNode(int data){
    node* n=new node;
    n->val=data;
    n->left=NULL;
    n->right=NULL;
    n->ht=0;
    return n;
}

int getbal(node* n)
{
    return (height(n->left)-height(n->right));
}

node* leftrot(node* x)
{
    node* y=x->right;
    x->right=y->left;
    y->left=x;
    x->ht=max(height(x->left),height(x->right))+1;
    y->ht=max(height(y->left),height(y->right))+1;
    return y;
}

node* rightrot(node* x)
{
    node* y=x->left;
    x->left=y->right;
    y->right=x;
    x->ht=max(height(x->left),height(x->right))+1;
    y->ht=max(height(x->left),height(x->right))+1;
    return y;
}

node* insert(node * root,int val)
{
    if(root==NULL)
        return newNode(val);
    if(val<root->val)
        root->left=insert(root->left,val);
    else if(val>root->val)
        root->right=insert(root->right,val);
    else return root;
    
    root->ht=1+max(height(root->left),height(root->right));
    int b=getbal(root);
    if(b>1 && val<root->left->val){
        return rightrot(root);
    }
    if(b<-1 && val>root->right->val){
        return leftrot(root);
    }
    if(b>1 && val>root->left->val){
        root->left=leftrot(root->left);
        return rightrot(root);
    }
    if(b<-1 && val<root->right->val){
        root->right=rightrot(root->right);
        return leftrot(root);
    }
    return root;
}
