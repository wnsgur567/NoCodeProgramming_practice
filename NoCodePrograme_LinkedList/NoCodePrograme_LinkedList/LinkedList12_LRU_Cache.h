#pragma once

//https://www.youtube.com/watch?v=HpuIrGiHwTo&list=PLDV-cCQnUlIbV0z51Mwbbe-tdW2JDS-bR&index=13

// Least Recently Used
// 가장 최근에 사용되지 않은 것

// key value 값이 온다고 가정
// 테이블을 map에 넣고 사용할 경우
// 어떤 object 가 가장 오래된 것인지 map 만으로는 알 수 없음

// 따라서 추가적인 자료저장이 필요함
// array 는 부적절하니 doubly Linkedlist 가 좋음

#include"LinkedList1_base.h"

// key, value 를 저장하는 노드
// int, int 기준
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
			// 탐색 성공
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
			// 탐색 성공
			if (curr->value == _value)
				return curr;
			curr = curr->next;
		}
		return nullptr;
	}
	// 가장 첫 노드 삭제
	// key 리턴
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
		// 탐색 실패
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
		// 맵에서 key로 검색
		if (map.end() == map.find(_key))
		{	// 없는 경우
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
		{	// 이미 있는 경우
			MoveToLast(_key);
		}
	}
	int Get(int _key)
	{
		auto value_iter = map.find(_key);
		if (value_iter == map.end())
		{	// 찾는 값이 없으면
			return INT_MIN;
		}

		// 사용한 노드 최신화
		MoveToLast(_key);

		return value_iter->second;
	}

	void TestPrint()
	{
		// 맵 출력
		cout << endl;
		cout << "--map" << endl;
		for (std::map<int, int>::iterator it = map.begin(); it != map.end(); it++)
		{
			cout << '[' << it->first << ':' << it->second << ']';
			cout << endl;
		}
		cout << endl;

		// list 출력
		list.PrintAll();		
	}

private:
	// 이미 등록된 node를 재사용할 경우
	// list에서 가장 최근에 사용한 위치로 옮겨주는 작업
	void MoveToLast(int _key)
	{
		// map과 list는 데이터가 항상 동기화 되어야 함
		auto _find = list.Find_byKey(_key);
		// 기존 연결 재설정하기
		auto _prev = _find->prev;
		auto _next = _find->next;
		_prev->Link_next(_next);
		--list.size;
		// _find를 맨 뒤로 넣기
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