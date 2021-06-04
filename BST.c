#include<stdio.h>
#include<stdlib.h>
struct BSTNode{
    struct BSTNode *left;
    struct BSTNode *right;
    int data;
    
};
void preorder(struct BSTNode *root);
 
 // finding the element
 struct BSTNode* find(struct BSTNode *root,int data)
{
    if(root==NULL)
        return NULL;
    if(data<root->data)
        return(find(root->left,data));
    else if(data>root->data)
        return(find(root->right,data));
    return(root);
}


// inserting the node in the list
void insert( struct BSTNode *root,int data)
{
    struct BSTNode *par;
    struct BSTNode *n=malloc(sizeof(struct BSTNode));
    n->left=NULL;
    n->right=NULL;
    

    if(root==NULL)   // if there is no noode
        n=root;
    else{
        par=root;

        while(par!=NULL)
        {
            if(par->data>data) {    //  data of par> inserting data

                    if(par->left==NULL)      
                        par->left=n;
                    par=par->left;
            
            }  
            else if(par->data<data)  // data of par is < inserting data
            {

                if(par->right==NULL)
                    par->right=n;
                par=par->right;
            }    
            
        }
    }
}


// deletion in bst

// if the element to be deleted is leaf node

// struct BSTNode* Delete(struct BSTNode *root, int data)
// {
//     structBSTNode *temp;
//     if(root==NULL)
//         pirntf("no such elelment exixts");
//     else if(data<root->data)
// }

void preorder(struct BSTNode *root)
{
    if(root)
    {
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    int choice,data;
    struct BSTNode *root=NULL;
    
    while(1)
    {
        printf("/n1.for insert");
        printf("/n2. for display");
        printf("/n3. for exit");
        printf("/nenter choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: 
                    printf("/nenetr data");
                    scanf("%d",&data);
                     insert(root,data);
                    break;
            case 2:
                 preorder(root);
                 break;
            case 3: exit(0);
            default: printf("invalid choice");
        }
    }
}