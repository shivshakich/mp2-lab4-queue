#pragma once

static const int MAXSIZE = 10000;

template <class T>
class TQueue {
	T* pMem;					// ��������� �� ������ �������
	size_t size;				// ������������ ���-�� ��������� � �������
	int count;					// �������������� ���-�� ��������� � �������
	int start, finish;			// ������ �������� ������� � ���������� ��������� � �������
public:
	TQueue(int _size);						// �����������
	TQueue(const TQueue& tq);				// ����������� �����������
	~TQueue();								// ����������

	TQueue& operator=(const TQueue& tq);	// �������� �����������

	int IsEmpty();							// �������� �� �������
	int IsFull();							// �������� �� �������������

	void Push(const T& val);				// �������� ������� � �������
	T Pop();								// ������� ������� � �������
	T Front() const;						// �������� ������ ������� � �������
	T Back() const;							// �������� ��������� ������� � �������

	void Clear(void);						// �������� �������

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