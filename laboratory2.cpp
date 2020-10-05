//#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

// Custom class to handle Linked List operations 
// Operations like push_back, push_front, pop_back, 
// pop_front, erase, size can be added here 
template <typename T>
class LinkedList
{
    // Forward declaration 
    class Node;

public:
    LinkedList<T>() noexcept
    {
        // caution: static members can't be 
        // initialized by initializer list 
        m_spRoot = nullptr;
    }

    // Forward declaration must be done 
    // in the same access scope 
    class Iterator;

    // Root of LinkedList wrapped in Iterator type 
    Iterator begin()
    {
        return Iterator(m_spRoot);
    }

    // End of LInkedList wrapped in Iterator type 
    Iterator end()
    {
        return Iterator(nullptr);
    }

    // Adds data to the end of list 
    void push_back(T data);

    void Traverse();

    // Iterator class can be used to 
    // sequentially access nodes of linked list 
    class Iterator
    {
    public:
        Iterator() noexcept :
            m_pCurrentNode(m_spRoot) { }

        Iterator(const Node* pNode) noexcept :
            m_pCurrentNode(pNode) { }

        Iterator& operator=(Node* pNode)
        {
            this->m_pCurrentNode = pNode;
            return *this;
        }

        // Prefix ++ overload 
        Iterator& operator++()
        {
            if (m_pCurrentNode)
                m_pCurrentNode = m_pCurrentNode->pNext;
            return *this;
        }

        // Postfix ++ overload 
        Iterator operator++(int)
        {
            Iterator iterator = *this;
            ++* this;
            return iterator;
        }

        bool operator!=(const Iterator& iterator)
        {
            return m_pCurrentNode != iterator.m_pCurrentNode;
        }

        int operator*()
        {
            return m_pCurrentNode->data;
        }

    private:
        const Node* m_pCurrentNode;
    };

private:

    class Node
    {
        T data;
        Node* pNext;

        // LinkedList class methods need 
        // to access Node information 
        friend class LinkedList;
    };

    // Create a new Node 
    Node* GetNode(T data)
    {
        Node* pNewNode = new Node;
        pNewNode->data = data;
        pNewNode->pNext = nullptr;

        return pNewNode;
    }

    // Return by reference so that it can be used in 
    // left hand side of the assignment expression 
    Node*& GetRootNode()
    {
        return m_spRoot;
    }

    static Node* m_spRoot;
};

template <typename T>
/*static*/ typename LinkedList<T>::Node* LinkedList<T>::m_spRoot = nullptr;

template <typename T>
void LinkedList<T>::push_back(T data)
{
    Node* pTemp = GetNode(data);
    if (!GetRootNode())
    {
        GetRootNode() = pTemp;
    }
    else
    {
        Node* pCrawler = GetRootNode();
        while (pCrawler->pNext)
        {
            pCrawler = pCrawler->pNext;
        }

        pCrawler->pNext = pTemp;
    }
}

template <typename T>
void LinkedList<T>::Traverse()
{
    Node* pCrawler = GetRootNode();

    while (pCrawler)
    {
        cout << pCrawler->data << " ";
        pCrawler = pCrawler->pNext;
    }

    cout << endl;
}


#include <iostream>
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
        do 
        {
            cout << temp->data.name << "\n";
            temp = temp->next;
        } while (temp != head);
    }
    void moove_by_n_possitions() 
    {

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
       // previous = head;
        current = head;
        while (n > 1) 
        {
            previous = current;
            current = current->next;
            --n;
        }
        previous->next = current->next;
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
    void clean() 
    {

    }
    /*
    void delete_first()
    {
        node* temp = new node;
        temp = head;
        head =  head->next;
        delete temp;
    }
    void delete_last()
    {
        node* current = new node;
        node* previous = new node;
        current = head;
        while (current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
        tail = previous;
        previous->next = NULL;
        delete current;
    }*/
    class Iterator
    {
    public:
        Iterator() noexcept :
            m_pCurrentNode(m_spRoot) { }

        Iterator(const Node* pNode) noexcept :
            m_pCurrentNode(pNode) { }

        Iterator& operator=(Node* pNode)
        {
            this->m_pCurrentNode = pNode;
            return *this;
        }

        // Prefix ++ overload 
        Iterator& operator++()
        {
            if (m_pCurrentNode)
                m_pCurrentNode = m_pCurrentNode->pNext;
            return *this;
        }

        // Postfix ++ overload 
        Iterator operator++(int)
        {
            Iterator iterator = *this;
            ++* this;
            return iterator;
        }

        bool operator!=(const Iterator& iterator)
        {
            return m_pCurrentNode != iterator.m_pCurrentNode;
        }

        int operator*()
        {
            return m_pCurrentNode->data;
        }

    private:
        const node* m_pCurrentNode;
    };
    void delete_position(int pos)
    {
        node* current = new node;
        node* previous = new node;
        current = head;
        for (int i = 1; i < pos; i++)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
    }
};


int main()
{
    cout << "Hello World!\n";
    CircularList A, B, C;
    product p1;
    p1.name = "first";
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
    A.delete_from_n_possition(1);
    //C.delete_position(1);
    cout << "after cutting";
    A.display();


    LinkedList<int> list;

    // Add few items to the end of LinkedList 
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    cout << "Traversing LinkedList through method" << endl;
    list.Traverse();

    cout << "Traversing LinkedList through Iterator" << endl;
    for (LinkedList<int>::Iterator iterator = list.begin();
        iterator != list.end(); iterator++)
    {
        cout << *iterator << " ";
    }

    cout << endl;

    return 0;
}