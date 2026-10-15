#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100

struct PhanSo {
    int tu;
    int mau;

    PhanSo(int t = 0, int m = 1) : tu(t), mau(m) {}

    bool operator==(const PhanSo& other) const {
        return (tu * other.mau) == (other.tu * mau);
    }

    friend ostream& operator<<(ostream& os, const PhanSo& ps) {
        if (ps.mau == 1) os << ps.tu;
        else os << ps.tu << "/" << ps.mau;
        return os;
    }
};

template <class DataType>
class MyList {
private:
    DataType* items;
    int capicity;
    int size;
public:
    MyList();
    MyList(int maxsize);
    ~MyList();
    
    bool isEmpty();
    bool isFull();
    
    void add(DataType value);
    void insert(DataType value, int index);
    
    void removeAt(int index);
    void clear();

    int indexOf(DataType value);
    int lastIndexOf(DataType value);
    
    int getSize();
    
    DataType get(int index);
    
    void display();
};

template <class DataType>
MyList<DataType>::MyList()
{
    capicity = MAX_SIZE;
    items = new DataType[capicity];
    size = 0;
}

template <class DataType>
MyList<DataType>::MyList(int maxsize)
{
    if (maxsize > 0)
        capicity = maxsize;
    else 
        capicity = MAX_SIZE;
    items = new DataType[capicity];
    size = 0;
}

// hàm hủy
template <class DataType>
MyList<DataType>::~MyList()
{
    delete[] items;
}

// hàm empty, full
template <class DataType>
bool MyList<DataType>::isEmpty()
{
    return size == 0;
}

template <class DataType>
bool MyList<DataType>::isFull()
{
    return size == capicity;
}

// hàm add
template <class DataType>
void MyList<DataType>::add(DataType value)
{
    if (!isFull())
    {
        items[size] = value;
        size++;
    }
    else
    {
        cout << "Mang da day roi!" << endl;
    }
}

// hàm insert value ở vị trí index
template <class DataType>
void MyList<DataType>::insert(DataType value, int index)
{
    if (index >= 0 && index <= size && !isFull()) 
    {
        for (int i = size; i > index; i--)
        {
            items[i] = items[i - 1];
        }
        items[index] = value;
        size++;
    }
    else cout << "Sai index!" << endl;
}

// hàm removeAt
template <class DataType>
void MyList<DataType>::removeAt(int index)
{
    if (index >= 0 && index < size && !isEmpty())
    {
        for (int i = index; i < size - 1; i++)
        {
            items[i] = items[i + 1];
        }
        size--;
    }
    else cout << "Sai index!" << endl;
}

// hàm clear
template <class DataType>
void MyList<DataType>::clear()
{
    size = 0;
}

// hàm indexOf
template <class DataType>
int MyList<DataType>::indexOf(DataType value)
{
    for (int i = 0; i < size; i++) {
        if (items[i] == value) {
            return i;
        }
    }
    return -1;
}

// hàm lastIndexOf
template <class DataType>
int MyList<DataType>::lastIndexOf(DataType value) {
    for (int i = size - 1; i >= 0; i--) {
        if (items[i] == value) {
            return i;
        }
    }
    return -1;
}

// hàm getSize
template <class DataType>
int MyList<DataType>::getSize()
{
    return size;
}

// hàm get lấy phần tử tại vị trí index
template <class DataType>
DataType MyList<DataType>::get(int index) {
    if (index >= 0 && index < size && !isEmpty())
    {
        return items[index];
    }
    else
        cout << "Sai index!" << endl;
    return DataType();
}

// hàm display
template<class DataType>
void MyList<DataType>::display()
{
    for (int i = 0; i < size; i++)
    {
        cout << items[i] << " ";
    }
    cout << endl;
}

int main() {
    MyList<int> list(10);
    
    list.add(24);
    list.add(9);
    list.add(36);
    list.add(12);
    list.display();
    list.insert(5, 2);
    list.display();

    MyList<PhanSo> pslist(10);

    pslist.add(PhanSo(39, 6));
    pslist.add(PhanSo(22, 42));
    pslist.add(PhanSo(6, 7));
    pslist.add(PhanSo(36, 67));
    pslist.add(PhanSo(192, 209));
    pslist.display();
    pslist.insert(PhanSo(99, 666), 1);
    pslist.insert(PhanSo(3668, 222), 3);

    pslist.display();

    return 0;
}