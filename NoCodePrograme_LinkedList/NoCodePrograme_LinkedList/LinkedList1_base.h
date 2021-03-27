#pragma once

#include<iostream>
#include<cassert>
#define DELETED 0x0008123
#define DELETED_REF 0xdddddddd

// 1: nullptr �� ��� (�Ҵ����� �ʾҰų� nullptr)
// 2: �Ҵ� �� delete �� ��� (0x0008123)
// 3: delete�� �����͸� �����ϴ� �������� ��� (3�� �����͸� ����(*)�ϸ� 0xdddddddd)

#define IS_NULL(ptr) \
(\
((ptr) == nullptr) || \
((ptr) == reinterpret_cast<void*>(DELETED)) || \
(( *( reinterpret_cast<unsigned int*>(ptr) )) == (DELETED_REF))\
)\
? true : false

#define IS_NULL_CONST(ptr,non_const_type) \
(\
((ptr) == nullptr) || \
((ptr) == reinterpret_cast<void*>(DELETED)) || \
(( *( reinterpret_cast<unsigned int*>(  const_cast<non_const_type> (ptr) ) )) == (DELETED_REF))\
)\
? true : false

using std::cout;
using std::endl;

template<typename T>
struct ListNode
{
public:
	ListNode* next;
	T value;
public:
	ListNode() :next(nullptr), value(T()) {}
	ListNode(T _value) : next(nullptr), value(_value)
	{}	

	template<typename T>
	friend std::ostream& operator<<(std::ostream& os, const ListNode<T>& _node);
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const ListNode<T>& _node)
{
	os << _node.value;
	return os;
}

void PrintAll(ListNode<int>* _head)
{
	auto curr = _head;
	while (!IS_NULL(curr))
	{
		cout << *curr << ' ';
		curr = curr->next;
	}
	cout << endl;
}

template<typename T>
class LinkedList
{
public:
	ListNode<T>* head;
	size_t size;
public:
	LinkedList() : head(nullptr), size(0) {}
	~LinkedList() { FreeAll(); }
public:
	/// <summary>
	/// ��� ����� value�� ���
	/// </summary>
	void Print();
	/// <summary>
	/// value �� ��带 Ž��
	/// </summary>
	/// <param name="value"></param>
	/// <returns> value ���� ������ ��尡 ���� ��� nullptr�� ��ȯ </returns>
	ListNode<T>* FindNode(T value);
	void AddFront(ListNode<T>* _newNode);
	void AddBack(ListNode<T>* _newNode);
	void AddBefroe(ListNode<T>* _flagNode, T value);
	void AddAfter(ListNode<T>* _flagNode, T value);
	/// <summary>
	///	_beforeNode�� ������ �����
	/// </summary>	
	void DeleteAfter(ListNode<T>* _beforeNode);
	void Delete(ListNode<T>* _deleteNode);
	/// <summary>
	/// ���� ��忡 �Ҵ�� object�� ��� delete
	/// </summary>
	void FreeAll();
};


template<typename T>
void LinkedList<T>::Print()
{

	if (size == 0)
	{
		cout << "����Ʈ �������" << endl;
		return;
	}

	ListNode<T>* curr = head;
	cout << "List ���..." << endl << ' ';
	while (!IS_NULL(curr))
	{
		cout << *curr << ' ';
		curr = curr->next;
	}
	cout << endl;
}

template<typename T>
void LinkedList<T>::AddFront(ListNode<T>* _newNode)
{
	// ����Ʈ�� ����ִ� ���
	if (size == 0)
	{
		head = _newNode;
	}
	else
	{
		// ���� ��带 newNode �ڿ� ����
		// ���ο� ��带 head�� ����
		_newNode->next = head;
		head = _newNode;
	}
	++size;
}

template<typename T>
void LinkedList<T>::AddBack(ListNode<T>* _newNode)
{
	// ����Ʈ�� ����ִ� ���
	if (size == 0)
	{
		head = _newNode;
	}
	else
	{
		// ���� ������ ��带 ã��(next�� nullptr�� ���)
		ListNode<T>* curr = head;
		while (!IS_NULL(curr->next))
		{
			curr = curr->next;
		}
		// ������ ��忡 newNode����
		curr->next = _newNode;
	}
	++size;
}

