#include "sequential-list.h"
#include <iostream>
using namespace std;

SequentialList::SequentialList(unsigned int cap)
{
    data_ = new DataType [cap];
    capacity_ = cap ;
    size_ = 0 ;

}

SequentialList::~SequentialList()
{
    delete [] data_;
    size_ = 0;
    capacity_ = 0;
}

unsigned int SequentialList::size() const
{
return size_;

}

unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::empty() const
{
    if (size_ == 0) {
        return true;
    }

        return false;

}

bool SequentialList::full() const
{
    if (capacity_ == size_){
        return true;
    }
    return false;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
    if (index > size_ || index < 0 ){
        return data_[size_ ];
    }
    else{
        return data_[index];
    }


}

unsigned int SequentialList::search(DataType val) const
{
    for (unsigned int i=0; i < size_; i++){
        if(data_[i] == val){
            return i;
        }
    }

    return size_;
}

void SequentialList::print() const
{
    for(unsigned int i=0; i < size_; i ++) {
        cout << data_[i];
    }
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    if (index > size_ || size_ == capacity_){
        return false;
    }
    else
    {
    for(unsigned int i= size_; i > index ; i --) {

        data_[i] = data_[i - 1];

    }
    data_[index]= val;
            size_++;
            return true;
        }



}

bool SequentialList::insert_front(DataType val)
{
    return insert(val, 0);

}

bool SequentialList::insert_back(DataType val)
{
    return insert(val, size_);
}

bool SequentialList::remove(unsigned int index) {
    if (index == 0 || index > size_) {
        return false;
    }
    for (int i = index; i < size_; i++) {
        data_[i] = data_[i+1];
    }

    size_--;

    return true;
}
    bool SequentialList::remove_front() {
        if (size_ > 0) {
            for (unsigned int i = 0; i < size_; i++) {
                data_[i] = data_[i + 1];
            }
            size_--;
            return true;

        } else {
            return false;
        }
    }

    bool SequentialList::remove_back() {
        if (size_ > 0) {

            size_--;
            return true;
        }
        return false;
    }

    bool SequentialList::replace(unsigned int index, DataType val) {
        if (index < size_ && index >= 0) {
            data_[index] = val;
            return true;
        } else {
            return false;
        }
    }
