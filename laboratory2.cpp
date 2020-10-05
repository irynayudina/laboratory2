#include <iostream>
#include <algorithm>
using namespace std;
struct product {
    string name;
};
struct node
{
    product data;
    node *next;
};
class CircularList
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
    void insert_start(product value)
    {
        node* temp = new node;
        temp->data = value;
        temp->next = head;
        head = temp;
    }
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
    void delete_from_n_possition(int n) 
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
    void insert_after_position(int pos, product value)
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
    CircularList list_of_same(CircularList object) {
        CircularList result;
        node* point = new node;
        point = head;
        node* point_obj = new node;
        node* obj_head = object.get_head();
        do
        {
            do 
            {
                point_obj = obj_head;
                if (point == point_obj || point->data.name == point_obj->data.name)
                {
                    result.createnode(point->data);
                }
                point_obj = point_obj->next;
            
            } while (point_obj != obj_head);            
            point = point->next;            
        } while (point != head);
        return object;
    }
    void sort_by_increase() {

    }
    void sort_by_decrease() {

    }
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
    void clean() 
    {
       // /*node* temp = head;
       // node* current = head;
       // head = head->next;
       // delete head;
       // do
       // {
       //     temp = temp->next;
       // } while (temp != head);*/
       // node* temp = new node;
       // node* temp_head = new node;
       // node* previous = new node;
       // temp = head;
       // temp_head = head;
       //     do
       //     {
       //         previous = temp;
       //         temp = temp->next;
       //         delete previous;
       //     } while (temp != temp_head);
       //int n = amount();
       // node* previous = new node;
       // node* current = new node;
       // current = head;
       // while (n-1)
       // {
       //     delete
       //     --n;
       // }*/
        //delete_each_n(1);
        int n = amount();
        node* previous = new node;
        node* current = new node;        
        previous = head;
        while (n > 2)
        {
            --n;
           // previous = current;
            current = previous->next;
            free(previous);
            previous = current;
            
        }
        head = NULL;
        //free( head);
        /*for (int i = 2; i <= n; i++) {
            delete_from_n_possition(i);
        }
        delete head;*/
    }

};

void deleteList(node** head_ref)
{

    /* deref head_ref to get the real head */
    node* current = *head_ref;
    node* next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    /* deref head_ref to affect the real head back
        in the caller. */
    *head_ref = NULL;
}

int main()
{
    cout << "Hello World!\n";
    CircularList A, B, C, E;
    product p1;
    p1.name = "first";
    A.createnode(p1);
    A.createnode(p1);
    A.createnode(p1);
    A.createnode(p1);
    A.createnode(p1);
    A.createnode(p1);
    A.createnode(p1);
    A.createnode(p1);
    A.createnode(p1);
    A.createnode(p1);
    A.createnode(p1);
    A.createnode(p1);
    A.display();
    cout << endl;
    B = A.copy();
    B.display();
    C = A.merge(B);
   // C.display();
    A.delete_each_n(2);
    //C.delete_position(1);
    cout << "after cutting"<<endl;
    A.display();
    cout << "after cleaning"<<endl;
    A.clean();
    //B.moove_by_n_possitions(4, 1);
    node* theHead = new node;
    theHead = A.get_head();
   // deleteList(&theHead);
    A.display();
   //cout <<  A.amount();
}