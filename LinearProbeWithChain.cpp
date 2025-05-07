#include<iostream>
using namespace std;
class SMS
{
    int key[10],n,c[10],loc,pos;
    int prn,percent,rno;
    string name,add,classroom,Div;
    public:
    void DisplayEmpty();
    void CreateTable();
    void AcceptDetails();
    void DisplayDetails();
    void Search();
    void Modify();
    void Delete();
}h[10];
void SMS :: CreateTable()
{
    cout<<"\nEnter no.of records :";
    cin>>n;
    
    for(int i=0;i<10;i++)
    {
        h[i].prn = -1;
        h[i].name="-1";
        h[i].rno=-1;
        h[i].percent=-1;
        h[i].add="-1";
        h[i].classroom="-1";
        h[i].Div="-1";
        c[i] = -2;
    }
}
void SMS :: DisplayEmpty()
{
     cout<<"\nDisplay Empty Table:";
     cout<<"\nLoc\tPRN\tName\tRollno\tPercent\tAddress\tClass\tDivision  chain\n";
     for(int i=0;i<10;i++)
    {
        cout<<"\n"<<i<<" \t "<<h[i].prn<<" \t "<<h[i].name<<" \t "<< h[i].rno<<" \t "<<h[i].percent<<" \t "
        <<h[i].add<<" \t "<< h[i].classroom<<" \t "
        <<h[i].Div<<" \t "<<c[i];
    }
}
void SMS :: AcceptDetails()
{
    for(int i=0;i<n;i++)
    {
	 cout<<"\nEnter prn no. :";
       cin>>key[i];
        loc = key[i] % 10;
        
       
            if(h[loc].prn == -1)
            {
                h[loc].prn = key[i];
                cout<<"\nAccept Remaining Details :";
                cout<<"\nEnter Name :";
                cin>>h[loc].name;
                cout<<"\nEnter Rollno :";
                cin>>h[loc].rno;
                cout<<"\nEnter Percentage :";
                cin>>h[loc].percent;
                cout<<"\nEnter Address :";
                cin>>h[loc].add;
                cout<<"\nEnter Classroom :";
                cin>>h[loc].classroom;
                cout<<"\nEnter Division :";
                cin>>h[loc].Div;
                		
            }
            else
            {
                pos = loc;
                int last = pos;
                while(c[last] != -2)
                		{
                			last = c[last];
                		}
                		int newloc = (loc+1)%10;
                		while(h[newloc].prn != -1 && newloc != loc)
                		{
                			newloc = (newloc + 1)%10;
                		}
                		
                		h[newloc].prn = key[i];
                		cout<<"\nEnter Details :";
                        cout<<"\nEnter Name :";
                        cin>>h[newloc].name;
                        cout<<"\nEnter Rollno :";
                        cin>>h[newloc].rno;
                        cout<<"\nEnter Percentage :";
                        cin>>h[newloc].percent;
                        cout<<"\nEnter Address :";
                        cin>>h[newloc].add;
                        cout<<"\nEnter Classroom :";
                        cin>>h[newloc].classroom;
                        cout<<"\nEnter Division :";
                        cin>>h[newloc].Div;                		
                        c[last] = newloc;
                }
                         
       }
 }
void SMS :: DisplayDetails()
{
     cout<<"\nLoc\tPRN\tName\tRollno\tPercent\tAddress\tClass\tDivision  chain\n";
    for(int i=0;i<10;i++)
    {
        cout<<"\n"<<i<<" \t "<<h[i].prn<<" \t "<<h[i].name<<" \t "<<h[i].rno<<" \t "<<h[i].percent<<" \t "<<h[i].add<<" \t "<<h[i].classroom<<" \t "<<h[i].Div<<"\t"<<c[i];
    }

}
void SMS ::Search()
{
    int pr,flag=0;
    cout<<"\nEnter Prn no that you want to search :";
    cin>>pr;
    loc =pr % 10;
	while (loc != -1) 
	{
		if (h[loc].prn ==pr) 
		{
			cout << "\nRecord Found!\n";
            cout<<"\n"<<loc<<" \t "<<h[loc].prn<<" \t "<<h[loc].name<<" \t "<<h[loc].rno<<" \t "<<h[loc].percent<<" \t "<<h[loc].add<<" \t "<<h[loc].classroom<<" \t "<<h[loc].Div<<"\t"<<c[loc];
			flag = 1;
			break;
		}
		loc = c[loc];  // follow the chain
	}

	if (flag == 0)
		cout << "\nRecord Not Found!";
}


void SMS :: Delete()
{
    int pr1,flag=0;
    cout<<"\nEnter Prn no. that you want to delete : ";
    cin>>pr1;
    loc = pr1 % 10; //loc =1
	while(loc != -2)
	{
		if(h[loc].prn ==pr1 && c[loc] != -1) //h[1].prn = 111 && c[1] = 2
		{
			do 
			{
				pos = c[loc];  // pos = 2  // pos = 3
				h[loc] = h[pos]; 	//h[1] = h[2] all record of h[2] //h[2] = h[3] 
				loc = pos;  //loc = 2 // loc =3
				flag = 1;  
			}while(c[loc]!= -2);  //c[2] = 3 != -1  //c[3] = -1; 
			
			c[loc - 1 ] = -2; 
			
			cout<<"\nRecord is Deleted ";
            c[pos] = -2; 
		h[loc].prn = -1;
            h[loc].name="-1";
            h[loc].rno=-1;
            h[loc].percent=-1;
            h[loc].add="-1";
            h[loc].classroom="-1";
            h[loc].Div="-1";
            
			
		}
		loc = c[loc];

	}
	
	if (flag == 0)
	{
		cout << "\nRecord Not Found!";
	}
}
void SMS :: Modify() 
{
	int pr2, flag = 0;
	cout << "\nEnter PRN of Student You Want To Update: ";
	cin >> pr2;
	loc = pr2 % 10; //loc = 1
	while (loc != -1) 
	{
		if(h[loc].prn ==pr2)
		{
			cout << "\nEnter New Name and Percentage: ";
			cin >> h[loc].name >> h[loc].percent;
			cout << "\nRecord Updated!";
			flag = 1;
			break; 
			
			
		}
		loc = c[loc];
	}
	if (flag == 0)
		cout << "\nRecord Not Found!";
}
int main()
{
    SMS s1;
    int ch;
	do
	{
		cout<<"\n=====================================MENU===================================\n";
		cout<<"\n1.Create Table\n2.Display EmptyTable\n3.Accept Details\n4.Display Hashtable\n5.Search Record\n6.Delete Record\n7.Modify Record\n8.Exit\n";
		cout<<"\nEnter your choice :";
		cin>>ch;
		switch(ch)
		{
			case 1 :
			s1.CreateTable();
			break;
			case 2 :
			s1.DisplayEmpty();
			break;
			case 3 :
			s1.AcceptDetails();
			break;
			case 4 :
			s1.DisplayDetails();
			break;
			case 5 :
			s1.Search();
			break;
			case 6 :
			s1.Delete();
			break;
			case 7 :
			s1.Modify();
			break;
			case 8 :
			cout<<"\nExiting.........\n";
			break;
            default :
            cout<<"\nWrong Choice!!!!!!\n";
		}
	}while(ch != 8);
    
    return 0;
    
}
