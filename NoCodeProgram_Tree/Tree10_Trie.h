#pragma once

//https://www.youtube.com/watch?v=WooOuXIiRjE&list=PLDV-cCQnUlIaTA41swrZwgH4mX7iPxLH4&index=11

// Trie (검색 단어 추천 알고리즘으로 자주 사용됨)
// 영어 검색을 기준으로 해보자

void TrieTest();

void Tree10_Trie()
{
	TrieTest();
}

#include<iostream>
#include<map>

// 2바이트인 u_short 형 value 사용
// map을 사용하면 간편
class TrieNode
{
public:
	using ushort = unsigned short;
	using map_iter = std::map<ushort, TrieNode*>::iterator;
	using map_const_iter = std::map<ushort, TrieNode*>::const_iterator;
	// key 값인 char 는 a-z 까지의 key에 대응
	// value 는 다음 노드에 해당하는 포인터
	std::map<ushort, TrieNode*> m_map;

	// 자신이 저장할 value
	ushort m_value;
	// 단어가 현재 노드로 완성되는 경우 true
	// Trie class(외부 클래스)에서 단어를 regist 시 마지막 character에서 활성화 됨
	bool m_wordEnd;
public:
	TrieNode() :m_value(USHRT_MAX), m_wordEnd(false) {}
	TrieNode(int _value) :m_value(_value), m_wordEnd(false) {}
public:
	// 해당 key값에 대해 이미 노드가 이미 존재하는지
	bool IsRegisterd(ushort _key) const
	{
		auto _result = m_map.find(_key);
		if (_result == m_map.end())
			return false;
		return true;
	}
	// 자식 노드가 존재한다면 true
	bool IsRegisterd_Any() const
	{
		if (m_map.size() == 0)
			return false;
		return true;
	}
	// 자식 노드가 없다면
	bool IsLeaf() const
	{
		return (!IsRegisterd_Any());
	}
	// 단어가 현재 노드로 완성되는 경우
	bool IsWordEnd()
	{
		return m_wordEnd;
	}
	void SetValue(ushort _value)
	{
		m_value = _value;
	}

	// 해당 key값에 대한 child를 생성 및 map 등록
	void AddChild(ushort _key)
	{
		if (IsRegisterd(_key))
		{	// 해당 key값에 대한 정보가 있을 경우 (자식이 이미 존재하는 경우)
			return;	// 추가 작업 필요 없음
		}

		// 해당 Key값에 대한 child 생성 및 set
		m_map[_key] = new TrieNode(_key);		
	}
	TrieNode* GetChild(ushort _key)
	{
		if (IsRegisterd(_key))
			return m_map[_key];
		return nullptr;
	}
};



// ba__ 으로 검색(find)시 _은 모든 문자에 대응되도록 짤 것
// string 도 wstring 으로 해야되는데...
class Trie
{
public:
	TrieNode* head;	// 검색 시작 헤드
public:
	Trie() :head(new TrieNode()) {	}
	~Trie()
	{
		Clear(head);
	}
public:
	// 단어 등록
	void Regist(std::string word)
	{
		if (word.length() == 0)
			return;
		Regist_Recurr(head, word);
	}
	// word 가 등록되어 있는지 판별
	bool Find(std::string word)
	{
		if (word.length() == 0)
		{
			std::cout << "검색 단어 없음" << std::endl << std::endl;
			return false;
		}

		bool _isFound = false;
		_isFound = Find_Recurr(head, word);
		return _isFound;
	}
private:
	void Regist_Recurr(TrieNode* _node, std::string _word)
	{
		// _word의 첫 char를 _node 에 등록
		TrieNode::ushort _key = static_cast<TrieNode::ushort>(_word[0]);
		if (_key == '_')	// 공백으로 강제 대체 (검색 알고리즘에 사용할 놈이라 제회함)
			_key = ' ';
		_node->AddChild(_key);

		// 다음 recurr 호출
		std::string _newOne = _word.substr(1);
		if (_newOne.length() == 0)
		{	// recurr 탈출 조건		
			// 단어의 마지막을 표시
			_node->m_wordEnd = true;
			return;
		}
		Regist_Recurr(_node->GetChild(_key), _newOne);
	}

