#include<iostream>
using namespace std;
class BTree
{
	int id,sal;
	string name,add,desig;
	BTree *lc,*rc;
	public:
	void create();
	void insert(BTree *root,BTree *next);
	int Display_Height(BTree *root);
	void Count_Node(BTree *root);
	void Display_RootNode();
	void Display_InternalNode();
	void Display_Tree(BTree *root);
	void Display_LeafNode();

}*root,*st[100];
void BTree::create()
{
	root = new BTree;
	cout<<"\nEnter ID:";
	cin>>root->id;
	cout<<"\nEnter Name:";
	cin>>root->name;
	cout<<"\nEnter Address:";
	cin>>root->add;
	cout<<"\nEnter Designation:";
	cin>>root->desig;
	cout<<"\nEnter Salary:";
	cin>>root->sal;
	root->lc = NULL;
      root->rc = NULL;
	int ch;
	BTree *next;
	do
	{

		cout<<"\nDo you want to add Info: Yes=1 , No=0:"<<" ";
		cin>>ch;
		if(ch == 1)
		{
			next = new BTree;
			cout<<"\nEnter Id:";
			cin>>next->id;
			cout<<"\nEnter Name:";
			cin>>next->name;
			cout<<"\nEnter Address:";
			cin>>next->add;
			cout<<"\nEnter Designation:";
			cin>>next->desig;
			cout<<"\nEnter Salary:";
			cin>>next->sal;
			next->lc = NULL;
			next->rc = NULL;
			insert(root,next);
		}
	}while(ch == 1);
}
void BTree::insert(BTree *root,BTree *next)
{
	char chr;
	cout<<"\nWhere you want to add new node (Left:L/l,Right:R/r):"<<root->id<<" ";
	cin>>chr;
	if(chr == 'L' || chr == 'l')
	{
		if(root->lc == NULL)
		{
		root->lc = next;
		}
	
		else
		{
			insert(root->lc,next);
		}
	}
	else if(chr == 'R' || chr == 'r')
	{
		if(root->rc == NULL)
		{
			root->rc = next;
		}

		else
		{
			insert(root->rc,next);
		}
	}
		

}
int BTree :: Display_Height(BTree *root)
{
	int lth,rth,flh;
	if(root == NULL)
	{
		return 0;
	}
	else 
	{
		
			lth = Display_Height(root ->lc);
			rth = Display_Height(root ->rc);
			
			if(lth > rth)
			{
				flh = lth + 1;
			}
			else
			{
				flh = rth +1;
			}
	}
	return flh;
	

}


void BTree::Display_Tree(BTree *root)
{
	int top =-1;
	BTree *temp;
	temp = root;
	if(root!=NULL)
	{
		do
		{
			while(temp!= NULL)
			{
				top++;
				st[top] =temp;
				temp = temp->lc;
			}
			if(top!=-1)
			{
				temp = st[top];
				top--;
				cout<<"\n"<<temp->id<<"\t"<<temp->name<<"\t"<<temp->add<<"\t"<<temp->desig<<"\t"<<temp->sal<<endl;
				temp=temp->rc;
			}
		}while(temp!=NULL || top!=-1);
	}
}
void BTree :: Count-Node(BTree *root)
{
	int n=0;
	int top =-1;
	BTree *temp;
	temp = root;
	if(root == NULL)
	{
		do
		{
			while(temp!= NULL)
			{
				top++;
				st[top] =temp;
				temp = temp->lc;
			}
			if(top!=-1)
			{
				temp = st[top];
				top--;
				if(root == NULL)
				{
					return;
				}
				else
				{
					n = 1 + Count-Node(root -> lc);
					n = 1 + Count-Node(root -> lc);
					return n;
				}
				
			}
		}while(temp!=NULL || top!=-1);
	}

}
void BTree :: Display_RootNode()
{
	int top =-1;
	BTree *temp;
	temp = root;
	if(root!=NULL)
	{
		do
		{
			while(temp!= NULL)
			{
				top++;
				st[top] =temp;
				temp = temp->lc;
			}
			if(top!=-1)
			{
				temp = st[top];
				top--;
				if(temp == root)
				{
					cout<<"\n Root Node Id: "<<temp->id;				
				}
				temp = temp-> rc;
				
			}
		}while(temp!=NULL || top!=-1);
	}
}
void BTree :: Display_InternalNode()
{
	int top =-1;
	BTree *temp;
	temp = root;
	if(root!=NULL)
	{
		do
		{
			while(temp!= NULL)
			{
				top++;
				st[top] =temp;
				temp = temp->lc;
			}
			if(top!=-1)
			{
				temp = st[top];
				top--;
				if((temp->lc != NULL || temp->rc != NULL) && temp != root)
				{
					cout<<"\n Intermediate Node Id: "<<temp->id;					
				}
				temp = temp-> rc;
			}
		}while(temp!=NULL || top!=-1);
	}
}
void BTree :: Display_LeafNode()
{
	int top =-1;
	BTree *temp;
	temp = root;
	if(root!=NULL)
	{
		do
		{
			while(temp!= NULL)
			{
				top++;
				st[top] =temp;
				temp = temp->lc;
			}
			if(top!=-1)
			{
				temp = st[top];
				top--;
				if(temp->lc == NULL && temp->rc == NULL)
				{
					cout<<"\n Leaf Node Id: "<<temp->id;
				}
				temp = temp-> rc;
			}
		}while(temp!=NULL || top!=-1);
	}
}
int main()
{
	BTree t;
	int choice;
	
	do
	{
		cout<<"\n1.Create Tree\n2.Display Tree\n3.Display Root Node\n4.Display Internal Node\n5.Display Leaf Node\n6.Display Height\n7.Count Nodes\n";
		cout<<"Enter your choice :";
		cin>>choice;
		switch(choice)
		{
			case 1: 
			t.create();
			break;
			case 2: 
			cout<<"\nEmp_Id\tEmp_Name\tEmp_add\tEmp_desig\tEmp_sal\n";
			t.Display_Tree(root);
			break;
			case 3:
			t.Display_RootNode();
			break;
			case 4:
			t.Display_InternalNode();
			break;
			case 5:
			t.Display_LeafNode();
			break;
			case 6:
			cout<<"Height of tree :"<<t.Display_Height(root);
			break;
			case 7:
			cout<<"Exiting.......\n";
			break;
			
		}
	}while(choice != 7);
	return 0;
}
