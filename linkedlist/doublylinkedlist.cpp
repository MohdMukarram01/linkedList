#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* prev;
		Node* next;
		
		~Node(int d){
			this->data=d;
			this->prev=NULL;
			this->next=NULL;
		}
};

void print(Node* &head)
{
	Node* temp=head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void insertathead(Node* &head,int value)
{
	Node* temp=new Node(value);
	temp->next=head;
	head->prev=temp;
	head=temp;
}
void insertatend(Node* &tail,int value)
{
	Node* temp=new Node(value);
	tail->next=temp;
	temp->prev=tail;
	temp=tail;
}
void insertatposition(Node* &tail,Node* &head,int position,int value)
{
	if(position==1)
	{
		insertathead(head,value);
		return;
	}
	
		Node* temp=head;
		int cnt=1;
		while(cnt < position-1)
		{
		  temp=temp->next;
		  cnt++;	
		}
	if(temp->next==NULL)
	{
		insertatend(tail,value);
		return;
	}
		
		Node* newnode=new Node(value);
		newnode->next=temp->next;
		temp->next->prev=newnode;
		temp->next=newnode;
		newnode->prev=temp;
}
void deleteposition(Node* &head,int position)
{
	if(position==1){
		Node* temp=head;
		temp->next->prev=NULL;
		head=temp->next;
		temp->next=NULL;
	}
	else{
		Node* curr=head;
		Node* prev=NULL;
		int cnt=1;
		
		while(cnt < position)
		{
			prev=curr;
			curr=curr->next;
			cnt++;
		}
		prev->next=curr->next;
		curr->next=NULL;
		delete curr;
	}
}


int main(){
	Node* node1=new Node(10);
	Node* head=node1;
	Node* tail=node1;
	print(head);
	insertathead(head,12);
	print(head);
	insertatend(tail,15);
	print(head);
	insertatposition(tail,head,1,11);
	print(head);
	deleteposition(head,2);
	print(head);
}
