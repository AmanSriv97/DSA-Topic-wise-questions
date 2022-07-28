#include <bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this-> left = NULL;
        this-> right = NULL;
    }
};

Node* insertIntoBst( Node* &root, int data)
{
    //base case
    if(root == NULL)
    {
        // create a new node
        root = new Node (data);
        return root;
    }

    if(root->data >data)
    {
        root-> left = insertIntoBst(root->left, data);
    }
    else{
        root-> right = insertIntoBst(root-> right, data);
    }

    return root;
}

void takeInput (Node* &root)
{
    int data;
    cin>> data;

    while(data!= -1)
    {
        insertIntoBst(root,data);
        cin>> data;
    }
}

void LevelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);

    //cout<< "root data is " << root->data;
    while(!q.empty())
    {
        Node * temp = q.front();
        q.pop();
        
        cout<< temp-> data << " ";
        if(temp-> left)
        {
            q.push(temp->left);
        }
        if(temp-> right)
        {
            q.push(temp-> right);
        }
    }
}

void preorder(Node* root)
{
    // base case
    if(root == NULL)
    {
        return ;
    }

    cout<< root-> data<< " ";
    preorder(root-> left);
    preorder(root-> right);
}

Node * minValue( Node * root)
{
    // Base case
    if( root == NULL)
    {
         return root;
    }

    Node * temp = root;
    while(temp-> left != NULL)
    {
        temp = temp-> left;
    }

    return temp;
}

Node* DeleteFromBST ( Node * root, int val)
{
    // Base case
    if( root == NULL)
    {
        return root;
    }
    if( root-> data == val)
    {
        // 0 child
        if( root-> left == NULL && root-> right == NULL)
        {
            delete root;
            return NULL;
        }


        // 1 child 
        // left child
        if( root -> left != NULL && root-> right ==  NULL)
        {
            Node * temp = root-> left;
            delete root;
            return temp;
        }    

        // right child
        if( root -> left == NULL && root-> right !=  NULL)
        {
            Node * temp = root-> right;
            delete root;
            return temp;
        }  


        // 2 child
        if( root-> left != NULL && root-> right != NULL)
        {
            int mini = minValue(root-> right)-> data;
            root-> data = mini;
            root-> right = DeleteFromBST( root-> right, mini);
            return root;
        }
    }

    else if( root -> data > val)
    {
        root -> left = DeleteFromBST( root-> left, val);
        return root;
    }
    else{
        root-> right = DeleteFromBST( root-> right, val);
        return root;
    }
}



int main()
{
    Node * root = NULL;

    cout<< " Enter the data to insert into BST" << endl;
    takeInput(root);

    cout<< "Level Order traversal"<< endl;
    LevelOrderTraversal(root);

    cout<< endl<< "preorderTraversal"<<endl;

    preorder(root);


    // Deletion
    root = DeleteFromBST(root, 30);


    cout<< endl<< "Level Order traversal after deletion"<< endl;
    LevelOrderTraversal(root);

    cout<< endl<< "preorderTraversal"<<endl;

    preorder(root);
    return 0;
}
