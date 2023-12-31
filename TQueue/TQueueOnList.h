#pragma once

#include <iostream>

template <class T>
struct TNode {
	T value;			// значение
	T* pNext;			// указатель на следующее звено
};

template <class T>
class TQueueOnList {
	TNode<T>* pFirst;					// указатель на первый элемент очереди
	TNode<T>* pLast;					// указатель на последний элемент очереди
public:
	TQueueOnList();								// конструктор по умолчанию
	TQueueOnList(const T& val);					// конструктор преобразования типа
	TQueueOnList(const TQueue<T>& que);			// конструктор преобразования типа
	TQueueOnList(const TQueueOnList& que);		// конструктор копирования
	~TQueueOnList();							// деструктор

	bool IsEmpty() const;						// проверка на пустоту

};