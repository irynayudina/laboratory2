#include <iostream>
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
            cout << temp->data.name << "\n";
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
        if (pos_of_elem > amount() || n > amount()-pos_of_elem) { return; }
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
class CircularList : public List
{
//private:
//    node * head, * tail;
public:
    CircularList()
    {
        head = NULL;
        tail = head;
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
    void set_head(node* n) {
        head = n;
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
        if (pos_of_elem > amount()) { return; }
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
    CircularList list_of_same(CircularList object) {
        CircularList result;        
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
    void delete_each_n(int n) {
        if (n > amount()) { return; }
        if (n == 1) { clean(); return; }
        int count = 1;
        int _amount = 0;
        node* temp = new node;
        temp = head;
        
        do
        {
            temp = temp->next;
            ++_amount;
        } while (temp != head);
        for (int i = 0; i < _amount; i++) {
            if (count % n == 0) {
                delete_from_n_possition(count);
            }
            ++count;
        }        
    }
    void insert_start(product value)//******************WILL BE INHERITED IN CIRCULAR LIST CLASS***********************
    {
        node* temp = new node;
        temp->data = value;
        temp->next = head;
        head = temp;
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

int main()
{
    ////part 1 //////////////////////////
    cout << "Part 1" << endl;
    List list, list2;
    product p1;
    int num_of_elem, ind;
    p1.name = "name";
    int sl1, sl2;
    cout << "enter the size of first list" << endl;
    cin >> sl1;
    cout << "enter the size of second list" << endl;
    cin >> sl2;
    for (int i = 1; i <= sl1; i++) {
        product p1;
        string str = "product" + to_string(i);
        p1.name = str;
        list.createnode(p1);
    }
    for (int i = 1; i <= sl2; i++) {
        product p1;
        string str = "product" + to_string(i*2);
        p1.name = str;
        list2.createnode(p1);
    }
    int choise = 0;
    while (choise != 12) {
        cout << "choose the action" << endl;
        cout << "1 - move j element by n positions" << endl;
        cout << "2 - make a copy of the list" << endl;
        cout << "3 - add to the top" << endl;
        cout << "4 - merge to lists" << endl;
        cout << "5 - delete n element from the list" << endl;
        cout << "6 - insert after n element of the list" << endl;
        cout << "7 - make a list of common elements of 2 given lists" << endl;
        cout << "8 - sort elements of list by increase" << endl;
        cout << "9 - sort elements of list by dicrease" << endl;
        cout << "10 - delete each n element" << endl;
        cout << "11 - clean the list" << endl;
        cout << "12 - exit this part of menu" << endl;
        cin >> choise;
        switch (choise) {
        case 1:
            cout << "enter a number of the element you want to move" << endl;
            cin >> num_of_elem;
            cout << "how many positions do you want to move the element?" << endl;
            cin >> ind;
            list.moove_by_n_possitions(num_of_elem, ind);
            list.display();
            break;
        case 2:
            list2 = list.copy();
            list2.display();
            break;
        case 3:
            list.insert_start(p1);
            list.display();
            break;
        case 4:
            list.merge(list2);
            list2.display();
            break;
        case 5:
            cout << "enter a number of the element you want to delete" << endl;
            cin >> num_of_elem;
            list.delete_from_n_possition(num_of_elem);
            list.display();
            break;
        case 6:
            cout << "enter a number of the position you want to insert at" << endl;
            cin >> ind;
            list.insert_after_position(ind, p1);
            list.display();
            break;
        case 7:
            list.list_of_same(list2);
            list.display();
            break;
        case 8:
            list.sort_by_increase();
            list.display();
            break;
        case 9:
            list.sort_by_decrease();
            list.display();
            break;
        case 10:
            cout << "enter n to delete each n element" << endl;
            cin >> ind;
            list.delete_each_n(ind);
            list.display();
            break;
        case 11:
            list.clean();
            list.display();
            break;
        }
    }

    //////////part 2 //////////////////////
    cout << "Part 2" << endl;
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
        string str = "product" + to_string(i*2);
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