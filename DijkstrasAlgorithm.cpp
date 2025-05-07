#include<iostream>
using namespace std;
class PPS
{
	int v,adj[20][20];
	string city[20];
	public:
	 void Accept();
	 void DisplayMatrix();
	 void SSSP();
	
};
void PPS :: Accept()
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
				cout<<"Enter Distance for"<<" "<<city[i]<<" "<<"TO"<<" "<<city[j]<<":";
				cin>>adj[i][j];
			}
		}
	}
}
void PPS :: DisplayMatrix()
{
	cout<<"\nDistance matrix :\n";
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
			
			cout<<"  "<<adj[i][j];
		
		}
		cout<<endl;
	}
}
void PPS :: SSSP()
{
	int dist[20];
	bool visited[20];
	dist[0] = 0;
	visited[0] = false;
	for(int i=1;i<v;i++)
	{
		dist[i] = 999;
		visited[i] = 0;
	}
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(adj[i][j] && !visited[j] && (dist[i] + adj[i][j] < dist[j]))
			{
				dist[j] = dist[i] + adj[i][j];
			}
		
		}
		visited[i] = true;
	}
	cout<<"\n================ Minimum Distances Needed From Pizza Parlour to Particular Customer city============== ";
	for(int i=1;i<v;i++)
	{
		cout<<"\nDistance from Pizza Parlour  "<<city[0]<<" TO "<<city[i]<<" ---> "<<dist[i]<<endl;
	}

}
int main()
{
	PPS p1;
	int ch;
	do
	{
		cout<<"\n=====================================MENU===========================\n";
		cout<<"\n1.Create Graph\n2.Display Matrix\n3.Display SingleSourceShortestPath\n4.Exit\n";
		cout<<"\nEnter your choice :";
		cin>>ch;
		switch(ch)
		{
			case 1 :
			p1.Accept();
			break;
			case 2 :
			p1.DisplayMatrix();
			break;
			case 3 :
			p1.SSSP();
			break;
			case 4 :
			cout<<"\nExiting............\n";
		}
	}while(ch != 4);
return 0;
}
