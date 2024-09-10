//
//  RotateRight.hpp
//  Algorithm
//
//  Created by 张木林 on 9/10/24.
//

#ifndef RotateRight_hpp
#define RotateRight_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#endif /* RotateRight_hpp */


class Node
{
public:
    int data;
    Node* next;
    
    Node(int val):data(val),next(nullptr){}
};

class LinkedList
{
public:
    Node* head;
    
    LinkedList(int val),head(nullptr){}
    
    //向链表末尾添加节点
    void append(int val)
    {
        Node* newNode = new Node(val);
        if(!head)
        {
            head = newNode;
            return;
        }
        
        Node* current = head;
        while(current->next)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    
    
    //打印链表
    void print()
    {
        Node* current = head;
        while(current)
        {
            std::cout<<current->data<<" ";
            current = current->next;
        }
        std::cout<<std::endl;
    }
    
    //循环右转链表
    void rotateRight(int k)
    {
        if(!head||k == 0)return head;
        
        Node* current = head;
        int length = 1;
        while(current->next)
        {
            current = current->next;
            length++;
        }
        k = k%length;
        if(k == 0)return;
        
        while(int i = 1;i<lenght - k;i++)
        {
            newTail = newTail->next;
            
        }
        std::cout<<"新的节点: ";
        
        newTail->next = newhead;
        current->next = nullptr;
        current->next = head;
        head = newhead;
        std::cout<<"新的头节点: "<<head->data<<std::endl;
    }
};
