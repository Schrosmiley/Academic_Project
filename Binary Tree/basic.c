#include<stdio.h>
#include<stdlib.h>
struct treenode
{
    int val;
    struct treenode *left;
    struct treenode *right;
};
void print(struct treenode *root)
{
    if(root==NULL)
        return ;
    printf("%d ",root->val);
    print(root->left);
    print(root->right);
}
int main()
{
    struct treenode *root = (struct treenode *)malloc(sizeof(struct treenode));
    struct treenode *a = (struct treenode *)malloc(sizeof(struct treenode));
    struct treenode *b = (struct treenode *)malloc(sizeof(struct treenode));
    struct treenode *c = (struct treenode *)malloc(sizeof(struct treenode));
    struct treenode *d = (struct treenode *)malloc(sizeof(struct treenode));
    struct treenode *e = (struct treenode *)malloc(sizeof(struct treenode));
    struct treenode *f = (struct treenode *)malloc(sizeof(struct treenode));
    root->val = 10;
    a->val = 20;
    b->val = 30;
    c->val = 40;
    d->val = 50;
    e->val = 60;
    f->val = 70;
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    b->left = e;
    b->right = f;
    c->left = NULL;
    c->right = NULL;
    d->left = NULL;
    d->right = NULL;
    e->left = NULL;
    e->right = NULL;
    f->left = NULL;
    f->right = NULL;
    print(root);
    return 0;
}