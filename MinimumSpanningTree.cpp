#include<iostream>
using namespace std;
class MSTree
{
	int v;
	string city[10];
	int adj[20][20];
	public:
	void CreateGraph();
	void DisplayMatrix();
	void MST();
};
void MSTree :: CreateGraph()
{
	cout<<"\nEnter no.of cities:";
	cin>>v;
	cout<<"\nEnter city Names :";
	for(int i=0;i<v;i++)
	{
		cin>>city[i];
	}
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(i == j)
			{
				adj[i][j] = 0;
			}
			else
			{
				cout<<"Enter Fuel for"<<" "<<city[i]<<" "<<"TO"<<" "<<city[j]<<":";
				cin>>adj[i][j];
			}
		}
	}
}
void MSTree :: DisplayMatrix()
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
void MSTree :: MST()
{
	int u,i,j;
	int min;
	int key[10];
	int parent[10];
	bool visited[10];
	
	for(i=0;i<v;i++)
	{
		key[i] = 999;
		visited[i] = false;
	}
	key[0] = 0;
	parent[0] = -1;
	
	for(int e=0;e<v-1;e++)
	{
		min = 999;
		for(int i=0;i<v;i++)
		{
			if(!visited[i] && min > key[i])
			{
				min = key[i];
				u = i;
			
			}
				
		}
		visited[u] = true;
		for(j=0;j<v;j++)
		{
			if(adj[u][j] && !visited[j] && adj[u][j] < key[j])
			{
				key[j] = adj[u][j];
				parent[j] = u;
			}
		
		}
				
	}
	//Displaying Minimum Spanning Tree
	int sum = 0;
	for(i=0;i<v;i++)
	{
		sum = sum + key[i];
	}
	cout<<"\nTotal Cost of MST :"<<sum;
	cout<<"\n=================================Minimum Distance Between Selected Cities======================================";
	for(i=1;i<v;i++)
	{
		cout<<"\n" <<city[parent[i]] << " To " <<city[i] <<" : " <<key[i] <<endl;
	}
	
	
}
int main()
{
	MSTree m1;
	int ch;
	do
	{
		cout<<"\n=====================================MENU===========================\n";
		cout<<"\n1.Create Graph\n2.Display Matrix\n3.Display MST\n4.Exit\n";
		cout<<"\nEnter your choice :";
		cin>>ch;
		switch(ch)
		{
			case 1 :
			m1.CreateGraph();
			break;
			case 2 :
			m1.DisplayMatrix();
			break;
			case 3 :
			m1.MST();
			break;
			case 4 :
			cout<<"\nExiting............\n";
		
		}
	}while(ch != 4);
return 0;

}
