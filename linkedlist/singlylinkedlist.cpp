#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	
	Node(int data){
		this->data=data;
		this->next=NULL;
	}
	
	~Node(){
		int value=this->data;
		
		if(this->next != NULL){
			delete next;
			this->next=NULL;
		}
	}
	
};

//void insertnode(Node* &head,int d)
//{
//	Node* temp=new Node(d);
//    temp->next=head;
//	head=temp;
//}

void insertatTail(Node* &Tail,int d){
	Node* temp=new Node(d);
	Tail->next=temp;
	Tail=temp;
}

void insertatPosition(Node* &head,int position,int v)
{
	Node* temp=head;
	int cnt=1;
	while(cnt<position-1){
		temp=temp->next;
		cnt++;
	}
	
	//create node for d 
	Node* insertlocat=new Node(v);
	insertlocat->next=temp->next;
	temp->next=insertlocat;
}
void insertatend(Node* &head ,int d)
{
	Node* temp=head;
	int cnt=1;
	while(temp->next != NULL){
		temp=temp->next;
		cnt++;
	}
	
	Node* insertlast=new Node(d);
	insertlast->next=NULL;
	temp->next=insertlast;
}

void deletenode(int position,Node* &head)
{
	if(position==1){
		Node* temp=head;
		head=head->next;	
		temp->next=NULL;
		
		//memory free 
		delete temp;
	}
	else{
		Node* curr=head;
		Node* prev=NULL;
		
		int cnt=1;
		
		while(cnt < position){
		  prev=curr;
		  curr=curr->next;
		  cnt++;		
		}
		prev->next=curr->next;
		curr->next=NULL;
		delete curr;
	}
}


void print(Node* &head)
{  
	Node* temp=head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	Node* node1= new Node(10);
	
	Node* head=node1;
	Node* Tail=node1;
	
	insertatTail(Tail,20);

	insertatTail(Tail,30);
	insertatPosition(head,3,40);
	
	insertatend(head,100);
    print(head);
    
    deletenode(3,head);
    print(head);
    
    
	return 0;
}
