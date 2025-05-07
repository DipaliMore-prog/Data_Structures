#include<iostream>
using namespace std;
class SMS
{
    int key[10],n,loc;
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
}h[100];
void SMS :: CreateTable()
{
    cout<<"\nEnter no.of records :";
    cin>>n;
    cout<<"\nEnter prn no. :";
    for(int i=0;i<n;i++)
    {
        cin>>key[i];
    }
    for(int i=0;i<10;i++)
    {
        h[i].prn = -1;
        h[i].name="-1";
        h[i].rno=-1;
        h[i].percent=-1;
        h[i].add="-1";
        h[i].classroom="-1";
        h[i].Div="-1";
    }
}
void SMS :: DisplayEmpty()
{
     cout<<"\nDisplay Empty Table:";
     cout<<"\nLoc\tPRN\tName\tRollno\tPercent\tAddress\tClass\tDivision\n";
    for(int i=0;i<10;i++)
    {
        cout<<"\n"<<i<<" \t "<<h[i].prn<<" \t "<<h[i].name<<" \t "<< h[i].rno<<" \t "<<h[i].percent<<" \t "
        <<h[i].add<<" \t "<< h[i].classroom<<" \t "
        <<h[i].Div;
    }
}
void SMS :: AcceptDetails()
{
    for(int i=0;i<n;i++)
    {
        loc = key[i] % 10;
        while(loc < 10)
        {
            if(h[loc].prn == -1)
            {
                h[loc].prn = key[i];
                cout<<"\nAccept Remaining Details :";
                cin>>h[loc].name>>h[loc].rno>>h[loc].percent>>h[loc].add>>h[loc].classroom>>h[loc].Div;
                break;
            }
            else
            {
                loc++;
                if(loc >= 10)
                {
                    loc = 0;
                }
            }
        }
    }
}
void SMS :: DisplayDetails()
{
    cout<<"\nLoc\tPRN\tName\tRollno\tPercent\tAddress\tClass\tDivision\n";
    for(int i=0;i<10;i++)
    {
        cout<<"\n"<<i<<" \t "<<h[i].prn<<" \t "<<h[i].name<<" \t "<<h[i].rno<<" \t "<<h[i].percent<<" \t "<<h[i].add<<" \t "<<h[i].classroom<<" \t "<<h[i].Div;
    }

}
void SMS ::Search()
{
    int pr,flag=0;
    cout<<"\nEnter Prn no that you want to search :";
    cin>>pr;
    for(int i=0;i<10;i++)
    {
        
              if(h[i].prn == pr)
                {
                    cout<<"\n--------Student Found----------\n";
                    cout<<"\nLoc\tPRN\tName\tRollno\tPercent\tAddress\tClass\tDivision\n";
                    cout<<"\n"<<i<<" \t "<<h[i].prn<<" \t "<<h[i].name<<" \t "<<h[i].rno<<" \t "<<h[i].percent<<" \t "<<h[i].add<<" \t "<<h[i].classroom<<" \t "<<h[i].Div;
                    flag = 1;
                    break;
                }
		  	
            
    }
	    if(flag == 0)
		 {
			cout<<"\nRecord Not Found!!!!";
				     
		 }
}
void SMS ::Delete()
{
    int pr1,flag=0;
    cout<<"\nEnter Prn no. that you want delete : ";
    cin>>pr1;
    for(int i=0;i<10;i++)
    {

              if(h[i].prn == pr1)
                {
                          h[i].prn = -1;
				  h[i].name=-1;
				  h[i].rno=-1;
				  h[i].percent=-1;
				  h[i].add=-1;
				  h[i].classroom=-1;
				  h[i].Div=-1;
				  
                    cout<<"\nLoc\tPRN\tName\tRollno\tPercent\tAddress\tClass\tDivision\n";
                    cout<<"\n"<<i<<" \t "<<h[i].prn<<" \t "<<h[i].name<<" \t "<<h[i].rno<<" \t "<<h[i].percent<<" \t "<<h[i].add<<" \t "<<h[i].classroom<<" \t "<<h[i].Div;
                    flag = 1;
                    break;
                 }
        
    }
    if(flag == 0)
                 {
                 		cout<<"\nRecord Not Found!!!!";
                 
                 }
            
}
void SMS ::Modify()
{
    int pr2,flag = 0;
    cout<<"\nEnter Prn no. that you want to Modify :";
    cin>>pr2;
    for(int i=0;i<10;i++)
    {
              if(h[i].prn == pr2)
                {
                    cout<<"\nEnter New Record :";
                    cin>>h[i].prn>>h[i].name>>h[i].rno>>h[i].percent>>h[i].add>>h[i].classroom>>h[i].Div;
                    cout<<"\n------------------Record Updated---------------\n";
                    cout<<"\nLoc\tPRN\tName\tRollno\tPercent\tAddress\tClass\tDivision\n";
                    cout<<"\n"<<i<<" \t "<<h[i].prn<<" \t "<<h[i].name<<" \t "<<h[i].rno<<" \t "<<h[i].percent<<" \t "<<h[i].add<<" \t "<<h[i].classroom<<" \t "<<h[i].Div;
                    flag = 1;
                    break;
                }
           
        
    }
    if(flag == 0)
	{
		cout<<"\nRecord Not Found!!!!";
		           
	}
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
		}
	}while(ch != 8);
    
    return 0;
    
}
