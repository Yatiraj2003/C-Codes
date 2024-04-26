#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    struct Node*left;
    int data;
    struct Node*right;
}*node;

node root,newnode,head,temp;
node InsertNode(node,node);
node getnode(node);
node DeleteNode(node,int);
void display(node);
int main()
{
    int n,key;
    root=NULL;
    while(1)
    {
        printf("Choose the option\n");
        printf("1:Insert node\n 2:Preorder\n 3:Postorder\n 4:Inorder\n 5:Delete node\n 6:display in hierarchical\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:newnode=getnode(newnode);
                   root=InsertNode(root,newnode);
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

node getnode(node newnode)
{
    int item;
    newnode=(node)malloc(sizeof(struct Node));
    printf("Enter the data\n");
    scanf("%d",&item);
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->data=item;
    return newnode;
}

node InsertNode(node root,node newnode)
{
    if(root==NULL)
    {
        root=newnode;
    }
    else
    {
        if(newnode->data<root->data)
        {
           root->left=InsertNode(root->left,newnode);
        }
        else if(newnode->data>root->data)
        {
            root->right=InsertNode(root->right,newnode);
        }
    }
    return root;
}

node inorderpred(node temp)
{
    while(temp->left!=NULL && temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp;
}
node inordersucc(node temp)
{
    while(temp->right!=NULL && temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}

int NodeHeight(node p)
{
    int hl,hr;
    if(p!=NULL)
    {
        hl=NodeHeight(p->left);
        hr=NodeHeight(p->right);
        return hl>hr?hl+1:hr+1;
    }
    return 0;
}
node DeleteNode(node p, int key)
{
   if(p==NULL)
   {
       return NULL;
   }
   if(p->left==NULL &&p->right==NULL)
   {
       if(p==root)
          root=NULL;
       free(p);
       return NULL;
   }
   if(key>p->data)
       p->right=DeleteNode(p->right,key);
   else if(key<p->data)
       p->left=DeleteNode(p->left,key);
   else
   {
       if(NodeHeight(p->left)>NodeHeight(p->right))
       {
           temp=inorderpred(p->left);
           p->data=temp->data;
           p->left=DeleteNode(p->left,temp->data);
       }
       else
       {
           temp=inordersucc(p->right);
           p->data=temp->data;
           p->right=DeleteNode(p->right,temp->data);
       }
   }
}

void preorder(node root)
{
    if(root!=NULL)
    {
    printf("%d--->",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}
void inorder(node root)
{
    if(root!=NULL)
    {
    inorder(root->left);
    printf("%d--->",root->data);
    inorder(root->right);
    }
}
void postorder(node root)
{
    if(root!=NULL)
    {
    postorder(root->left);
    postorder(root->right);
    printf("%d--->",root->data);
    }
}

