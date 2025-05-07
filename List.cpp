#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node *next;
	
	Node(int val)
	{
		data=val;
		next=NULL;
	}
};
class List
{
	Node *head,*tail;
	public:
	
	List()
	{
		head=tail=NULL;
	} 
	
	void push_front(int val)
	{
		Node *newNode = new Node(val);
		if(head == NULL)
		{
			head=tail=newNode;
		}
		else
		{
			newNode->next = head;
			newNode = head;
		}
	}
	void push_back(int val)
	{
		Node *newNode = new Node(val);
		if(head == NULL)
		{
			head=tail=newNode;
		}
		else
		{
			tail->next = newNode;
			newNode = tail;
		}
	}
	void print()
	{
		if(head == NULL)
		{
			cout<<"LIst is empty";
		}
		else
		{
			Node *temp = head;
			while(temp!=NULL)
			{
				cout<<temp->data<<"->";
				temp=temp->next;
			}
			cout<<"NULL"<<endl;
		}
	}
};
int main()
{
	List l;
	l.push_front(10);
	l.push_back(20);
	l.push_back(30);
	l.push_front(40);
	l.print();
	return 0;
}
