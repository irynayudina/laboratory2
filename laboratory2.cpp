﻿#include <iostream>
#include<string>
using namespace std;
struct product {
    string name;
    bool operator<(const product & p) {
        
        if (this->name[0] < p.name[0]) {
            return true;
        }
        else if (this->name[0] == p.name[0]) {
            for (int i = 0; i < ((this->name.length() < p.name.length()) ? this->name.length() : p.name.length()); i++)
            {
                if (this->name[i] > p.name[i]) { return false; }
            }
            return true;
        }
        else { return false; }
    }
    bool operator>(const product& p) {

        if (this->name[0] > p.name[0]) {
            return true;
        }
        else if (this->name[0] == p.name[0]) {
            for (int i = 0; i < ((this->name.length() < p.name.length()) ? this->name.length() : p.name.length()); i++)
            {
                if (this->name[i] < p.name[i]) { return false; }
            }
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
    node *next;
};
class List {

private:
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
            cout << temp->data.name << "\n";
            temp = temp->next;
        }
    }
    node* get_head() {
        return head;
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
            if (previous->next == NULL) { previous->next = head; }
            previous->next = _next;
            current->next = _next->next;
            _next->next = current;
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
    void insert_start(product value)/////////////same////////////
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
    void delete_from_n_possition(int n)////////////same///////////////////
    {
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
    void insert_after_position(int pos, product value)//same//////////////////////
    {
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
        //node* point = new node;
        //point = head;
        //node* point_obj = new node;
        //node* obj_head = new node;
        //for (int i = 1; i < amount(); i++) {
        //    obj_head = object.get_head();
        //    for (int j = 1; j < object.amount(); j++) {                
        //        if (point == point_obj || point->data == point_obj->data)
        //        {
        //            result.createnode(point->data);
        //        }
        //        point_obj = point_obj->next;
        //    }
        //    point = point->next;
        //}
        //return result;

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
    void sort_by_increase()///////////////////same//////////////////////
    {
        node* current = new node;
        node* index = new node;
        int n = amount();
        int succes = 1;
        current = head;
        index = current->next;
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
                //Compare data of currentand index node.If current's data is greater than the index's data then, swap the data between them.
                //in the if block succes +1;
                current = current->next;
                index = index->next;
            }
        }
    }
    void sort_by_decrease() //////////////saame////////////
    {
        node* current = new node;
        node* index = new node;
        int n = amount();
        int succes = 1;
        current = head;
        index = current->next;
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
                //Compare data of currentand index node.If current's data is less than the index's data then, swap the data between them.
                //in the if block succes +1;
                current = current->next;
                index = index->next;
            }
        }
    }
    void delete_each_n(int n)
    {
        int count = 1;
        int amount = 0;
        node* temp = new node;
        temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            ++amount;
        } 
        for (int i = 0; i < amount; i++) {
            if (count % n == 0) {
                delete_from_n_possition(count);
            }
            ++count;
        }

    }
    void clean()//////same////////////////
    {
        int n = amount();
        node* previous = new node;
        node* current = new node;
        previous = head;
        while (n > 2)
        {
            --n;
            current = previous->next;
            delete previous;
            previous = current;

        }
        head = NULL;
    }
};
class CircularList : List
{
private:
    node * head, * tail;
public:
    CircularList()
    {
        head = NULL;
        tail = NULL;
    }
    void createnode(product value)
    {
        node * temp = new node;
        temp->data = value;
        temp->next = head;
        if (head == NULL)
        {
            head = temp;
            tail = temp;     
            head->next = tail;
            tail->next = head;
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
        if (temp != NULL) {
        do
        {
            cout << temp->data.name << "\n";
            temp = temp->next;
        } while (temp != head);
        }
    }
    node* get_head() {
        return head;
    }
    int amount() {
        int Amount = 0;
        node* temp = new node;
        temp = head;
        do
        {
            temp = temp->next;
            ++Amount;
        } while (temp != head);
        return Amount;
    }
    //required methods
    void moove_by_n_possitions(int pos_of_elem, int n) 
    {
        node * previous = new node;
        node* current = new node;
        node* _next = new node;
        previous = head;
        for (int i = 1;  i < pos_of_elem - 1; i++) 
        {
            previous = previous->next;
        }
        current = previous->next;
        _next = current->next;
        for (int i = 0; i < n; i++) {
            previous->next = _next;
            current->next = _next->next;
            _next->next = current;
        }       
    }
    CircularList copy()
    {
        CircularList temp;
        node* point = new node;
        point = head;
        do
        {
            temp.createnode(point->data);
            point = point->next;
        } while (point != head);
        return temp;
    }
    /*void insert_start(product value)
    {
        node* temp = new node;
        temp->data = value;
        temp->next = head;
        head = temp;
    }*/
    CircularList merge(CircularList object)
    {
        node* point = new node;
        point = head;
        do
        {
            object.createnode(point->data);
            point = point->next;
        } while (point != head);
        return object;
    }
    /*void delete_from_n_possition(int n) 
    {
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
    }*/
    /*void insert_after_position(int pos, product value)
    {
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
    }*/
    CircularList list_of_same(CircularList object) {
        CircularList result;
        //node* point = new node;
        //point = head;
        //node* point_obj = new node;
        //node* obj_head = new node;
        //for (int i = 1; i < amount(); i++) {
        //    obj_head = object.get_head();
        //    for (int j = 1; j < object.amount(); j++) {                
        //        if (point == point_obj || point->data == point_obj->data)
        //        {
        //            result.createnode(point->data);
        //        }
        //        point_obj = point_obj->next;
        //    }
        //    point = point->next;
        //}
        //return result;
        
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
            
            } while (point_obj != obj_head);            
            point = point->next;            
        } while (point != head);
        return result;
    }
    //void sort_by_increase() {
    //    node* current = new node;
    //    node* index = new node;
    //    int n = amount();
    //    int succes = 1;
    //    current = head;
    //    index = current->next;
    //    while (succes != 0) {
    //        n = amount();
    //        while (n > 2) {
    //            --n;
    //            succes = 0;
    //            if (current->data > index->data) {
    //                ++succes;
    //                product prod = current->data;
    //                current->data = index->data;
    //                index->data = prod;
    //            }
    //            //Compare data of currentand index node.If current's data is greater than the index's data then, swap the data between them.
    //            //in the if block succes +1;
    //            current = current->next;
    //            index = index->next;
    //        }
    //    }        
    //}
    //void sort_by_decrease() {
    //    node* current = new node;
    //    node* index = new node;
    //    int n = amount();
    //    int succes = 1;
    //    current = head;
    //    index = current->next;
    //    while (succes != 0) {
    //        n = amount();
    //        while (n > 2) {
    //            --n;
    //            succes = 0;
    //            if (current->data < index->data) {
    //                ++succes;
    //                product prod = current->data;
    //                current->data = index->data;
    //                index->data = prod;
    //            }
    //            //Compare data of currentand index node.If current's data is less than the index's data then, swap the data between them.
    //            //in the if block succes +1;
    //            current = current->next;
    //            index = index->next;
    //        }
    //    }
    //}
    void delete_each_n(int n) {
        int count = 1;
        int amount = 0;
        node* temp = new node;
        temp = head;
        do
        {
            temp = temp->next;
            ++amount;
        } while (temp != head);
        for (int i = 0; i < amount; i++) {
            if (count % n == 0) {
                delete_from_n_possition(count);
            }
            ++count;
        }
        
    }
  /*  void clean() 
    {
        int n = amount();
        node* previous = new node;
        node* current = new node;        
        previous = head;
        while (n > 2)
        {
            --n;
            current = previous->next;
            delete previous;
            previous = current;
            
        }
        head = NULL;
    }*/
};

int main()
{
    ////part 1 //////////////////////////
    List list;

    //////////part 2 //////////////////////
    CircularList concernA, concernB, commonProducts;
    int s1, s2;
    cout << "enter the size of first list" << endl;
    cin >> s1;
    cout << "enter the size of second list" << endl;
    cin >> s2;
    for (int i = 1; i <= s1; i++) {
        product p1;
        string str = "product" + to_string(i);
        p1.name = str;
        concernA.createnode(p1);
    }
    for (int i = 1; i <= s2; i++) {
        product p1;
        string str = to_string(i*2);
        p1.name = str;
        concernB.createnode(p1);
    }
    cout << "concern A" << endl;
    concernA.display();
    cout << "concern B" << endl;
    concernB.display();
    commonProducts = concernA.list_of_same(concernB);
    cout << "list of common" << endl;
    commonProducts.display();
}