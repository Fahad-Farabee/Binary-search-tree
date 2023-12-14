#include<bits/stdc++.h>
using namespace std;

struct Node{
int value;
struct Node* Left;
struct Node* Right;
};
///inserting nodes....
Node* insertNode(Node* root, int elem){
if(root==NULL){
    Node* N = new Node;
    N->value = elem;
    N->Left=NULL;
    N->Right=NULL;
    root = N;
    return root;
}

if(elem< root->value){
    ///left side of the bst...
    root->Left = insertNode(root->Left, elem);
}

else{
    ///right side of the bst...
    root->Right = insertNode(root->Right, elem);
}
return root;
}
///finding minimum element from the tree or node..
int findMinFromtheTree(Node* root){
if(root==NULL) {
    return -1;
}

if(root->Left==NULL){
    return root->value;
}
else{
    return findMinFromtheTree(root->Left);
}
}
///finding maximum element from the tree or node..
int findMaxFromTheTree(Node* root){
if(root==NULL){
    return -1;
}

if(root->Right==NULL){
    return root->value;
}
else{
    return findMaxFromTheTree(root->Right);
}
}




///searching an item in the tree ....
int searchItem(Node* root, int item){
if(root == NULL){
    return 0;
}

if(item<root->value){
    return searchItem(root->Left, item);
}
else if(item>root->value){
    return searchItem(root->Right, item);
}
else{
    return 1;
}
}



///Delete Node..
Node* FindMinNode(Node* root){
if(root == NULL) return root;
if(root->Left==NULL) return root;
else{
    return FindMinNode(root->Left);
}
}
Node* FindMaxNode(Node* root){
if(root == NULL) return root;
if(root->Right== NULL) return root;
else{
    return FindMaxNode(root->Right);
}
}

Node* deleteNode(Node* root, int element){

    ///first we will have find the node that contains the element
if(root == NULL) return root;

if(element<root->value){
    ///left subtree..
    root->Left = deleteNode(root->Left, element);
}
else if(element> root->value){
    ///right subtree..
    root->Right = deleteNode(root->Right, element);
}

///the node is found in here.
else {
    ///we found the item....
    ///case 1: node has no child..
    if(root->Left==NULL && root->Right == NULL){
        delete root;
        root = NULL;
    }
    ///case 2: Node has only one child. Either a right or a left child...
     else if(root->Left==NULL){
        ///node has only one right child.
        Node* Temp = root;
        root = root->Right;
        delete Temp;
     }
     else if(root->Right==NULL){
        ///node has only one left child..
        Node* temp = root;
        root = root->Left;
        delete temp;
     }

     ///case 3: Node has 2 child..
     else{
            //this kind of problem can be handled in two ways
            //1. we can use the right path.
            //2. or we can use the left path.

            //step 1: if we use the right path then we have to find the minimum node from the right side.
            //step 2: store the minimum node in a temp node.
            //step 3: then we will swap the root node value with the minimum node value.
            //step 4: then we will use the recursion to remove the minimum node from the tree.
        Node* temp = FindMinNode(root->Right);///step 1 and 2
        root->value = temp->value;///step 3
        root->Right = deleteNode(root->Right, temp->value);///step 4
            ///this code will return 13 for the current tree.Because on the right side the minimum node is 13.

          /* both code will work.
          //step 1: if we use the Left path then we have to find the Maximum node from the Left side.
          //step 2: store the Maximum node in a temp node.
          //step 3: then we will swap the root node value with the Maximum node value.
         //step 4: then we will use the recursion to remove the Maximum node from the tree.
         Node* temp = FindMaxNode(root->Left);///step 1 and 2
        root->value = temp->value;///step 3
        root->Left = deleteNode(root->Left, temp->value);///step 4

        ///this code will return 9 for the current tree. because on left side the maximum node is 9.
        */
     }
}
return root;
}

///finding parent.....

int findParent(Node* root, int value){
if(root==NULL){
        ///The tree is empty..
    return-1;
}
if(root->value==value){
    ///value is matched with the root.
    return -1;
}

else if((root ->Left && root->Left->value == value)||(root->Right&&root->Right->value==value)){
    ///for children..
    return root->value;
}

///if value has not been found...
if(value<root->value){
    return findParent(root->Left, value);
}
else{
     return findParent(root->Right, value);
}
}


///finding children.....
//First i will find the root node of the element..
Node* findRoot(Node* root, int elem){
if(root == NULL){
    return root;
}

if(elem<root->value){
    return findRoot(root->Left, elem);
}
else if(elem>root->value){
    return findRoot(root->Right, elem);
}
else{
    return root;
}
}

