#include<stdio.h>
#include<stdlib.h>

//structure declared for a node
typedef struct Node
{
    struct Node*left;
    int data;
    int height;
    struct Node*right;
}*node;

node root,newnode,head,temp,p,t;
node InsertNode(node,int);
node DeleteNode(node,int);
node balanceCheck(node);
int balancefactor(node);
int NodeHeight(node);
node RRRotation(node);
node LLRotation(node);
node RLRotation(node);
node LRRotation(node);

int main()
{
    int n,key,key1;
    root=NULL;
    while(1)
    {
        printf("Choose the option\n");
        printf(" 1:Insert node\n 2:Preorder\n 3:Postorder\n 4:Inorder\n 5:Delete node\n ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:printf("Enter the element\n");
                 scanf("%d",&key1);
                root=InsertNode(root,key1);
            break;
            case 2: preorder(root);
            break;
            case 3: postorder(root);
            break;
            case 4: inorder(root);
            break;
            case 5:printf("enter the key element to be deleted\n");
                  scanf("%d",&key);
                  root=DeleteNode(root,key);
                  break;
        }
    }
   return 0;
}

//function for inserting node in  tree
node InsertNode(node p,int key1)
{
    if(p==NULL)
    {
        t=(node)malloc(sizeof(struct Node));
        t->data=key1;
        t->height=0;
        t->left=t->right=NULL;
        return t;
    }
    if(key1<p->data)
    {
       p->left=InsertNode(p->left,key1);
    }
    else if(key1>p->data)
    {
        p->right=InsertNode(p->right,key1);
    }
    p->height=NodeHeight(p);
    p=balanceCheck(p);
    return p;
}

//function for finding inorder successor of the particular node
node Inpred(node temp)
{
    while(temp->left!=NULL && temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp;
}
node Insucc(node p)
{
    while(p->left!=NULL &&p->right!=NULL)
    {
        p=p->left;
    }
    return p;
}

//function for delete a node from tree

node DeleteNode(node p,int key)
{
    if(p==NULL)
    {
        return NULL;
    }
    if(p->left==NULL && p->right==NULL)
    {
        if(p==root)
            root=NULL;
        free(p);
        return NULL;
    }
    if(key>p->data)
    {
        p->right=DeleteNode(p->right,key);
    }
    else if(key<p->data)
    {
        p->left=DeleteNode(p->left,key);
    }
    else
    {
        if(NodeHeight(p->left)>NodeHeight(p->right))
        {
            temp=Inpred(p->left);
            p->data=temp->data;
            p->left=DeleteNode(p->left,temp->data);
        }
        else
        {
            temp=Insucc(p->right);
            p->data=temp->data;
            p->right=DeleteNode(p->right,temp->data);
        }
    }
    p->height=NodeHeight(p);
    if(balancefactor(p)>1 && balancefactor(p->left)>=0)
    {
        p=LLRotation(p);
    }
    if(balancefactor(p)<-1 && balancefactor(p->right)<0)
    {
        p=RRRotation(p);
    }
    if(balancefactor(p)>1 && balancefactor(p->left)<=0)
    {
        p=LRRotation(p);
    }
    if(balancefactor(p)<-1 && balancefactor(p->right)>0)
    {
        p=RLRotation(p);
    }
    return p;
}
//function for preorder traversal
void preorder(node root)
{
    if(root!=NULL)
    {
    printf("%d--->",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}

//function for inorder traversal
void inorder(node root)
{
    if(root!=NULL)
    {
    inorder(root->left);
    printf("%d--->",root->data);
    inorder(root->right);
    }
}

//function for postorder traversal
void postorder(node root)
{
    if(root!=NULL)
    {
    postorder(root->left);
    postorder(root->right);
     printf("%d--->",root->data);
    }
}

//function for finding a height of a particular node
int NodeHeight(node p)
{
 int hl=0,hr=0;
 if(p!=NULL)
 {
     hl=NodeHeight(p->left);
     hr=NodeHeight(p->right);
    return hl>hr?hl+1:hr+1;
 }
 return 0;
}

//function for finding balance factor for a node
int balancefactor(node p)
{
 int hl=0,hr=0;
 if(p!=NULL)
 {
 hl=NodeHeight(p->left);
 hr=NodeHeight(p->right);

 return hl-hr;
 }
 return 0;
}

//function for performing LL Rotation if it is LL imbalance
node LLRotation(node p)
{
 node pl=p->left;
 node plr=pl->right;

 pl->right=p;
 p->left=plr;
 p->height=NodeHeight(p);
 pl->height=NodeHeight(pl);

 if(root==p)
   root=pl;

 return pl;
}

//function for performing LR Rotation if it is LR imbalance
node LRRotation(node p)
{
    p->left=RRRotation(p->left);
    p=LLRotation(p);
    return p;
}

//function for performing RR Rotation if it is RR imbalance
node  RRRotation(node p)
{
    node pr=p->right;
    node prr=pr->left;
    pr->left=p;
    p->right=prr;
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    if(root==p)
        root=pr;
 return pr;
}

//function for performing RL Rotation if it is RL imbalance
node RLRotation(node p)
{
  p->right=LLRotation(p->right);
  p=RRRotation(p);
  return p;
}

//function for checking if it is LL,LR,RR&RL imbalance or not
node balanceCheck(node p)
{
     if(balancefactor(p)==2 && balancefactor(p->left)==1)
      {
          p=LLRotation(p);
      }
    else if(balancefactor(p)==2 && balancefactor(p->left)==-1)
    {
        p=LRRotation(p);
    }
    else if(balancefactor(p)==-2 && balancefactor(p->right)==-1)
    {
       p=RRRotation(p);
    }
    else if(balancefactor(p)==-2 && balancefactor(p->right)==1)
    {
       p=RLRotation(p);
    }
  return p;
}
