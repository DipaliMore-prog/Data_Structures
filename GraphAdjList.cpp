#include<iostream>
using namespace std;
class GR
{
	int fuel,v;
	string city;
	GR *next;
	public:
	void AcceptCity();
	void AddEdge();
	void Display();

}*head[10];
void GR :: AcceptCity()
{
	cout<<"Enter no.of cities : ";
	cin>>v;
	cout<<"Enter City Names :";
	for(int i=0;i<v;i++)
	{
		head[i] = new GR;    //allocate memory to node upto no.of cities entered
		cin>>head[i]->city;
		head[i]->next = NULL;
	}

}
void GR :: AddEdge()
{
	string s,d;
	int e,i,j;
	GR *n1,*temp;
	cout<<"\nEnter no.of edges:";
	cin>>e;
	for(i=0;i<e;i++)
	{
		cout<<"\nEnter source and Destination cities :";
		cin>>s>>d;
		for(j=0;j<v;j++)
		{
			if(head[j]->city == s)
			{
				break;
			}
		}
		n1 =new GR;	  //newNode
		n1->city=d;
		cout<<"\nEnter Fuel :";	   //Fuel for newNode
		cin>>n1->fuel;
		n1->next=NULL;
		temp = head[j];     // points to source city
		while(temp ->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next =n1;
	}

}
void GR :: Display()
{
	GR *temp;
	for(int i=0;i<v;i++)
	{
		temp = head[i];
		while(temp!=NULL)
		{
		
			cout<<" "<<temp->city<<"->"<<temp->fuel<<"->";
			temp = temp->next;
		}
			cout<<"NULL\n";
	}

}
int main()
{
	GR g;
	int ch;
	cout<<"\n====================MENU===================\n";
	do
	{
		cout<<"\n1.Accept City\n2.Add Edges\n3.Display List\n4.Exit";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				g.AcceptCity();
				break;
			case 2:
				g.AddEdge();
				break;
			case 3:
				g.Display();
				break;
			case 4:
				cout<<"\nExiting.....\n";
				break;
		}
	}while(ch !=4);

	return 0;

}
