#include<iostream>
#include<string.h>
using namespace std;

typedef struct node
{
	string word;
	string meaning;
	int fact;
	node *left;
	node *right;

}node;

class bst
{
	public:

		int diff(node*);
		void display(node*);

		node* LL(node *);
		node* RR(node*);
		node* RL(node*);
		node* LR(node*);

		int search(node*,string);

		node* insert(node*,string,string);
		node* balance(node*);
		int height(node*);

		void update(node*,string);
		void disprev(node*);
};
void bst::update(node *root,string key)
{
	int temp;
	temp = search(root,key);
	if(temp==1)
	{
		//cout<<"\nCurrent meaning of  "<<root->word<<"  is  "<<temp->meaning;
	}
	else
	{
		cout<"\nDoesn't Exist\n";
	}
}
int bst::search(node *root,string key)
{
	if(root==NULL)
	{
		return 0;
	}
	if(key.compare(root->word)==0)
	{
		cout<<"\n key is : "<<key ;
		cout<<"\n root->word : "<<root->word<<"   meaning : "<<root->meaning;
		cout<<"\nEnter the new meaning\n";
		cin>>root->meaning;
		return 1;
	}
	else if(key.compare(root->word)<0)
	{
		search(root->left,key);
	}

	else if(key.compare(root->word)>0)
	{
		search(root->right,key);
	}
	//return NULL;
}

int bst::height(node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
int bst::diff(node *temp)
{
	int l = height(temp->left);
	//cout<<"\nL : "<<l;
	int r = height(temp->right);
	//cout<<"\nR : "<<r<<endl;
	int f = l-r;
	return f;
}
node* bst::LL(node *parent)
{
	node *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}
node* bst::RR(node *parent)
{
    node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
node* bst::LR(node *parent)
{
	node *temp;
	temp = parent->left;
	parent->left = RR(temp);
	return LL(parent);
}
node* bst::RL(node *parent)
{
    node *temp;
    temp = parent->right;
    parent->right = LL(temp);
    return RR(parent);
}
node* bst::balance(node *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = LL(temp);
        else
            temp = LR(temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = RL(temp);
        else
            temp = RR(temp);
    }
    return temp;
}
node* bst::insert(node *root, string value,string mean)
{
    if (root == NULL)
    {
        root = new node;
        root->word = value;
		root->meaning = mean;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if ((value.compare(root->word))<0)
    {
        root->left = insert(root->left, value,mean);
        root = balance (root);
    }
    else if ((value.compare(root->word))>0)
    {
        root->right = insert(root->right, value,mean);
        root = balance (root);
    }
    return root;
}
void bst::display(node* root)
{
	if(root)
	{
		display(root->left);
		cout<<root->word<<" means "<<root->meaning<<endl;
		display(root->right);
	}
}
void bst::disprev(node *root)
{
	if(root)
	{
		disprev(root->right);
		cout<<root->word<<" means "<<root->meaning<<endl;
		disprev(root->left);
	}
}
int main()
{
	bst obj;
	node *rt;
	int ch;
	int choice;
	char x;
	string key,mean;
	string keys;
	rt = NULL;
	do
	{
		cout<<"\nEnter Choice\n";
		cout<<"\n1.Insert the data into dictionary. \n2.Update the dictionary ";
		cout<<"\n3.Display the data in ascending order.\n4.Display the data in descending order";
		cin>>choice;
		switch(choice)
		{
			case 1:
					do
					{
						cout<<"\nEnter the word\n";
						cin>>key;
						cout<<"\nEnter the meaning of the word\n";
						cin>>mean;
						rt = obj.insert(rt,key,mean);
				//cout<<"\nROOT is : "<<rt->word;
						cout<<"\nDo you want to insert more words? Y or N\n";
						cin>>x;
					}while(x=='y'||x=='Y');
					break;
			case 2:
					cout<<"\nEnter the word whose meaning is supposed to be updated\n";
					cin>>keys;
					obj.update(rt,keys);
					break;
			case 3:
					cout<<"\nDisplay :\n";
					obj.display(rt);
					break;
			case 4:
					cout<<"Reverse display:\n";
					obj.disprev(rt);
					break;
		}
		cout<<"\nDo you wish to continue? Y or N \n";
		cin>>x;
	}while(x=='y' || x=='Y');
	return 0;
}

