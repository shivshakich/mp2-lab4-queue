#pragma once

static const int MAXSIZE = 10000;

template <class T>
class TQueue {
	T* pMem;					// указатель на начало массива
	size_t size;				// максимальное кол-во элементов в массиве
	int count;					// действительное кол-во элементов в очереди
	int start, finish;			// номера индексов первого и последнего элементов в очереди
public:
	TQueue(int _size);						// конструктор
	TQueue(const TQueue& tq);				// конструктор копирования
	~TQueue();								// деструктор

	TQueue& operator=(const TQueue& tq);	// оператор копирования

	int IsEmpty();							// проверка на пустоту
	int IsFull();							// проверка на заполненность

	void Push(const T& val);				// добавить элемент в очередь
	T Pop();								// забрать элемент в очередь
	T Front() const;						// показать первый элемент в очереди
	T Back() const;							// показать последний элемент в очереди

	void Clear(void);						// очистить очередь

	friend std::ostream& operator<<(std::ostream& os, const TQueue& tq);
};

template <class T>
TQueue<T>::TQueue(int _size) {
	if (_size < 1)
		throw "_size < 1";

	pMem = new T[_size];
	size = _size;
	count = 0;
	start = 0, finish = -1;
}

template <class T>
TQueue<T>::TQueue(const TQueue<T>& tq) {
	pMem = new T[tq.size];
	size = tq.size;
	count = tq.count;
	start = tq.start, finish = tq.finish;


}