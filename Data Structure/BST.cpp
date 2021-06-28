#include <iostream>
#include <vector>

using namespace std;

class Node{

private:
    int val;
    
public:

    Node* left;
    Node* right;
    Node* parent;

    Node(int value){
        val = value;
        left=nullptr;
        right=nullptr;
        parent=nullptr;
    }

    int getVal(){
        return val;
    }
    
};

class BST{

protected:
    Node* root;

    void inorder(vector<int> &v, Node* n){
        if(n){
            inorder(v,n->left);
            v.push_back(n->getVal());
            inorder(v,n->right);
        }
    }

    void print2D(Node* root,int space, int inc)  
    {  
        if (!root)  
            return;  
      
        space += inc;  
        print2D(root->right, space, inc);  
      
        cout<<"\n";  
        for (int i = inc; i < space; i++)  
            cout<<" ";  
        cout<<root->getVal()<< "\n";  
        print2D(root->left, space, inc);  
    }  
    
public:
    BST(){
        root = nullptr;
    }

    BST(Node* r){
        root = r;
    }

    BST(int val){
        root = new Node(val);
    }

    vector<int> inorder(){
        vector<int> ans;
        inorder(ans,root);
        return ans;
    }

    Node* find(int key){
        Node* curr = root;
        while(curr){
            if(curr->getVal()==key){
                return curr;
            }
            else if(curr->getVal()>key){
                curr=curr->left;
            }
            else{
                curr = curr->right;
            }
        }
        return curr;
    }

    Node* getMin(Node* currRoot){
        if(!currRoot){
            return currRoot;
        }
        Node* curr = currRoot;
        while(curr->left){
            curr=curr->left;
        }
        return curr;
    }

    Node* getMin(){
        return getMin(root);
        
    }

    Node* getMax(Node* currRoot){
        if(!currRoot){
            return currRoot;
        }
        Node* curr = currRoot;
        while(curr->right){
            curr=curr->right;
        }
        return curr;
    }

    Node* getMax(){
        return getMax(root);
        
    }

    Node* succ(Node* n){
        if(n->right){
            return getMin(n->right);
        }
        Node* x = n;
        Node* y = n->parent;
        while(y && x==y->right){
            x=y;
            y=y->parent;
        }
        return y;
    }

    Node* pred(Node* n){
        if(n->left){
            return getMax(n->left);
        }
        Node* x = n;
        Node* y = n->parent;
        while(y && x==y->left){
            x=y;
            y=y->parent;
        }
        return y;
    }

    Node* insert(int key){
        Node* curr = root;
        Node* parent = nullptr;
        Node* n = new Node(key);
        while(curr){
            parent = curr;
            if(curr->getVal()>=key){
                curr=curr->left;
            }
            else{
                curr = curr->right;
            }
        }
        if(!parent){
            root = n;
        }
        else if(parent->getVal()<key){
            parent->right = n;
            n->parent = parent;
        }
        else{
            parent->left = n;
            n->parent = parent;
        }
        return n;
        
    }

    void setParent(Node* a, Node* b){
        //places b in place of a
        //only sets pointers of parent of a to b
        if(a->parent){
            if(a->parent->left==a){
                a->parent->left=b;
            }
            else{
                a->parent->right=b;
            }
        }
        else{
            root = b;
        }
        if(b){
            b->parent = a->parent;
        }
    }

    void remove(Node* n){
        if(n){
            if(!n->left){
                setParent(n,n->right);
            }
            else if (!n->right){
                setParent(n,n->left);
            }
            else{
                Node* succ = getMin(n->right);
                if(succ->parent != n){
                    setParent(succ,succ->right);
                    succ->right = n->right;
                    succ->right->parent = succ;
                }
                setParent(n,succ);
                succ->left = n->left;
                succ->left->parent = succ;
                
            }
        }
    }

    void remove(int key){
        remove(find(key));
    }

      
    void print2D()  
    {    
        print2D(root, 0, 5);  
    }
    


    
};

int main(int argc, char const *argv[])
{
    BST* b = new BST();
    Node* a = b->insert(28);
    b->insert(100);
    b->insert(2);
    b->insert(4);
    b->insert(20);
    b->insert(19);
    b->insert(3);

    b->print2D();
    cout<<b->getMax()->getVal()<<endl;
    cout<<b->getMin()->getVal()<<endl;
    cout<<b->pred(a)->getVal()<<endl;
    b->remove(28);
    cout<<"Tree after del\n"<<endl;
    b->print2D();
    return 0;
}