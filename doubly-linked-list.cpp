#include "doubly-linked-list.h"
#include <iostream>
using namespace std;
DoublyLinkedList::Node::Node(DataType data)
{
    value = data;
    next = nullptr;
    prev = nullptr;

}

DoublyLinkedList::DoublyLinkedList()
{
    size_ = 0;
    head_ = nullptr;
    tail_= nullptr;
}


DoublyLinkedList::~DoublyLinkedList()
{
    Node* currNode = head_;
    while(currNode) {
        currNode = currNode -> next;
        delete head_;
        head_ = currNode;
    }

    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

unsigned int DoublyLinkedList::size() const
{
    return size_;


}

unsigned int DoublyLinkedList::capacity() const
{
    return CAPACITY;

}

bool DoublyLinkedList::empty() const
{
    if (size_ == 0) {
        return true;
    }

    return false;

}

bool DoublyLinkedList::full() const
{
    if (CAPACITY == size_){
        return true;
    }
    return false;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const {
    if(index >= size_ || index < 0) {
        return tail_ -> value;
    }
    Node* newNode = head_;

    for(int i = 0; i < size_; i++) {
        if(i == index) {
            return newNode -> value;
        }
        newNode = newNode -> next;
    }

}

unsigned int DoublyLinkedList::search(DataType value) const
{

    Node* newNode = head_;

    for(int i = 0; i < size_; i++) {
        if(newNode -> value == value)
        {
            return i;
        }

        newNode = newNode -> next;
    }

    return size_;
}

void DoublyLinkedList::print() const
{
    Node *newPtr = head_;

    for (unsigned int i =0; i < size_; i ++){
        newPtr  = newPtr -> next;

        cout << newPtr -> value ;
        cout << ", ";
    }
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
    if(index == size_ - 1)
        return tail_;


    Node* newNode = head_;


    for(int i = 0; i < size_; i++) {
        if(i == index) {
            return newNode;
        }
        newNode = newNode -> next;
    }
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    Node* newNode = new Node(value);
    if(index > size_ || index < 0){
        return false;
    }
    else if (index == 0){
        if (size_ == 0){
            head_ = newNode;
            tail_ = newNode;
            size_++;
            return true;
        }
        else {
            head_ -> prev = newNode;
            newNode->next = head_;
            head_ = newNode;
            size_++;
            return true;
        }
    }
    else if (index == size_ ){
        newNode -> prev = tail_;
        tail_ -> next = newNode;
        tail_ = newNode;
        size_ ++ ;
        return true;
    }
    else {

        Node *newPtr = getNode(index);
        newNode->prev = newPtr->prev;
        newPtr->prev->next = newNode;
        newPtr->prev = newNode;
        newNode->next = newPtr;

        newPtr = NULL;
        size_++;
        return true;
    }
}

bool DoublyLinkedList::insert_front(DataType value)
{
    Node *newNode = new Node(value);
    if(size_ >= CAPACITY){
        return false;
    }
    if(size_ == 0){


        tail_ = newNode;
        head_ = newNode;
        size_ ++;
        return true;
    }
    else {
        head_ -> prev = newNode;
        newNode -> next = head_;
        head_ = newNode;

        size_ ++;
        return true;
    }
}

bool DoublyLinkedList::insert_back(DataType value)
{ if(size_ >= CAPACITY){
        return false;
    }
    if(size_ == 0){
        Node* newNode = new Node(value);

        tail_ = newNode;
        head_ = newNode;
        size_ ++;
        return true;
    }else {
        Node *newNode = new Node(value);

        tail_ -> next = newNode;
        newNode -> prev = tail_;

        tail_ = newNode;

        size_ ++;
        return true;
    }
}

bool DoublyLinkedList::remove(unsigned int index)
{
    Node* newNode;
    if (index >= size_ || !head_ )
    {return false;}
    else if (index == 0){
        if(size_ == 0) {
            return false;
        }else if(size_ == 1) {
            delete head_;
            head_ = nullptr;
            tail_ = nullptr;
            size_--;
            return true;
        }
        else {
            newNode = head_->next;
            newNode -> prev = nullptr;
            delete head_;
            head_ = newNode;
            size_--;
            return true;
        }
    }
    else if (index == size_ - 1){
        newNode = tail_ -> prev ;
        newNode -> next = nullptr;
        delete tail_ ;
        tail_ = newNode ;
        size_ --;
        return true;
    }
    else{
        Node *newPtr = head_;

        for (int i =0; i < size_; i ++){
            newPtr = newPtr -> next;
        }
        newPtr  -> prev = newPtr -> next ;
        newPtr -> next -> prev = newPtr -> prev;
        delete newPtr;
        newPtr = nullptr;
        size_ --;
        return true;
    }
}

bool DoublyLinkedList::remove_front()
{ if (size_ == 0){
        return false;
    }
    else if (size_ == 1){
        head_ = nullptr;
        tail_ = nullptr;

    }
    else {
        head_->next->prev = nullptr;
        head_ = head_->next;

    }
    size_ --;
    return true;

}

bool DoublyLinkedList::remove_back()
{ remove(size_ - 1);
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    if(index >= size_ || index < 0) {
        return false;
    }
    Node *newPtr = head_;

    for (int i =0; i < size_; i++) {
        if (i == index) {
            newPtr-> value = value;
            return true;
        }
        newPtr = newPtr -> next;

    }

}