//then i will just print the left and right children of the root node
void findChildren(Node* root, int val){
struct Node* R = findRoot(root, val);
if(R != NULL){
    if(R->Left==NULL && R->Right==NULL)cout<< "This is a leaf there is no child of this node"<<endl;///there is no children of this node
    else if(R->Left==NULL) cout<< "There is only right child of this node.."<< R->Right->value<<endl;///there is only right children of this node.
    else if(R->Right== NULL)cout<< "there is only left child of this node.."<< R->Left->value<<endl;///there is only left children of this node.
    else{
        cout<< "The left child of the node is: "<< R->Left->value<< " The right child of the node is: "<< R->Right->value<<endl;///there are both right and left child of this node.
    }
}
else{
    cout<< "No such node found....";///there is no node like this.
}
}



///find sibling....
Node* FindParent(Node* root, int elem){
if(root == NULL) return root;
if(root->value == elem) return root;
else if((root->Left && root->Left->value == elem) || (root->Right&& root->Right->value == elem) ){
   return root;
}
if(elem <root->value){
    return FindParent(root->Left, elem);
}
else
{
    return FindParent(root->Right, elem);
}
}



void findSibling(Node* root, int elem){
struct Node* S = FindParent(root, elem);
if(S!=NULL){
    if(S->Left!=NULL && S->Right!=NULL){
        if(S->Left->value==elem) cout<< "the sibling is : "<< S->Right->value;
        else cout<< "The sibling is : " << S->Left->value;
    }
    if(S->Left==NULL || S->Right==NULL) cout<< "there is no sibling"<< endl;
}
else{
    cout<< "There is no parent of this node...."<< endl;
}
}



///Finding ancestors..
bool findAncestors(Node*root, int val){

if(root==NULL) return false;
if(root->value == val) return true;
if(findAncestors(root->Left, val)||findAncestors(root->Right, val)){
    cout<< root->value<< " ";
    return true;
}
return false;
}

///Finding successor...
Node* findSuccessor(Node* root,int elem){
/*if(root == NULL) return root;
root = root->Right;
while(root->Left){
    root = root->Left;
}
return root;
*/
struct Node* N = findRoot(root, elem);
if(N==NULL) return N;
N = N->Right;
while(N->Left){
    N = N->Left;
}
return N;
}
void printSuccessor(Node* root, int elem){
struct Node* sc = findSuccessor(root,elem);
cout<< "The successor is: "<< sc->value<< endl;
}



//Finding predecessor....
Node* findPredecessor(Node* root, int elem){
struct Node* fp = findRoot(root, elem);
if(fp==NULL) return fp;
fp = fp->Left;
while(fp->Right){
    fp=fp->Right;
}
return fp;
}
void printPredecessor(Node* root, int elem){
struct Node* fp = findPredecessor(root, elem);
cout<< "The predecessor is: "<< fp->value<< endl;
}













int main(){
    Node* root = NULL;
   root  =  insertNode(root, 12);
   root  =  insertNode(root, 5);
   root  =  insertNode(root, 3);
   root  =  insertNode(root, 7);
   root  =  insertNode(root, 15);
   root  =  insertNode(root, 9);
   root  =  insertNode(root, 1);
   root  =  insertNode(root, 17);
   root  =  insertNode(root, 13);
   cout<< "root->Left-> Right-> value : "<<root->Left-> Right-> value<< endl;
   cout<< "Minimum of the tree: "<< findMinFromtheTree(root);
   cout<< endl;
   cout<< "Minimum of the tree: "<< findMaxFromTheTree(root);
   cout<< endl;

   ///searching an element...
   int searchFor;
   cout<< "Enter a number to search...";
   cin>>searchFor;
   int searchResult = searchItem(root, searchFor);
   if(searchResult==1)
   cout<< "The item.." << searchFor<< " is found..";
   else cout<< "The item.."<< searchFor<< "is Not Found...";
   cout<< endl;
   ///deleting a node..
  // root = deleteNode(root,12);
  // cout<< "After deleting 12 The root of the tree is: " <<root->value<<endl;

   ///finding parent...
   cout<< "Parent of 9 is: "<< findParent(root, 9)<<endl;

   ///finding child of a node...
   findChildren(root, 5);
   findChildren(root, 7);

   ///finding sibling of a node...
   findSibling(root, 1);
    ///Finding ancestor...
   cout<< "The ancestors are: "<< findAncestors(root, 13)<<endl;

    ///finding successor...
    findSuccessor(root,15);
    printSuccessor(root,15);

    ///finding predecessor...
   // findPredecessor(root,5);
    printPredecessor(root,5);

return 0;
}

