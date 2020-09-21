#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
using namespace std;

///节点类
class Node
{
public:
    Node(int item);
    ~Node();
    void display()const;
    void setItem(int item);
    int getItem(void);
    void setNext(Node *next);
    Node *getNext(void);
private:
    int m_item;
    Node *m_next;
};

Node::Node(int item)
{
    m_item = item;
    m_next = NULL;
}
Node::~Node()
{
    if(m_next != NULL)
    {
        delete m_next;
    }
}
void Node::setNext(Node *next)
{
    m_next = next;
}

int Node::getItem(void)
{
    return m_item;
}
void Node::setItem(int item)
{
    m_item = item;
}

Node *Node::getNext(void)
{
    return m_next;
}
void Node::display()const
{
    cout << m_item << " ";
}

///////////////////////////////////////////////////////////////链表类:
class Link //:public Node
{
public:
    Link();
    Link(int len);
    ~Link();
    void insert_node(Node *p);
    Node *find_node(int item);
    void remove_node(Node *p);
    void traverse(void);
private:
    Node *m_head;
};

Link::Link()
{
    m_head = new Node(0);
    if(m_head == NULL)
    {
        cout << "failed" << endl;
    }

}
Link::~Link()
{
    if(m_head != NULL)
    {
        delete m_head;
    }
}

void Link::insert_node(Node *p)
{
    p->setNext(m_head->getNext());
    m_head->setNext(p);
}
void Link::traverse(void)
{
    Node *p = m_head->getNext();
    while (p != NULL)
    {
        cout << p->getItem() << " ";
        p = p->getNext();
    }
    cout << endl;
}
Node *Link::find_node(int item)
{
    

    Node *p = m_head->getNext();

    while (p != NULL)
    {
        if (p->getItem() == item)
        {
            return p;
        }
        //p = p->next;
        p = p->getNext();
    }

    return NULL;

}
void Link::remove_node(Node *p)
{


    Node *pre = m_head;

    while (pre->getNext() != NULL)
    {
        if (pre->getNext() == p)
        {
            // pre->next = p->next;
            // p->next = NULL;
            pre->setNext(p->getNext());
            p->setNext(NULL);
            return;
        }

        //pre = pre->next;
        pre = pre->getNext();
    }

}
//////////////////////////////////////////////main//////////////////////////////
int main()
{
    Link p;
    Node *node = new Node(10);
    p.insert_node(node);
    node = new Node(30);
    p.insert_node(node);
    Node *find = p.find_node(30);
    if(find != NULL)
    {
        cout << "find it" <<endl;
    }else
    {
        cout << "can't find" <<endl;
    }
    p.remove_node(find);
    p.traverse();
    return 0;
}