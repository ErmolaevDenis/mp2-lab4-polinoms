#pragma once

#include <iostream>

using namespace std;

template <class T>
struct Node
{
    T data;
    Node* next;
    Node() : next(nullptr) {};
    Node(T val) : data(val), next(nullptr) {};
};

template <class T>
class List
{
private:
    Node<T>* head;
public:
    List() : head(new Node<T>) {}
    List(const List& other) : head(new Node<T>)
    {
        Node<T>* p = other.head->next;
        while (p)
        {
            this->sortInsert(p->data);
            p = p->next;
        }
    }
    List& operator=(const List& other)
    {
        if (this == &other)
            return *this;
        this->~List();
        head = new Node<T>;
        Node<T>* p = other.head->next;
        while (p)
        {
            this->sortInsert(p->data);
            p = p->next;
        }
        return *this;
    }
    bool isEmpty() { return head->next == NULL; }
    Node<T>* getFirst() { return head->next; }
    void sortInsert(const T& val)
    {
        {
            Node<T>* elem = new Node<T>(val);
            Node<T>* p = head;
            if (isEmpty())
            {
                p->next = elem;
                p = elem;
                return;
            }
            Node<T>* p_next = head->next;
            while (p_next && elem->data < p_next->data)
            {
                p = p->next;
                p_next = p_next->next;
            }
            elem->next = p_next;
            p->next = elem;
        }
    }
    ~List()
    {
        Node<T>* p = head;
        while (p->next)
        {
            Node<T>* nextNode = p->next;
            delete p;
            p = nextNode;
        }
        delete p;
    }
};