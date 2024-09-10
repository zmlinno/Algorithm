//
//  DoublyList.cpp
//  Algorithm
//
//  Created by 张木林 on 9/10/24.
//

#include "DoublyList.hpp"
#include<iostream>
#include "Test.hpp"
//class Node
//{
//public:
//    int data;   //节点数据
//    Node* prev; //前驱节点
//    Node* next; //后继节点
//    
//    Node(int val):data(val),prev(nullptr),next(nullptr){}
//    
//};
//
////双向链表类
//class DoublyLinkedList
//{
//private:
//    Node* head; //链表头
//    Node* tail; //链表尾
//    
//public:
//    //构造函数
//    DoublyLinkedList():head(nullptr),tail(nullptr){}
//    
//    //向链表末尾插入节点
//    void append(int val)
//    {
//        Node* newNode = new Node(val);
//        if(!head)
//        {
//            //如果链表为空
//            head = tail = newNode;
//        }
//        else
//        {
//            tail->next = newNode;
//            newNode->prev = tail;
//            tail = newNode;
//        }
//    }
//    
//    //删除链表中的某个值
//    void remove(int val)
//    {
//        Node* current = head;
//        while(current)
//        {
//            if(current->data == val)
//            {
//                if(current->prev)
//                {
//                    current->prev->next = current->next;
//                }
//                else
//                {
//                    head = current->next; //更新头节点
//                }
//                if(current->next)
//                {
//                    current->next->prev = current->prev;
//                }
//                else
//                {
//                    tail = current->prev; //更新尾节点
//                }
//                delete current;
//                return;
//            }
//            current = current->next;
//        }
//        std::cout<<"Value"<<val<<"not found in the list.\n";
//    }
//    //正向打印链表
//    void display()
//    {
//        Node* current = head;
//        while(current)
//        {
//            std::cout<<current->data<<" ";
//            current = current->next;
//        }
//        std::cout<<std::endl;
//    }
//    
//    //反向打印链表
//    void displayReverse()
//    {
//        Node* current = tail;
//        while(current)
//        {
//            std::cout<<current->data<<" ";
//            current = current->prev;
//        }
//        std::cout<<std::endl;
//    }
//};
//int main()
//{
//    DoublyLinkedList dll;
//    
//    //插入元素
//    dll.append(10);
//    dll.append(20);
//    dll.append(30);
//    dll.append(40);
//    dll.append(50);
//    
//    std::cout<<"正向打印链表: ";
//    dll.display();
//    
//    std::cout<<"反向打印链表: ";
//    dll.displayReverse();
//    
//    //删除元素
//    dll.remove(20);
//    std::cout<<"删除 20 后的链表: ";
//    dll.display();
//    
//    
//    return 0;
//}
