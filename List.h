#pragma once
#include <iostream>
struct product {
    int name;
    bool operator<(const product& p) {

        if (this->name < p.name) {
            return true;
        }
        else { return false; }
    }
    bool operator>(const product& p) {

        if (this->name > p.name) {
            return true;
        }
        else { return false; }
    }
    bool operator==(const product& p) {
        if (this->name == p.name) { return true; }
        else return false;
    }
};
struct node
{
    product data;
    node* next;
};
class List {

public:
    node* head, * tail;
public:
    List()
    {
        head = NULL;
        tail = NULL;
    }
    void createnode(product value)
    {
        node* temp = new node;
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
        node* temp = new node;
        temp = head;
        while (temp != NULL)
        {
            std::cout << temp->data.name << "\n";
            temp = temp->next;
        }
    }
    node* get_head() {
        return head;
    }
    void set_head(node* n) {
        head = n;
    }
    int amount()
    {
        int Amount = 0;
        node* temp = new node;
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
        if (pos_of_elem > amount() || n > amount() - pos_of_elem) { return; }
        node* previous = new node;
        node* current = new node;
        node* _next = new node;
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
        node* point = new node;
        point = head;
        while (point != NULL)
        {
            temp.createnode(point->data);
            point = point->next;
        }
        return temp;
    }
    void insert_start(product value)//******************WILL BE INHERITED IN CIRCULAR LIST CLASS***********************
    {
        node* temp = new node;
        temp->data = value;
        temp->next = head;
        head = temp;
    }
    List merge(List object)
    {
        node* point = new node;
        point = head;
        while (point != NULL)
        {
            object.createnode(point->data);
            point = point->next;
        }
        return object;
    }
    void delete_from_n_possition(int n)//******************WILL BE INHERITED IN CIRCULAR LIST CLASS***********************
    {
        if (n > amount()) { return; }
        if (n == 1) { clean(); return; }
        node* previous = new node;
        node* current = new node;
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
    void insert_after_position(int pos, product value)//******************WILL BE INHERITED IN CIRCULAR LIST CLASS***********************
    {
        if (pos > amount()) { return; }
        node* pre = new node;
        node* cur = new node;
        node* temp = new node;
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
        node* point = new node;
        point = head;
        node* point_obj = new node;
        node* obj_head = object.get_head();
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
    void sort_by_increase()//******************WILL BE INHERITED IN CIRCULAR LIST CLASS***********************
    {
        node* current = new node;
        node* index = new node;
        int n = amount();
        if (n == 1) { return; }
        current = head;
        index = current->next;
        if (n == 2 && current->data > index->data) {
            product prod = current->data;
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
                    product prod = current->data;
                    current->data = index->data;
                    index->data = prod;
                }
                current = current->next;
                index = index->next;
            }
        }
    }
    void sort_by_decrease()//******************WILL BE INHERITED IN CIRCULAR LIST CLASS***********************
    {
        node* current = new node;
        node* index = new node;
        int n = amount();
        if (n == 1) { return; }
        current = head;
        index = current->next;
        if (n == 2 && current->data > index->data) {
            product prod = current->data;
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
                    product prod = current->data;
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
        node* temp = new node;
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
    void clean()//******************WILL BE INHERITED IN CIRCULAR LIST CLASS***********************
    {
        int n = amount();
        node* previous = new node;
        node* current = new node;
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