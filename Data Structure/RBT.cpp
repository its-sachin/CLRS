#include "BST.cpp"

using namespace std;

enum COLOR{
    BLACK,
    RED
};

class Node{

private:
    int val;
    
public:

    Node* left;
    Node* right;
    Node* parent;
    COLOR color;

    Node(int value, COLOR C){
        val = value;
        left=nullptr;
        right=nullptr;
        parent=nullptr;
        color = C;
    }

    int getVal(){
        return val;
    }
    
};

class RBT : public BST{

private:
    
    
public:
    RBT(): BST(){}
    RBT(Node* r): BST(r){}

    Node* insert(int key){
        Node* curr = root;
        Node* parent = nullptr;
        Node* n = new Node(key,);
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
    
};

int main(int argc, char const *argv[])
{
    RBT* b = new RBT();
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