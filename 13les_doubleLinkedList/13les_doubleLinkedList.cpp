#include <iostream>
using namespace std;

template<typename T>
class List {
	struct Node {
		Node* prev;
		T value;
		Node* next;
		Node():prev(nullptr),value{}, next(nullptr) {}
		Node(Node* p,T v,Node* n):prev(p),value(v),next(n){}
	};
	Node* head;
	Node* tail;
public:
	List():head(nullptr),tail(nullptr){}

	List(const List& other) :head(nullptr), tail(nullptr) {
		Node* current = other.head;

		while (current!=nullptr)
		{
			addToTail(current->value);
			current = current->next;
		}
	}

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
		Node* newNode = new Node(tail, val, nullptr);

		if (isEmpty())
			head = tail = newNode;

		else
		{
			tail->next = newNode;
			tail = newNode;
		}

		//for (Node* i=head;i!=nullptr;i=i->next)
		//{
		//	cout << i->value << " ";
		//}
	}


void deleteFromHead() {
	if (isEmpty())
		return;

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

	int getCount() {
		int count = 0;
		for (Node* i = head; i !=nullptr; i=i->next)
		{
			count++;
		}
		return count;
	}

	void addByIndex(int index,T value) {
		if (index == 0)
			addToHead(value);

		else if (index == getCount())
			addToTail(value);

		else if (index > getCount())
			return;

		else if (index < 0)
			return;
		
		else
		{
			Node* current = head;
			for (int i = 0; i < index; i++)
			{
				current = current->next;
			}
			Node* newNode = new Node(current->prev, value, current);
			current->prev->next = newNode;
			current->prev = newNode;
		}
	}

	void deleteByIndex(int index) {
		if (index == 0)
			deleteFromHead();

		else if (index == getCount() - 1)
			deleteFromTail();

		else if (index > getCount() - 1)
			return;

		else if (index < 0)
			return;

		else
		{
			Node* current = head;
			for (int i = 0; i < index; i++)
			{
				current = current->next;
			}
			current->prev->next = current->next;
			current->next->prev = current->prev;

			delete current;
		}
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
public:
	struct Vagon {
		int vagonNum;
		int seatsAmount;
		int passengersAmount;
		Vagon() :vagonNum(0), seatsAmount(0), passengersAmount(0) {}
		Vagon(int vn, int sa, int pa) :vagonNum(vn), seatsAmount(sa), passengersAmount(pa) {}


		friend ostream& operator<<(ostream& out, const Vagon& v) {
			out << "vagon: " << v.vagonNum << "/seats: " << v.seatsAmount << "/passengers: " << v.passengersAmount << endl;
			return out;
		}
	};
private:
	string model;
	int countVagons;
	List<Vagon> vagons;
public:
	Train():model("none"),countVagons(0) {}
	Train(string m,int c):model(m),countVagons(0){}
	
	void addVagonStart(Vagon v) {
		vagons.addToHead(v);
		countVagons++;
	}

	void addVagonEnd(Vagon v) {
		vagons.addToTail(v);
		countVagons++;
	}

	void deleteTrainHead() {
		vagons.deleteFromHead();
		countVagons--;
	}
	void deleteTrainTail() {
		vagons.deleteFromTail();
		countVagons--;
	}

	void show() {
		vagons.print();
	}
	Train(const Train& other) 
		:model(other.model), countVagons(other.countVagons), vagons(other.vagons){ }
	
	void addVagonByIndex(int index, Vagon value) {
		vagons.addByIndex(index, value);
		countVagons++;
	}
	void deleteVagonByIndex(int index) {
		vagons.deleteByIndex(index);
		countVagons--;
	}

};


int main()
{
	Train::Vagon v1(228,90,80);
	Train::Vagon v2(300,90,79);
	Train::Vagon v3(228,100,4);
	Train t;
	t.addVagonStart(v1);
	t.addVagonStart(v2);
	t.addVagonEnd(v3);
	Train t2 = t;
	//t.show();
	//t2.show();

	//t2.deleteTrainTail();
	//t2.show();
	//t2.deleteTrainHead();
	//t2.show();
	//t2.deleteTrainHead();
	//t2.show();
	t2.addVagonByIndex(1, v2);
	t2.deleteVagonByIndex(0);
	t2.show();





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


