#include<iostream>
using namespace std; 
class Emp
{
	int id,sal; 
	string name,design,add; 
	Emp *lc, *rc; 
	public : 
		void Create(); 
		void Insert(Emp *root, Emp *next); 
		int Height(Emp *root);
		void Display(Emp *root); 
}*root; 
void Emp :: Create()
{
	root = new Emp; 
	Emp *next; 
	int ch; 
	cout<<"\n--------------- Enter Employee Info --------------------"; 
	cout<<"\nEnter Employee ID :"; 
	cin>>root->id;
	cout<<"\nEnter Employee Name :"; 
	cin>>root->name;
	cout<<"\nEnter Employee Designation :"; 
	cin>>root->design; 
	cout<<"\nEnter Employee Address :"; 
	cin>>root->add; 
	cout<<"\nEnter Employee Salary :"; 
	cin>>root->sal; 
	 root->lc = NULL; 
	 root->rc = NULL; 
	 
	 do
	 {
		 cout<<"\nDo you want to add more Emp Info? (press Yes=1, NO=0): "; 
		 cin>>ch; 
		 if(ch==1)
		 {
				next = new Emp; 
				cout<<"\n--------------- Enter New Employee Info --------------------"; 
				cout<<"\nEnter Employee ID :"; 
				cin>>next->id;
				cout<<"\nEnter Employee Name :"; 
				cin>>next->name;
				cout<<"\nEnter Employee Designation :"; 
				cin>>next->design; 
				cout<<"\nEnter Employee Address :"; 
				cin>>next->add; 
				cout<<"\nEnter Employee Salary :"; 
				cin>>next->sal;
				next->lc = NULL; 
				next->rc = NULL; 
				Insert(root, next); 
		 }
	 }while(ch==1); 
}

void Emp :: Insert(Emp *root, Emp *next)
{
		char chr; 
		cout<<"\nEnter Where you want to insert new Emp info -> Left/Right of ID : "<<root->id<<" ";
		cin>>chr; 
		
		if(chr == 'L' || chr == 'l') 
		{
			if(root->lc == NULL)
			{
				root->lc = next; 
			}
			else 
			{
				Insert(root->lc, next); 
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
				Insert(root->rc, next); 
			}
		}	
}
int Emp :: Height(Emp *root)
{
	int lfth,rth,flh;
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		lfth = Height(root ->lc);
		rth = Height(root ->rc);
		
		if(lfth > rth)
		{
			lfth = lfth + 1;
		}
		else
		{
			rth = rth +1;
		}
	}
	return flh;
	cout<<"Height of tree is :"<<flh;

}
	
void Emp :: Display(Emp *root)
{
	if(root == NULL)
	{
		return; 
	}
	else
	{ 
		
		Display(root->lc);
		cout << "\n"<< root->id<<"\t"<< root->name<<"\t"<< root->design<<"\t"<< root->add<<"\t"<< root->sal; 
		Display(root->rc); 
	}
}

int main()
{
	Emp e; 
	e.Create(); 
	int Height(Emp *root);
	cout<<"\nEmp_Id\tEmp_Name\tEmp_design\tEmp_add\tEmp_sal\n";
	e.Display(root); 
	return 0; 
}
