#pragma once
#include <iostream>
#include <QMessageBox>
#include "mainone.h"
#define private public
extern int flag;
template<typename T> class DoubleLinkList
{
    //类型声明
private:
    class node
    {
    public:
        T data;
        node *next = nullptr;
        node *prior = nullptr;

    public:
        node() {}
        node(T _data) : data(_data) {}
        ~node() {}
    };
    using node_ptr = node*;
    using callback_t = void(T&);
    using condition_compare_t = bool(const T&, const T&);
    using condition_t = bool(T&, T& info);

    //成员变量
private:
    node_ptr head, tail;
    long cnt = 0; //供qt版本使用

    //开放接口
public:
    DoubleLinkList() : head(new node), tail(head) {}
    ~DoubleLinkList() {
        clear();
        delete head;
    }

    long get_cnt() {
        return cnt;
    }

    void push_back(const T& a) { //在尾部插入新结点
        tail->next = new node(a);
        tail->next->prior = tail;
        tail = tail->next;
        ++cnt;
    }

    void push_with_order(T& a, condition_compare_t f) { //按照一定的顺序，在满足约束条件的最后一个结点后插入新结点
        if(head->next == nullptr)
        {
            push_back(a);
            return;
        }
        if(!f(head->next->data, a))
        {
            node_ptr temp = head->next;
            head->next = new node(a);
            head->next->prior = head;
            head->next->next = temp;
            temp->prior = head->next;
            ++cnt;
            return;
        }
        for(node_ptr p = head->next; p != nullptr; p = p->next)
        {
            if( f(p->data, a) && (p->next == nullptr || !f(p->next->data, a)) )
            {
                node_ptr temp = p->next;
                p->next = new node(a);
                p->next->prior = p;
                p->next->next = temp;
                if(temp != nullptr)
                    temp->prior = p->next;
                else
                    tail = p;
                ++cnt;
                break;
            }
        }
    }

    void emplace_back(const T& pre, const T& a) { //在pre元素所在结点后插入新结点
        node_ptr p = locate(pre);
        if(p == nullptr)
        {
            std::cout << "Prior element not exist." << std::endl;
            exit(EXIT_FAILURE);
        }
        node_ptr temp = p->next;
        p->next = new node(a);
        p->next->next = temp;
        p->next->prior = p;
        if(temp != nullptr)
            temp->prior = p->next;
        else
            tail = p;
        ++cnt;
    }

    void remove(const T& a) { //删除指定元素所在结点
        node_ptr p = locate(a);
        if(p == nullptr)
        {
            std::cout << "Can't remove a not existing element." << std::endl;
        }
        p->prior->next = p->next;
        if(p->next != nullptr)
            p->next->prior = p->prior;
        else
            tail = p->prior;
        delete p;
        --cnt;
    }

    void remove_with_condition(condition_t f, T& info) { //删除满足指定条件的结点
        int cnt1=0;
        for(node_ptr p = head->next; p != nullptr; )
        {
            if(f(p->data, info))
            {
                cnt1++;
                p->prior->next = p->next;
                if(p->next != nullptr)
                    p->next->prior = p->prior;
                else
                    tail = p->prior;
                node_ptr temp = p;
                p = p->next;
                delete temp;
                --cnt;
            }
            else
                p = p->next;
        }
        if(cnt1==0)
        {
            QMessageBox::question(NULL, "Warning", "Not Found",QMessageBox::Ok);
        }
        else
        {
            if(flag!=20)
                QMessageBox::question(NULL, " ", "Deleted",QMessageBox::Ok);
        }
    }


    void clear() { //清空链表，只保留头结点
        for(node_ptr i = head->next; i != nullptr; )
        {
            node_ptr temp = i;
            i = i->next;
            delete temp;
        }
        head->next = nullptr;
        tail = head;
        cnt = 0;
    }

    DoubleLinkList<T>& operator=(DoubleLinkList<T>& a) { //深复制，参数一加const就过不了编译，不知道为什么
        clear();
        for(iterator i = a.begin(); i != a.end(); i++)
            push_back(*i);
        return *this;
    }

    void traverse(callback_t f) { //按指定操作遍历
        for(iterator i = begin(); i != end(); i++)
            f(*i);
    }

    //内部函数
private:
    node_ptr locate(const T& a) { //定位特定元素所在结点，若不存在则返回nullptr
        for(node_ptr p = head->next; p != nullptr; p = p->next)
        {
            if(p->data == a)
                return p;
        }
        return nullptr;
    }


    //迭代器相关
public:
    friend class iterator;

    class iterator
    {
    public:
        node_ptr pointer;

    public:
        iterator() {}
        iterator(node_ptr p) : pointer(p) {}
        ~iterator() {}

        iterator& operator++() {
            pointer = pointer->next;
            return *this;
        }

        iterator operator++(int) {
            iterator temp = pointer;
            pointer = pointer->next;
            return temp;
        }

        iterator& operator--() {
            pointer = pointer->prior;
            return *this;
        }

        iterator operator--(int) {
            iterator temp = pointer;
            pointer = pointer->prior;
            return temp;
        }

        iterator& operator=(const iterator& a) {
            pointer = a.pointer;
            return *this;
        }

        bool operator==(const iterator& a) {
            return (pointer == a.pointer);
        }

        bool operator!=(const iterator& a) {
            return (pointer != a.pointer);
        }

        iterator operator+(int n) {
            node_ptr temp = pointer;
            for(int i = 0; i < n; i++)
            {
                if(temp == nullptr)
                {
                    std::cout << "Iterator out of range." << std::endl;
                    exit(EXIT_FAILURE);
                }
                temp = temp->next;
            }
            return iterator(temp);
        }

        iterator operator-(int n) {
            node_ptr temp = pointer;
            for(int i = 0; i < n; i++)
            {
                if(temp == nullptr)
                    break;
                temp = temp->prior;
            }
            return iterator(temp);
        }

        T& operator*() {
            if(pointer == nullptr)
            {
                std::cout << "Usage of empty pointer" << std::endl;
                exit(EXIT_FAILURE);
            }
            return pointer->data;
        }
    };

    iterator begin() {
        return iterator(head->next);
    }

    iterator end() {
        return iterator(nullptr); //TODO  在想有没有循环的必要
    }

    iterator rbegin() {
        return iterator(tail);
    }

    iterator rend() {
        return iterator(head);
    }
};
