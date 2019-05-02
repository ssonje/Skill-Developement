#include<iostream>
using namespace std;
struct Node
{
struct Node *left, *right;
int info;
int rf,lf=0;
};
struct Node *insert(struct Node *root, int key)
{
Node *temp = root;
Node *par = NULL;
while (temp!= NULL)
{
if (key == (temp->info))
{
cout<<"Duplicate Key !\n";
return root;
}
par = temp;
if (key < temp->info)
{
if (temp -> lf == 0)
temp = temp -> left;
else
break;
}
else
{
if (temp->rf == 0)
temp =temp  -> right;
else
break;
}
}
Node *tmp = new Node;
tmp -> info = key;
tmp -> lf = 1;
tmp -> rf = 1;
if (par == NULL)
{
root = tmp;
tmp -> left = NULL;
tmp -> right = NULL;
}
else if (key < (par -> info))
{
tmp -> left = par -> left;
tmp -> right = par;
par -> lf = 0;
par -> left = tmp;
}
else
{
tmp -> left = par;
tmp -> right = par -> right;
par -> rf = 0;
par -> right = tmp;
}

return root;
}
struct Node *inorderSuccessor(struct Node *ptr)
{
if (ptr -> rf == 1)
return ptr->right;
ptr = ptr -> right;
while (ptr -> lf== 0)
ptr = ptr -> left;
return ptr;
}
void inorder(struct Node *root)
{
if (root == NULL)
cout<<"Tree is empty";
struct Node *ptr = root;
while (ptr -> lf == 0)
ptr = ptr -> left;
while (ptr != NULL)
{
cout<<ptr -> info<<"\t";
ptr = inorderSuccessor(ptr);
}
}
int main()
{
struct Node *root = NULL;
root = insert(root, 20);
root = insert(root, 10);
root = insert(root, 30);
root = insert(root, 5);
root = insert(root, 16);
root = insert(root, 14);
root = insert(root, 17);
root = insert(root, 13);
inorder(root);
return 0;
}
