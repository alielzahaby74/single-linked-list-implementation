#include <bits/stdc++.h>
 
using namespace std;
 
struct node
{
	int data;
	node *next;
};
class llist
{
public:
	llist()
	{
		head = tail = NULL;
	}
	void push_back(int val)
	{
		node *tmp = new node;
		tmp->data = val;
		tmp->next = NULL;
		if(head ==	NULL)
		{
			head = tail = tmp;
			tmp = NULL;
		}
		else
		{
			tail->next = tmp;
			tail = tmp;
		}
	}
	void push_front(int val)
	{
		node *tmp = new node;
		tmp->data = val;
		tmp->next = head;
		head = tmp;
	}
	void add(int pos, int val)
	{
		node *pre = new node;
		node *curr = new node;
		node *tmp = new node;
		curr = head;
		for(int i = 1; i < pos ; ++i)
		{
			pre = curr;
			curr = curr->next;
		}
		tmp->data = val;
		pre->next = tmp;
		tmp->next = curr;
	}
 
	void pop_front()
	{
		node *tmp = new node;
		tmp = head;
		head = head->next;
		delete tmp;
	}
	void pop_back()
	{
		node *curr = new node;
		node *pre = new node;
		curr = head;
		while(curr->next != NULL)
		{
			pre = curr;
			curr = curr->next;
		}
		tail->next = pre;
		tail = pre;
		pre->next = NULL;
		delete curr;
	}
	void pop(int pos)
	{
		node *curr = new node;
		node *pre = new node;
		curr = head;
		for(int i = 1; i <= pos ; ++i)
		{
			pre = curr;
			curr = curr->next;
		}
		pre->next = curr->next;
	}
	void display()
	{
		node *tmp = new node;
		tmp = head;
		while(tmp != NULL)
		{
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
	}
private:
	node *head, *tail;
};
int main()
{
	llist ll;
	ll.push_back(10);
	ll.push_back(20);
	ll.push_back(30);
	ll.add(2, 10);
	//ll.pop_front();
	//ll.pop_back();
	ll.pop(1);
	ll.display();
	return 0;
}
