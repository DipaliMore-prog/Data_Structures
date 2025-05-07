#include<iostream>
using namespace std;
class Ems
{
	int id,sal;
	string name,add,desig;
	Ems *lc,*rc;
	public:
	void create();
	void insert(Ems *root,Ems *next);
	void Display_Height(Ems *root);
	void Count_Node(Ems *root);
	void Display_RootNode();
	void Display_InternalNode();
	void Display_Tree(Ems *root);
	void Display_SearchNode(Ems *root,int temp);

}*root;
void Ems::create()
{
	root = new Ems;
	cout<<"\n--------------- Enter Employee Info --------------------"; 
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
	Ems *next;
	do
	{

		cout<<"\nDo you want to add Info: Yes=1 , No=0:"<<" ";
		cin>>ch;
		if(ch == 1)
		{
			next = new Ems;
			cout<<"\n--------------- Enter New Employee Info --------------------"; 
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
void Ems ::insert(Ems *root,Ems *next)
{
	
	if(next -> sal < root -> sal)
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
	else if(next -> sal > root -> sal)
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
void Ems :: Display_Tree(Ems *root)
{
	if(root == NULL)
	{
		return; 
	}
	else
	{ 
		
		Display_Tree(root->lc);
		cout << "\n"<< root->id<<"\t"<< root->name<<"\t"<< root->desig<<"\t"<< root->add<<"\t"<< root->sal; 
		Display_Tree(root->rc); 
	}
}
void Ems :: Display_SearchNode(Ems *root,int temp)
{
	int flag = 0;
		while(root != NULL)
		{
			if(temp == root->sal)
			{
				flag = 1;
				break;
			}
			if(temp < root->sal)
			{
				Display_SearchNode(root -> lc,temp);
				if(temp == root->sal)
				{
					flag = 1;
					break;
				}
				return;
			}
			else if(temp > root -> sal)
			{
				Display_SearchNode(root -> rc,temp);
				if(temp == root->sal)
				{
					flag = 1;
					break;
				}
				return;
			}
				
			if(flag == 1)
			{
				cout<<"\nEmployee Found";	
			}
			else
			{
				cout<<"\nEmployee Not Found";
			}
		}
			

}
int main()
{

	Ems e;
	int choice;
	
	do
	{
		cout<<"\n1.Create Tree\n2.Display Tree\n3.Display Root Node\n4.Display Internal Node\n5.Display Leaf Node\n6.Display Height\n7.Count Nodes\n8.Exit\n";
		cout<<"Enter your choice :";
		cin>>choice;
		switch(choice)
		{
			case 1: 
			e.create();
			break;
			case 2: 
			cout<<"\nEmp_Id\tEmp_Name\tEmp_add\tEmp_desig\tEmp_sal\n";
			e.Display_Tree(root);
			break;
			case 3:
			int temp;
			cout<<"Enter id you want to search: ";
			cin>>temp;
			e.Display_SearchNode(root,temp);
			break;
			/*case 4:
			e.Display_InternalNode();
			break;
			case 5:
			e.Display_LeafNode();
			break;
			case 6:
			cout<<"Height of tree :"<<e.Display_Height(root);
			break;
			case 7:
			cout<<"Count of Nodes : "<<e.Count_Node(root);
			break;*/
			case 4:
			cout<<"Exiting......";
			break;
			
		}
	}while(choice != 4);
	return 0;




}
