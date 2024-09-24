#include"BiaryTree.h"
#include<iostream>

int main()
{
    BinaryTree tree;

    //插入节点
    tree.root = tree.insert(tree.root,50);
    tree.insert(tree.root,30);
    tree.insert(tree.root,70);
    tree.insert(tree.root,20);
    tree.insert(tree.root,40);
    tree.insert(tree.root,60);

    //前序遍历
    cout<<"前序遍历: ";
    tree.postOrder(tree.root);
    cout<<endl;

    cout<<"中序遍历: ";
    tree.inOrder(tree.root);
    cout<<endl;
    
    cout<<"后序遍历: ";
    tree.postOrder(tree.root);
    cout<<endl;

    return 0;

}