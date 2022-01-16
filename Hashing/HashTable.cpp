#pragma once
#include "HashTable.h"
#define ll long long int

//copy constructor
template<class t>
hashTable<t>::hashTable(const hashTable& s)
{
    this->size = s.size;
    this->currLoc = -1;
    arr = new t[size];
    for (int i = 0; i < size; i++)
    {
        if (!isFull())
            arr[++currLoc] = s.arr[i];
    }
}
//destructor
template<class t>
hashTable<t>::~hashTable()
{
    if (arr != nullptr)
        delete[] arr;
}
template<class t>
ll hashTable<t>::getSize()
{
    return size;
}
//returns currLoc of arr value and dec pointer
template<class t>
bool hashTable<t>::deleteKey()
{
    bool reSized = false;
    if (isFull())
    {
        this->resize(this->size * 2);
        reSized = true;
    }
    if (this->currLoc <= (this->size / 4))
    {
        this->resize(this->size / 2);
        reSized = true;
    }
    if (!isEmpty())
    {
        currLoc--;
        return reSized;
    }
    else
    {
        currLoc = -1;
        return reSized;
    }
}
//return value at currLoc of arr
template<class t>
t hashTable<t>::currLoc_()
{
    return arr[currLoc];
}
//return true if arr is full
template<class t>
bool hashTable<t>::isFull()
{
    return currLoc == size - 1;
}
//return true if arr is empty
template<class t>
bool hashTable<t>::isEmpty()
{
    return currLoc == -1;
}
template<class t>
//inc pointer and insert value at currLoc of arr
bool hashTable<t>::insert(ll index, t value)
{
    bool reSized = false;
    if (isFull())
    {
        this->resize(this->size * 2);
        reSized = true;
    }
    else
    {
        cout << "this is key value " << value << " hashed to index " << index << endl;
        ++currLoc;
        arr[index] = value;
    }
    return reSized;
}
template<class t>
//print the values inserted in arr till currLoc 
void hashTable<t>::printarr()
{
    cout << "\nTable is::";
    for (ll i = currLoc; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
template<class t>
//manage size
//if 1/4 of arr is empty reduces its size by half
//if arr is full double its size
void hashTable<t>::resize(ll newSize) //here size must be size*size or size/4
{
    if (arr != NULL)
        delete[] arr;
    this->size = newSize;
    this->arr = new t[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
    currLoc = -1;
}

template<class t>
void hashTable<t>::clearTable()
{
    this->currLoc = -1;
}