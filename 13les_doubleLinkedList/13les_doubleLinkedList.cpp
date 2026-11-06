#include <iostream>
using namespace std;

template<typename T>
class List {
	struct Node {
		Node* prev;
		T value;
		Node* next;
		Node():prev(nullptr),value(0),next(nullptr){}
		Node(Node* p,T v,Node* n):prev(p),value(v),next(n){}
	};
	Node* head;
	Node* tail;
public:
	List():head(nullptr),tail(nullptr){}

	bool isEmpty() {
		return head == nullptr;
	}

	void addToHead(T val) {
		Node* newNode = new Node(nullptr, val,head);

		if (isEmpty())
			head = tail = newNode;
		
		else
		{
			head->prev = newNode;
			head = newNode;
		}
	}

	void addToTail(T val) {
	/*	Node* newNode = new Node(tail, val, nullptr);

		if (isEmpty())
			head = tail = newNode;

		else
		{
			tail->next = newNode;
			tail = newNode;
		}*/

		for (Node* i=head;i!=nullptr;i=i->next)
		{
			cout << i->value << " ";
		}
	}


void deleteFromHead() {
	if (isEmpty())
		head = nullptr;

	if (head->next==nullptr)
	{
		delete head;
		head = tail = nullptr;
	}
	else
	{
		head = head->next;
		delete head->prev;
		head->prev = nullptr;
	}
}

	void deleteFromTail() {
		if (isEmpty())
			return;

		if (tail->prev==nullptr)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
	}

	void print()
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->value << " ";
			current = current->next;
		}
		cout << endl;
	}

	void show() {
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->value << " ";
			current = current->next;
		}
		cout << endl;
	}


	Train(const Train& other)//copy
	{
		this->model = other.model;
		this->vagonNum = other.vagonNum;
		if (countVagons > 0)
		{
			vagons = new Vagon[countVagons];

			for (int i = 0; i < countVagons; i++)
				vagons[i] = other.vagons[i];
		}
		else
			vagons = nullptr;
	}

	~List()
	{
		Node* current = nullptr;
		while (head != nullptr)
		{
			current = head;
			head = head->next;
			delete current;
		}
	}
};



class Train
{
	struct Vagon {
		int vagonNum;
		int seatsAmount;
		int passengersAmount;
		Vagon() :vagonNum(0), seatsAmount(0), passengersAmount(0) {}
		Vagon(int vn, int sa, int pa) :vagonNum(vn), seatsAmount(sa), passengersAmount(pa) {}
	};

	string model;
	int countVagons;
	List<Vagon> vagons;
public:
	Train():model("none"),countVagons(0) {}
	Train(string m,int c,Vagon v ):model(m),countVagons(c){}
	
	void addVagon(Vagons v) {
		vagons.addToHead(v);
	}
	void show() {
		vagons.print();
	}
};


int main()
{
	Vagon v1(228,90,80);
	Vagon v1(228,90,80);
	Vagon v1(228,90,80);
	Train t;
	t.show();
	





	/*List<int> l;
	for (int i = 0; i < 10; i++)
	{
		l.addToHead(i);
	}
	l.print();
	l.addToTail(100);
	l.addToTail(200);
	l.addToTail(300);
	l.print();
	l.deleteFromTail();
	l.print();
	l.deleteFromTail();
	l.print();
	l.deleteFromTail();
	l.print();*/

}


