#include<iostream>
using namespace std; 
class Emp
{
	int id, salary; 
	string name, address, desig; 
	Emp *next; 
	public : 
		void Accept(); 
		void Display(); 
		//void Search(); 
		//void Delete(); 
		//void DisplayTotal(); 
}*start=NULL; 
void Emp :: Accept()
{
	Emp *newnode = new Emp; 
	cout<<"\nEnter Employee ID :"; 
	cin>>newnode->id; 
	cout<<"\Enter Employee Name :";
	cin>>newnode->name; 
	cout<<"\nEnter Employee Designation:"; 
	cin>>newnode->desig; 
	cout<<"\nEnter Employee Address :"; 
	cin>>newnode->address; 
	cout<<"\nEnter Salary :"; 
	cin>>newnode->salary; 
	
	if(start == NULL)
	{
		start = newnode;
	} 
	else 
	{
		Emp *temp = start; 
		while(temp->next!=NULL)
		{
			temp=temp->next; 
		}
		temp->next = newnode; 
		newnode = NULL; 	
	}
} 
void Emp :: Display()
{
	Emp *temp = start; 
	if(temp == NULL)
	{
		cout<<"\nEmployee Record is Empty "; 
	}
	else 
	{
		while(temp!=NULL)
		{
			cout<<"\n---------------Employee Record----------------"; 
			cout<<"\nEmployee ID :"<<temp->id; 
			cout<<"\nEmployee Name :"<<temp->name; 
			cout<<"\nEmployee Address :"<<temp->address; 
			cout<<"\nEmployee Designation :"<<temp->desig; 
			cout<<"\nEmployee Salary :"<<temp->salary; 
			temp = temp->next; 
		}
	}
}
int main()
{
	Emp e; 
	e.Accept(); 
	e.Display(); 
	return 0; 
}








