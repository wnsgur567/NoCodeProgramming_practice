#pragma once

//https://www.youtube.com/watch?v=WooOuXIiRjE&list=PLDV-cCQnUlIaTA41swrZwgH4mX7iPxLH4&index=11

// Trie (�˻� �ܾ� ��õ �˰������� ���� ����)
// ���� �˻��� �������� �غ���

void TrieTest();

void Tree10_Trie()
{
	TrieTest();
}

#include<iostream>
#include<map>

// 2����Ʈ�� u_short �� value ���
// map�� ����ϸ� ����
class TrieNode
{
public:
	using ushort = unsigned short;
	using map_iter = std::map<ushort, TrieNode*>::iterator;
	using map_const_iter = std::map<ushort, TrieNode*>::const_iterator;
	// key ���� char �� a-z ������ key�� ����
	// value �� ���� ��忡 �ش��ϴ� ������
	std::map<ushort, TrieNode*> m_map;

	// �ڽ��� ������ value
	ushort m_value;
	// �ܾ ���� ���� �ϼ��Ǵ� ��� true
	// Trie class(�ܺ� Ŭ����)���� �ܾ regist �� ������ character���� Ȱ��ȭ ��
	bool m_wordEnd;
public:
	TrieNode() :m_value(USHRT_MAX), m_wordEnd(false) {}
	TrieNode(int _value) :m_value(_value), m_wordEnd(false) {}
public:
	// �ش� key���� ���� �̹� ��尡 �̹� �����ϴ���
	bool IsRegisterd(ushort _key) const
	{
		auto _result = m_map.find(_key);
		if (_result == m_map.end())
			return false;
		return true;
	}
	// �ڽ� ��尡 �����Ѵٸ� true
	bool IsRegisterd_Any() const
	{
		if (m_map.size() == 0)
			return false;
		return true;
	}
	// �ڽ� ��尡 ���ٸ�
	bool IsLeaf() const
	{
		return (!IsRegisterd_Any());
	}
	// �ܾ ���� ���� �ϼ��Ǵ� ���
	bool IsWordEnd()
	{
		return m_wordEnd;
	}
	void SetValue(ushort _value)
	{
		m_value = _value;
	}

	// �ش� key���� ���� child�� ���� �� map ���
	void AddChild(ushort _key)
	{
		if (IsRegisterd(_key))
		{	// �ش� key���� ���� ������ ���� ��� (�ڽ��� �̹� �����ϴ� ���)
			return;	// �߰� �۾� �ʿ� ����
		}

		// �ش� Key���� ���� child ���� �� set
		m_map[_key] = new TrieNode(_key);		
	}
	TrieNode* GetChild(ushort _key)
	{
		if (IsRegisterd(_key))
			return m_map[_key];
		return nullptr;
	}
};



// ba__ ���� �˻�(find)�� _�� ��� ���ڿ� �����ǵ��� © ��
// string �� wstring ���� �ؾߵǴµ�...
class Trie
{
public:
	TrieNode* head;	// �˻� ���� ���
public:
	Trie() :head(new TrieNode()) {	}
	~Trie()
	{
		Clear(head);
	}
public:
	// �ܾ� ���
	void Regist(std::string word)
	{
		if (word.length() == 0)
			return;
		Regist_Recurr(head, word);
	}
	// word �� ��ϵǾ� �ִ��� �Ǻ�
	bool Find(std::string word)
	{
		if (word.length() == 0)
		{
			std::cout << "�˻� �ܾ� ����" << std::endl << std::endl;
			return false;
		}

		bool _isFound = false;
		_isFound = Find_Recurr(head, word);
		return _isFound;
	}
private:
	void Regist_Recurr(TrieNode* _node, std::string _word)
	{
		// _word�� ù char�� _node �� ���
		TrieNode::ushort _key = static_cast<TrieNode::ushort>(_word[0]);
		if (_key == '_')	// �������� ���� ��ü (�˻� �˰��� ����� ���̶� ��ȸ��)
			_key = ' ';
		_node->AddChild(_key);

		// ���� recurr ȣ��
		std::string _newOne = _word.substr(1);
		if (_newOne.length() == 0)
		{	// recurr Ż�� ����		
			// �ܾ��� �������� ǥ��
			_node->m_wordEnd = true;
			return;
		}
		Regist_Recurr(_node->GetChild(_key), _newOne);
	}

	// ��� �ܾ ��ü ������ _
	bool Find_Recurr(TrieNode* _node, std::string _word)
	{
		// recurr Ż�� ����
		// �տ��� �ƴ��ϸ� ������ ����
		if (_word.length() == 0)
		{
			return true;
		}


		// Ű �˻�
		TrieNode::ushort _key = static_cast<TrieNode::ushort>(_word[0]);
		//bool _flag = false;
		std::string nextWord = _word.substr(1);
		if (_key == '_')
		{
			// ���� �̹� character�� ������ �˻� character�� ���(nextWord �� length �� 0�� ��쿡��)
			if (nextWord.length() == 0)
			{
				// �̹� character �� �ܾ �ϼ� �� �� �ִ� ��� true
				// �ܾ �ϼ� ���� �ʴ´ٸ� false				
				return _node->IsWordEnd();
			}

			// ���� ��忡�� �Ѱ��� ��ϵ� �ڽ��� ������ �˻� ������ ��
			if (_node->IsRegisterd_Any())
			{	
				// ���� �ܾ�(_key)�� _node�� ��� �ڽĿ� ���� for ���ƾ� ��			
				for (TrieNode::map_const_iter it = _node->m_map.begin()
					; it != _node->m_map.end(); it++)
				{
					// _node�� key(first)������ �ڽ��� ��������
					auto child = _node->GetChild(it->first);
					// �ش� �ڽĿ� ���� �ٽ� recurr
					auto _result = Find_Recurr(child, nextWord);
					if (_result)
						return true;
				}	// �Ѱ��� �����ϸ� true // �Ѱ��� ������ false				
				return false;
			}
			else
			{	// �ڽ��� ���� ���
				// �� �˻��ؾ� �Ѵٸ� (word �� ���̰� 1�̻��� ���) �˻� ����
				if (_word.length() > 0)
					return false;
				return true;
			}
		}
		else
		{	// _key ���� ���� �˻�
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
		{	// ������ ����� ��쿡
			// �ڽ��� ������ �����ϰ� recurr Ż��
			delete _node;
			return;
		}

		// �ڽ� ��尡 �ִ� ���
		// _node ���� m_map �� ��ȸ�ϸ鼭 ��� ��带 clear
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
	// baby ball tree trie ���

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

	std::cout << "ballet�߰�..." << std::endl;
	myTrie.Regist("ballet");
	isHave = myTrie.Find("ballet");
	std::cout << "ballet : " << (isHave ? "success" : "fail") << std::endl;

	isHave = myTrie.Find("balle_");
	std::cout << "balle_ : " << (isHave ? "success" : "fail") << std::endl;

	isHave = myTrie.Find("ba__");
	std::cout << "ba__ : " << (isHave ? "success" : "fail") << std::endl;

	isHave = myTrie.Find("ba__e_");
	std::cout << "ba__e_ : " << (isHave ? "success" : "fail") << std::endl;
	isHave = myTrie.Find("ba_____");	// _ 5��
	std::cout << "ba_____ : " << (isHave ? "success" : "fail") << std::endl;
	

	isHave = myTrie.Find("_");	
	std::cout << "_ : " << (isHave ? "success" : "fail") << std::endl;
	isHave = myTrie.Find("____");	// _ 4�� (4����)
	std::cout << "____ : " << (isHave ? "success" : "fail") << std::endl;
}