	// 모든 단어를 대체 가능한 _
	bool Find_Recurr(TrieNode* _node, std::string _word)
	{
		// recurr 탈출 조건
		// 앞에서 컷당하면 여까지 못옴
		if (_word.length() == 0)
		{
			return true;
		}


		// 키 검색
		TrieNode::ushort _key = static_cast<TrieNode::ushort>(_word[0]);
		//bool _flag = false;
		std::string nextWord = _word.substr(1);
		if (_key == '_')
		{
			// 만약 이번 character가 마지막 검색 character인 경우(nextWord 의 length 가 0인 경우에는)
			if (nextWord.length() == 0)
			{
				// 이번 character 로 단어가 완성 될 수 있는 경우 true
				// 단어가 완성 되지 않는다면 false				
				return _node->IsWordEnd();
			}

			// 현재 노드에서 한개라도 등록된 자식이 있으면 검색 가능한 것
			if (_node->IsRegisterd_Any())
			{	
				// 다음 단어(_key)는 _node의 모든 자식에 대해 for 돌아야 함			
				for (TrieNode::map_const_iter it = _node->m_map.begin()
					; it != _node->m_map.end(); it++)
				{
					// _node의 key(first)에대한 자식을 가져오고
					auto child = _node->GetChild(it->first);
					// 해당 자식에 대해 다시 recurr
					auto _result = Find_Recurr(child, nextWord);
					if (_result)
						return true;
				}	// 한개라도 성공하면 true // 한개도 없으면 false				
				return false;
			}
			else
			{	// 자식이 없는 경우
				// 더 검색해야 한다면 (word 의 길이가 1이상인 경우) 검색 실패
				if (_word.length() > 0)
					return false;
				return true;
			}
		}
		else
		{	// _key 값에 대한 검색
			if (_node->IsRegisterd(_key))
			{
				return Find_Recurr(_node->m_map[_key], nextWord);
			}
			else
				return false;
		}
	}

	void Clear(TrieNode* _node)
	{
		if (_node->IsLeaf())
		{	// 마지막 노드일 경우에
			// 자신의 정보를 해제하고 recurr 탈출
			delete _node;
			return;
		}

		// 자식 노드가 있는 경우
		// _node 에서 m_map 을 순회하면서 모든 노드를 clear
		for (TrieNode::map_iter it = _node->m_map.begin();
			it != _node->m_map.end(); it++)
		{
			auto _child_node = it->second;
			Clear(_child_node);
		}
	}
};

static void TrieTest()
{
	// baby ball tree trie 등록

	Trie myTrie;
	myTrie.Regist("baby");
	myTrie.Regist("ball");
	myTrie.Regist("tree");
	myTrie.Regist("trie");

	bool isHave = false;

	isHave = myTrie.Find("baby");
	std::cout << "baby : " << (isHave ? "success" : "fail") << std::endl;
	isHave = myTrie.Find("ball");
	std::cout << "ball : " << (isHave ? "success" : "fail") << std::endl;
	isHave = myTrie.Find("tree");
	std::cout << "tree : " << (isHave ? "success" : "fail") << std::endl;
	isHave = myTrie.Find("trie");
	std::cout << "trie : " << (isHave ? "success" : "fail") << std::endl;
	isHave = myTrie.Find("ballet");
	std::cout << "ballet : " << (isHave ? "success" : "fail") << std::endl;

	std::cout << "ballet추가..." << std::endl;
	myTrie.Regist("ballet");
	isHave = myTrie.Find("ballet");
	std::cout << "ballet : " << (isHave ? "success" : "fail") << std::endl;

	isHave = myTrie.Find("balle_");
	std::cout << "balle_ : " << (isHave ? "success" : "fail") << std::endl;

	isHave = myTrie.Find("ba__");
	std::cout << "ba__ : " << (isHave ? "success" : "fail") << std::endl;

	isHave = myTrie.Find("ba__e_");
	std::cout << "ba__e_ : " << (isHave ? "success" : "fail") << std::endl;
	isHave = myTrie.Find("ba_____");	// _ 5개
	std::cout << "ba_____ : " << (isHave ? "success" : "fail") << std::endl;
	

	isHave = myTrie.Find("_");	
	std::cout << "_ : " << (isHave ? "success" : "fail") << std::endl;
	isHave = myTrie.Find("____");	// _ 4개 (4글자)
	std::cout << "____ : " << (isHave ? "success" : "fail") << std::endl;
}