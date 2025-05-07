#include<iostream>
using namespace std;

class MaxHeap 
{
    int key[10], val, loc, parent, count = 0;
	public:
    void Accept();
    void BuildHeap(int m, int val);
    void Insert();
    void DisplayHeap();
} h1;

void MaxHeap::Accept()
{
    int n;
    cout << "\nEnter number of keys to insert initially : ";
    cin >> n;
    cout << "\nEnter Keys:\n";
    for (int i = 1; i <= n; i++) 
    {
        cin >> val;
        count++;
        BuildHeap(count, val);
    }
}

void MaxHeap::BuildHeap(int m, int val) 
{
    key[m] = val;
    loc = m;

    while (loc > 1) 
    {
        parent = loc / 2;
        if (key[parent] < key[loc])
        {
            // Swap
            int temp = key[parent];
            key[parent] = key[loc];
            key[loc] = temp;

            loc = parent;
        } 
        else
        {
            break;
        }
    }
}

void MaxHeap::Insert()
{
    char choice;
    do
    {
        if (count >= 9) 
        {
            cout << "Heap is full. Cannot insert more keys.\n";
            break;
        }

        cout << "\nDo you want to insert a key? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') 
        {
            int newkey;
            cout << "Enter new key to insert: ";
            cin >> newkey;
            count++;
            BuildHeap(count, newkey);
        }

    } while (choice == 'y' || choice == 'Y');
}

void MaxHeap::DisplayHeap()
{
    if (count == 0)
    {
        cout << "\nHeap is empty.\n";
        return;
    }

    cout << "\n----------- Max Heap Tree --------\n";
    for (int i = 1; i <= count; i++) 
    {
        cout << "\t" << key[i];
    }
    cout << "\n";
}

int main() 
{
    int choice;

    do
    {
        cout << "\n================== Menu =================\n";
        cout << "1. Accept Initial Keys\n";
        cout << "2. Insert Keys\n";
        cout << "3. Display Heap\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                h1.Accept();
                break;
            case 2:
                h1.Insert();
                break;
            case 3:
                h1.DisplayHeap();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