template<typename T>
void LinkedList<T>::AddBefroe(ListNode<T>* _flagNode, T value)
{
	if (size == 0)
		return;

	if (head == _flagNode)
	{
		ListNode<T>* _newNode = new ListNode<T>(value);
		_newNode->next = head;
		head = _newNode;
		++size;
		return;
	}
	ListNode<T>* before = head;
	ListNode<T>* curr = head->next;
	while (!IS_NULL(curr))
	{
		if (_flagNode == curr)
		{
			ListNode<T>* _newNode = new ListNode<T>(value);
			before->next = _newNode;
			_newNode->next = curr;
			++size;
			return;
		}
		before = curr;
		curr = curr->next;
	}
}

template<typename T>
void LinkedList<T>::AddAfter(ListNode<T>* _flagNode, T value)
{
	ListNode<T>* curr = head;
	while (!IS_NULL(curr->next))
	{
		if (_flagNode == curr)
		{
			ListNode<T>* _origin_next = curr->next;
			ListNode<T>* _new = new ListNode<T>(value);
			curr->next = _new;
			_new->next = _origin_next;
			++size;
			return;
		}
		curr = curr->next;
	}
}

template<typename T>
void LinkedList<T>::DeleteAfter(ListNode<T>* _beforeNode)
{
	if (size == 0)
		return;

	ListNode<T>* curr = head;
	while (!IS_NULL(curr->next))
	{
		if (curr == _beforeNode)
		{
			ListNode<T>* _deleteNode = curr->next;
			curr->next = _deleteNode->next;
			delete _deleteNode;
			--size;
			return;
		}
		curr = curr->next;
	}
}
template<typename T>
void LinkedList<T>::Delete(ListNode<T>* _deleteNode)
{
	if (size == 0)
		return;

	// ���� ��尡  head�� ���
	if (_deleteNode == head)
	{
		head = _deleteNode->next;
		delete _deleteNode;
		--size;
		return;
	}

	ListNode<T>* before = head;
	ListNode<T>* curr = head->next;
	while (!IS_NULL(curr->next))
	{
		if (_deleteNode == curr)
		{
			before->next = curr->next;
			delete _deleteNode;
			--size;
			return;
		}
		before = curr;
		curr = curr->next;
	}
}

template<typename T>
void LinkedList<T>::FreeAll()
{
	if (size == 0)
		return;

	ListNode<T>* deleteNode = nullptr;
	ListNode<T>* curr = head;
	while (!IS_NULL(curr->next))
	{
		deleteNode = curr;
		curr = curr->next;
		delete deleteNode;
		--size;
	}

	head = nullptr;
}

template<typename T>
ListNode<T>* LinkedList<T>::FindNode(T value)
{
	ListNode<T>* curr = head;
	while (!IS_NULL(curr))
	{
		if (curr->value == value)
			return curr;
		curr = curr->next;
	}

	return nullptr;
}


void BaseTest()
{
	LinkedList<int> list;
	list.AddFront(new ListNode<int>(1));
	list.AddFront(new ListNode<int>(2));
	list.Print();

	LinkedList<int> list2;
	list2.AddBack(new ListNode<int>(10));
	list2.AddBack(new ListNode<int>(12));
	list2.AddFront(new ListNode<int>(1));
	list2.AddBack(new ListNode<int>(100));
	list2.AddBack(new ListNode<int>(120));
	list2.Print();

	/*cout << "list2 size : " << list2.size << endl;
	list2.FreeAll();
	cout << "�Ҵ� ���� �� : " << list2.size << endl;*/

	auto a = list.FindNode(1);
	cout << *a << endl;
	auto b = list2.FindNode(-1);
	cout << b << endl;

	cout << endl << "value 99�� value 12�� ��� �ڿ� ����" << endl;
	list2.AddAfter(list2.FindNode(12), 99);
	list2.Print();

	cout << endl << "value 89�� value 99�� ��� �տ� ����" << endl;
	list2.AddBefroe(list2.FindNode(99), 89);
	list2.Print();
	cout << endl << "value 0�� value 1�� ��� �տ� ����" << endl;
	list2.AddBefroe(list2.FindNode(1), 0);
	list2.Print();

	// ���� ���� ��� �����
	list2.Delete(list2.FindNode(0));
	list2.Print();
	// �߰� ��� �����
	list2.Delete(list2.FindNode(89));
	list2.Print();
	// ���� ���� ��� �����
	list2.Delete(list2.FindNode(120));
	list2.Print();

	cout << "12�� ��� �����" << endl;
	list2.DeleteAfter(list2.FindNode(12));
	list2.Print();
	list2.DeleteAfter(list2.FindNode(12));
	list2.Print();
	cout << list2.size << endl;
}