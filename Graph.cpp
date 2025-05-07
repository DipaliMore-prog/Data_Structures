#include<iostream>
using namespace std;
class Graph
{
	int v,fuel;
	string city[20];
	int adj[100][100];
	public:
	void Accept();
	void Display();
};
void Graph :: Accept()
{	int i,j;
	cout<<"Enter no. of cities you want to store : ";
	cin>>v;
	cout<<"Enter city Names: ";
	for(int i=0;i<v;i++)
	{
		cin>>city[i];
	}
	cout<<"\n==============Enter Required Fuel==================\n";
	for( i=0;i<v;i++)	//Represent Rows
	{
		for( j=0;j<v;j++)	//Represent Columns
		{
			if(i == j)
			{
				adj[i][j] = 0;
			}
			else
			{
				cout<<"Enter fuel for "<<city[i]<<" "<<"To"<<" "<<city[j]<<":";
				cin>>adj[i][j];
				cout<<" ";
			}
		}
	}
}
void Graph :: Display()
{
	cout<<"\nFuel matrix :\n";
	cout<<"  ";
	for(int i=0;i<v;i++)
	{
		cout<<city[i]<<"  ";
		
	}
	cout<<endl;
	for(int i=0;i<v;i++)
	{
		cout<<city[i];
		for(int j=0;j<v;j++)
		{
			
			cout<<" "<<adj[i][j];
		
		}
		cout<<endl;
	}
}
int main()
{
	Graph g;
	int ch;
	cout<<"\n=======================MENU=========================\n";
	do
	{
		cout<<"\n1.Accept Data\n2.Display Data\n3.Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			g.Accept();
			break;
			case 2:
			g.Display();
			break;
			case 3:
			cout<<"\nExiting......\n";
			break;
		}
	}while(ch != 3)

}
