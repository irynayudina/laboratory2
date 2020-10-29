#pragma once
#include <iostream>
template <class T>
struct node
{
    T data;
    node<T>* next;
    /*T& operator*() const { return *node; }
    T* operator->() const { return node; }*/
};
template <class T>
class List {

public:
    node<T>* head, * tail;
public:
    List()
    {
        head = NULL;
        tail = NULL;
    }
    void createnode(T value)
    {
        node<T>* temp = new node<T>;
        temp->data = value;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }

    }
    void display()
    {
        node<T>* temp = new node<T>;
        temp = head;
        while (temp != NULL)
        {
            std::cout << temp->data<< "\n";
            temp = temp->next;
        }
    }
    node<T>* get_head() {
        return head;
    }
    void set_head(node<T>* n) {
        head = n;
    }
    int amount()
    {
        int Amount = 0;
        node<T>* temp = new node<T>;
        temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            ++Amount;
        }
        return Amount;
    }
    //required methods
    void moove_by_n_possitions(int pos_of_elem, int n)
    {
        int amnt = amount();
        if (pos_of_elem > amnt || n > amnt - pos_of_elem) { return; }
        node<T>* previous = new node<T>;
        node<T>* current = new node<T>;
        node<T>* _next = new node<T>;
        previous = head;

        for (int i = 1; i < pos_of_elem - 1; i++)
        {
            previous = previous->next;
        }
        current = previous->next;
        _next = current->next;
        for (int i = 0; i < n; i++) {
            previous->next = _next;
            current->next = _next->next;
            _next->next = current;

            previous = previous->next;
            current = previous->next;
            _next = current->next;
        }
    }
    List copy()
    {
        List temp;
        node<T>* point = new node<T>;
        point = head;
        while (point != NULL)
        {
            temp.createnode(point->data);
            point = point->next;
        }
        return temp;
    }
    void insert_start(T value)
    {
        node<T>* temp = new node<T>;
        temp->data = value;
        temp->next = head;
        head = temp;
    }
    List merge(List object)
    {
        node<T>* point = new node<T>;
        point = head;
        while (point != NULL)
        {
            object.createnode(point->data);
            point = point->next;
        }
        return object;
    }
    void delete_from_n_possition(int n)
    {
        if (n > amount()) { return; }
        if (n == 1) { clean(); return; }
        node<T>* previous = new node<T>;
        node<T>* current = new node<T>;
        current = head;

        while (n > 1)
        {
            previous = current;
            current = current->next;
            --n;
        }
        previous->next = current->next;
        delete current;
    }
    void insert_after_position(int pos, T value)
    {
        if (pos > amount()) { return; }
        node<T>* pre = new node<T>;
        node<T>* cur = new node<T>;
        node<T>* temp = new node<T>;
        cur = head;

        for (int i = 1; i < pos; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        temp->data = value;
        pre->next = temp;
        temp->next = cur;
    }
    List list_of_same(List object) {
        List result;
        node<T>* point = new node<T>;
        point = head;
        node<T>* point_obj = new node<T>;
        node<T>* obj_head = object.get_head();
        do
        {
            point_obj = obj_head;
            do
            {

                if (point == point_obj || point->data == point_obj->data)
                {
                    result.createnode(point->data);
                }
                point_obj = point_obj->next;

            } while (point_obj != NULL);
            point = point->next;
        } while (point != NULL);
        return result;
    }
    void sort_by_increase()
    {
        node<T>* current = new node<T>;
        node<T>* index = new node<T>;
        int n = amount();
        if (n == 1) { return; }
        current = head;
        index = current->next;
        if (n == 2 && current->data > index->data) {
            T prod = current->data;
            current->data = index->data;
            index->data = prod;
            return;
        }
        else if (n == 2) { return; }
        int succes = 1;
        while (succes != 0) {
            n = amount();
            while (n > 2) {
                --n;
                succes = 0;
                if (current->data > index->data) {
                    ++succes;
                    T prod = current->data;
                    current->data = index->data;
                    index->data = prod;
                }
                current = current->next;
                index = index->next;
            }
        }
    }
    void sort_by_decrease()
    {
        node<T>* current = new node<T>;
        node<T>* index = new node<T>;
        int n = amount();
        if (n == 1) { return; }
        current = head;
        index = current->next;
        if (n == 2 && current->data > index->data) {
            T prod = current->data;
            current->data = index->data;
            index->data = prod;
            return;
        }
        else if (n == 2) { return; }
        int succes = 1;
        while (succes != 0) {
            n = amount();
            while (n > 2) {
                --n;
                succes = 0;
                if (current->data < index->data) {
                    ++succes;
                    T prod = current->data;
                    current->data = index->data;
                    index->data = prod;
                }
                current = current->next;
                index = index->next;
            }
        }
    }
    void delete_each_n(int n)
    {
        if (n > amount()) { return; }
        if (n == 1) { clean(); return; }
        int count = 1;
        int _amount = 0;
        node<T>* temp = new node<T>;
        temp = head;

        while (temp != NULL)
        {
            temp = temp->next;
            ++_amount;
        }
        for (int i = 0; i < _amount; i++) {
            if (count % n == 0) {
                delete_from_n_possition(count);
            }
            ++count;
        }

    }
    void clean()
    {
        int n = amount();
        node<T>* previous = new node<T>;
        node<T>* current = new node<T>;
        previous = get_head();
        while (n > 1)
        {
            --n;
            current = previous->next;
            delete previous;
            previous = current;

        }
        delete previous;
        set_head(NULL);
    }
};