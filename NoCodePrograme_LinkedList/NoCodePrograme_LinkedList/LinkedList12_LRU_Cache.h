#pragma once

//https://www.youtube.com/watch?v=HpuIrGiHwTo&list=PLDV-cCQnUlIbV0z51Mwbbe-tdW2JDS-bR&index=13

// Least Recently Used
// ���� �ֱٿ� ������ ���� ��

// key value ���� �´ٰ� ����
// ���̺��� map�� �ְ� ����� ���
// � object �� ���� ������ ������ map �����δ� �� �� ����

// ���� �߰����� �ڷ������� �ʿ���
// array �� �������ϴ� doubly Linkedlist �� ����

#include"LinkedList1_base.h"

// key, value �� �����ϴ� ���
// int, int ����
#pragma region doubly
class DoublyNode
{
public:
	int key;
	int value;
	DoublyNode* prev;
	DoublyNode* next;
public:
	DoublyNode(int _key, int _value) :key(_key), value(_value), prev(nullptr), next(nullptr) {}
public:
	void Link_next(DoublyNode* _next)
	{
		next = _next;
		_next->prev = this;
	}
	void Link_prev(DoublyNode* _prev)
	{
		prev = _prev;
		_prev->next = this;
	}
};

class DoublyLinkedList
{
public:
	DoublyNode* dummy_head;
	DoublyNode* dummy_tail;
	int size;
public:
	DoublyLinkedList() :
		dummy_head(new DoublyNode(INT_MIN, INT_MIN)), dummy_tail(new DoublyNode(INT_MIN, INT_MIN)), size(0)
	{
		dummy_head->Link_next(dummy_tail);
	}
	~DoublyLinkedList()
	{
		Clear();
		delete dummy_head;
		delete dummy_tail;
	}
	bool IsDummyTail(const DoublyNode* _node) const
	{
		if (IS_NULL_CONST(_node, DoublyNode*))
			return false;
		if (_node == dummy_tail)
			return true;
		return false;
	}
public:
	void AddBack(DoublyNode* _node)
	{
		auto lastnode = dummy_tail->prev;
		lastnode->next = _node;
		_node->prev = lastnode;

		_node->next = dummy_tail;
		dummy_tail->prev = _node;

		++size;;
	}

	DoublyNode* Find_byKey(int _key)
	{
		DoublyNode* curr = dummy_head->next;
		while (!IsDummyTail(curr))
		{
			// Ž�� ����
			if (curr->key == _key)
				return curr;
			curr = curr->next;
		}
		return nullptr;
	}

	DoublyNode* Find_byValue(int _value)
	{
		DoublyNode* curr = dummy_head->next;
		while (!IsDummyTail(curr))
		{
			// Ž�� ����
			if (curr->value == _value)
				return curr;
			curr = curr->next;
		}
		return nullptr;
	}
	// ���� ù ��� ����
	// key ����
	int Delete_first()
	{
		if (size == 0)
			return INT_MIN;
				
		auto head = dummy_head->next;
		auto head_next = head->next;
		int ret = head->key;

		dummy_head->Link_next(head_next);
		delete head;
		--size;
		return ret;
	}
	void Delete(int _value)
	{
		auto find = Find_byValue(_value);
		// Ž�� ����
		if (nullptr == find)
			return;

		auto _prev = find->prev;
		auto _next = find->next;

		_prev->Link_next(_next);
		delete find;
		--size;
	}

	void PrintAll() const
	{
		cout << "---Print Doubly Linked List : size(" << size << ")" << endl;

		DoublyNode* curr = dummy_head->next;
		while (!IsDummyTail(curr))
		{
			cout << '[' << curr->key << ':' << curr->value << ']';
			cout << endl;
			curr = curr->next;
		}
	}

	void Clear()
	{
		auto curr = dummy_head->next;
		while (!IsDummyTail(curr))
		{
			auto deletenode = curr;
			curr = curr->next;
			delete deletenode;
			--size;
		}
		dummy_head->Link_next(dummy_tail);
	}
};


void Test_List()
{
	DoublyLinkedList list;

	list.AddBack(new DoublyNode(1, 10));
	list.AddBack(new DoublyNode(2, 20));
	list.AddBack(new DoublyNode(3, 30));

	list.Delete(30);

	list.PrintAll();
}

#pragma endregion

#include<map>

class LRU
{
private:
	int max_size;
	int size;
	std::map<int, int> map;
	DoublyLinkedList list;
public:
	LRU(int _max_size) :
		max_size(_max_size), size(0) {}
public:
	void Put(int _key, int _value)
	{
		// �ʿ��� key�� �˻�
		if (map.end() == map.find(_key))
		{	// ���� ���
			if (size + 1 > max_size)
			{
				int _ret = list.Delete_first();
				map.erase(_ret);
			}
			list.AddBack(new DoublyNode(_key, _value));
			map.insert({ _key, _value });
			++size;
		}
		else
		{	// �̹� �ִ� ���
			MoveToLast(_key);
		}
	}
	int Get(int _key)
	{
		auto value_iter = map.find(_key);
		if (value_iter == map.end())
		{	// ã�� ���� ������
			return INT_MIN;
		}

		// ����� ��� �ֽ�ȭ
		MoveToLast(_key);

		return value_iter->second;
	}

	void TestPrint()
	{
		// �� ���
		cout << endl;
		cout << "--map" << endl;
		for (std::map<int, int>::iterator it = map.begin(); it != map.end(); it++)
		{
			cout << '[' << it->first << ':' << it->second << ']';
			cout << endl;
		}
		cout << endl;

		// list ���
		list.PrintAll();		
	}

private:
	// �̹� ��ϵ� node�� ������ ���
	// list���� ���� �ֱٿ� ����� ��ġ�� �Ű��ִ� �۾�
	void MoveToLast(int _key)
	{
		// map�� list�� �����Ͱ� �׻� ����ȭ �Ǿ�� ��
		auto _find = list.Find_byKey(_key);
		// ���� ���� �缳���ϱ�
		auto _prev = _find->prev;
		auto _next = _find->next;
		_prev->Link_next(_next);
		--list.size;
		// _find�� �� �ڷ� �ֱ�
		list.AddBack(_find);
	}

};


// 1 10	put
// 2 20	put
// 3 30	put
// 1 get
// 4 40 put
// 

void LinkedList12_LRU()
{
	LRU lru(3);

	lru.Put(1, 10);
	lru.Put(2, 20);
	lru.Put(3, 30);
	int _result = lru.Get(1);
	cout << "Get(1) : " << _result << endl;
	lru.Put(4, 40);

	lru.TestPrint();

}