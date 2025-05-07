#include<iostream>
#include<string>
using namespace std;

int n;

class OBST {
    int p[10], q[10];
    int w[10][10], c[10][10], r[10][10];
    string key[10];

public:
    void AcceptItems();
    void Build();
    void PrintTree(int i, int j);       // wrapper with header
    void PrintTreeHelper(int i, int j); // helper to recurse and print
} b1;

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
        for (int j = 0; j <= n; j++) 
        {
            cout << w[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nCost Matrix (c):\n";
    for (int i = 0; i <= n; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            cout << c[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nRoot Matrix (r):\n";
    for (int i = 0; i <= n; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            cout << r[i][j] << "\t";
        }
        cout << endl;
    }
}

void OBST::PrintTree(int i, int j) {
    cout << "\nPreorder Traversal in Table Format:\n";
    cout << "Node\t\tLeft Child\tRight Child\n";
    cout << "-------------------------------------------\n";
    PrintTreeHelper(i, j);
}

void OBST::PrintTreeHelper(int i, int j) {
    if (i == j)
        return;

    int root = r[i][j];
    if (root == 0)
        return;

    string leftChild, rightChild;

    if (i == root - 1)
        leftChild = "D" + to_string(i);
    else if (r[i][root - 1] != 0)
        leftChild = key[r[i][root - 1]];
    else
        leftChild = "D" + to_string(root - 1);

    if (root == j)
        rightChild = "D" + to_string(j);
    else if (r[root][j] != 0)
        rightChild = key[r[root][j]];
    else
        rightChild = "D" + to_string(j);

    cout << key[root] << "\t\t" << leftChild << "\t\t" << rightChild << endl;

    PrintTreeHelper(i, root - 1);
    PrintTreeHelper(root, j);
}

int main() {
    b1.AcceptItems();
    b1.Build();
    b1.PrintTree(0, n);
    return 0;
}
