#include<iostream>
using namespace std;
int n;
class OBST
{
    int p[10],q[10];
    int w[10][10],c[10][10],r[10][10];
    string key[10];
    public:
    void AcceptItems();
    void Build();
    void Display(int i,int j);
}b1;
void OBST::AcceptItems() {
    cout << "\nEnter number of keys: ";
    cin >> n;

    cout << "Enter keys (strings):\n";
    for (int i = 1; i <= n; i++) {
        cin >> key[i];
    }

    cout << "Enter successful search probabilities (p[1] to p[n]):\n";
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    cout << "Enter unsuccessful search probabilities (q[0] to q[n]):\n";
    for (int i = 0; i <= n; i++) {
        cin >> q[i];
    }
}
void OBST::Build() 
{
	    for (int i = 0; i <= n; i++)
	     {
		     	for(int j=0;j<=n;j++)
		     	{
		     		if(i == j)
		     		{
				  w[i][j] = q[i];
				  c[i][j] = 0;
				  r[i][j] = 0;
			  	}
			  	for (int l = 1; l <= n; l++) 
    				{
					  for (int i = 0; i <= n - l; i++) 
					  {
						int j = i + l;
						w[i][j] = p[j] + q[j] + w[i][j - 1];
						c[i][j] = 9999;
						for (int k = i + 1; k <= j; k++) 
						{
						    int temp = c[i][k - 1] + c[k][j] + w[i][j];
						    if (temp < c[i][j]) 
						    {
							  c[i][j] = temp;
							  r[i][j] = k;
						    }
						}
					  }
				}
			}
		}

    cout << "\nWeight Matrix (w):\n";
    for (int i = 0; i <= n; i++) 
    {
        for (int j = i; j <= n; j++) 
        {
            cout << w[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nCost Matrix (c):\n";
    for (int i = 0; i <= n; i++) 
    {
        for (int j = i; j <= n; j++) 
        {
            cout << c[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nRoot Matrix (r):\n";
    for (int i = 0; i <= n; i++) 
    {
        for (int j = i; j <= n; j++) 
        {
            cout << r[i][j] << "\t";
        }
        cout << endl;
    }
}

 void OBST::Display(int i,int j) 
    {
    
        if (i >= j) 
        {
          // unsuccessful search
            return;
        }
    
        int root = r[i][j]; // r[0][4] = 2
        if (root == 0) 
        {
        	return; 
    	  }
    	  
    	  string left = "NULL";
    	  string right = "NULL";
    	  
	 if(r[i][root-1] != 0)
	 {
	 	left = key[r[i][root-1]-1];
	 }
	 
	 if(r[root][j] != 0)
	 {
	 	right = key[r[root][j]-1];
	 }

  		cout<<"\n"<<key[root-1]<<" \t "<<left<<" \t "<<right;
  		
  		Display(i,root-1);

  		Display(root,j);
    }
int main()
{
	int ch;
	do
	{
		cout<<"\n====================================MENU=================================\n";
		cout<<"\n1.Accept Items\n2.Build OBST\n3.Display OBST\n4.Exit";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1 :
			    b1.AcceptItems();
			    break;
			case 2 :
			    b1.Build();
			    break;
			case 3 :
				cout<<"\nNode\tLC\tRC\n";
				cout<<"------------------------------------------\n";
	    			b1.Display(0,n);
	    			break;
	    		case 4 :
	    			cout<<"\nExiting........\n";
    		}
	}while(ch != 4);


    
    return 0;

}
