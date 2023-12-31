#pragma once

#include <iostream>

template <class T>
struct TNode {
	T value;			// ��������
	T* pNext;			// ��������� �� ��������� �����
};

template <class T>
class TQueueOnList {
	TNode<T>* pFirst;					// ��������� �� ������ ������� �������
	TNode<T>* pLast;					// ��������� �� ��������� ������� �������
public:
	TQueueOnList();								// ����������� �� ���������
	TQueueOnList(const T& val);					// ����������� �������������� ����
	TQueueOnList(const TQueue<T>& que);			// ����������� �������������� ����
	TQueueOnList(const TQueueOnList& que);		// ����������� �����������
	~TQueueOnList();							// ����������

	bool IsEmpty() const;						// �������� �� �������

};