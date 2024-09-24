#include<iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val):data(val),left(nullptr),right(nullptr){}
    
};


class BinaryTree
{
public:
    TreeNode* root;

    //构造函数，初始化根节点为空
    BinaryTree():root(nullptr){}

    //插入节点(递归)
    TreeNode* insert(TreeNode* node,int data)
    {
        //如果当前节点为空，创建新节点并返回
        if(node == nullptr)
        {
            return new TreeNode(data);
        }

        //插入到左子树
        if(data<node->data)
        {
            node->left = insert(node->left,data);
        }

        //插入到右子树
        else if(data>node->data)
        {
            node->right = insert(node->right,data);
        }
        return node;


    }

    //前序遍历
    void preOrder(TreeNode* node)
    {
        if(node == nullptr)
        {
            return;
        }
        cout<<"node->data"<<" ";//访问跟节点
        preOrder(node->left);
        preOrder(node->right);
    }

    //中序遍历(根 左 右)
    void inOrder(TreeNode* node)
    {
        if(node == nullptr)
        {
            return;
        }
        inOrder(node->left);
        cout<<node->data<<" ";
        inOrder(node->right);
    }

    //后序遍历
    void postOrder(TreeNode* node)
    {
        if(node == nullptr)
        {
            return;
        }
        postOrder(node->left);
        postOrder(node->right);
        cout<<node->data<<" ";
    }
};