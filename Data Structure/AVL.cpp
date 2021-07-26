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
    int height;

    Node(int value){

        val = value;
        left=nullptr;
        right=nullptr;
        parent=nullptr;
        height = 0;
    }

    int getVal(){
        return val;
    }
    
};


class AVL{

private:
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

    int height(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        else {
            return node->height;
        }
    }
    
public:

    AVL(){
        root = new Node(-1);
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
        if(root->right==nullptr)
            return nullptr;
        return getMin(root->right);
        
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

     // 4 rotation functions performing rotations as per their names.
    // time ------> O(1)
    // space ------> O(1)
    Node* leftRotate(Node* node) {
        Node* right = node->right;
        Node* t1 = right->left;

        node->right = t1;
        if (t1!= nullptr) {
            t1->parent = node;
        }

        right->left = node;
        right->parent = node->parent;
        if (node->parent->left == node) {
            node->parent->left = right;
        }
        else {
            node->parent->right = right;
        }
        node->parent = right;

        node->height = 1 + max(height(node->left), height(node->right));
        right->height = 1 + max(height(right->left), height(right->right));


        return right;
    }

    Node* rightRotate(Node* node) {
        Node* left = node->left;
        Node* t1 = left->right;


        node->left = t1;
        if (t1 != nullptr ){
            t1->parent = node;
        }

        left->right = node;
        left->parent = node->parent;
        if (node->parent->left == node) {
            node->parent->left = left;
        }
        else {
            node->parent->right = left;
        }
        node->parent = left;

        node->height = 1 + max(height(node->left), height(node->right));
        left->height = 1 + max(height(left->left), height(left->right));

        return left;

    }

    Node* rightLeftRotate(Node* node) {
        node->right = rightRotate(node->right);

        return leftRotate(node);
    }

    Node* leftRightRotate(Node* node){
        node->left = leftRotate(node->left);

        return rightRotate(node);
    }
    
    // CheckBalance function maintains the height balanced property and perform desired rotations.
    // time ------> O(logn)
    // space ------> O(1)
    void checkBalance(Node* node) {

        // cout<<"lol "<<(node==nullptr)<<endl;
        while (node->parent) {
            int lh = height(node->left);
            int rh = height(node->right);
            node->height = 1 + max(lh,rh);
            int llh = 0;
            int lrh = 0;
            int rlh = 0;
            int rrh = 0;
            if (lh != 0) {
                llh = height(node->left->left);
                lrh = height(node->left->right);
            }
            if (rh != 0) {
                rlh = height(node->right->left);
                rrh = height(node->right->right);
            }


            int hDiff = lh-rh;

            if (hDiff > 1) {
                int hDiffL = llh - lrh; 
                if (hDiffL >= 0){
                    node = rightRotate(node);
                }
                else {
                    node = leftRightRotate(node);
                }
            }

            else if (hDiff < -1) {
                int hDiffR = rrh - rlh;
                if (hDiffR >= 0){
                    node = leftRotate(node);
                }
                else {
                    node = rightLeftRotate(node);
                }
            }
            node = node->parent;
        }
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
        checkBalance(n);
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

    void print2D(){    
        print2D(root, 0, 5);  
    }
    
};

int main(int argc, char const *argv[])
{
    AVL* b = new AVL();
    Node* a = b->insert(1);
    b->insert(2);
    b->insert(3);
    b->insert(4);
    b->insert(5);
    b->insert(6);
    b->insert(7);

    b->print2D();
    cout<<"khatam"<<endl;
    cout<<b->getMax()->getVal()<<endl;
    cout<<b->getMin()->getVal()<<endl;
    cout<<b->pred(a->parent)->getVal()<<endl;
    b->remove(4);
    cout<<"Tree after del\n"<<endl;
    b->print2D();
    return 0;
}