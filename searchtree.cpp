#include "searchtree.h"

searchtree::searchtree() : root(NULL), size(0) {

}

searchtree::~searchtree(){
    while(!isempty()){
        remove(root->value);
    }
}

bool searchtree::isempty(){
    return !size;
}

int searchtree::getsize(){
    return size;
}

void searchtree::insert(int newnum){
    if(insert(root, newnum))
        size++;
}

void searchtree::remove(int num) {
    if(remove(root,num ))
        size--;
}

bool searchtree::insert(node *&from, int num){
    if(root==NULL){
        from = new node(num);
        return true;
    }

    if(num < from->value)
        return insert(from->left, num);
    if(num > from->value)
        return insert(from->right, num);
    return false;

}

bool searchtree::remove(node *&from, int num){
    if(from==NULL)
        return false;
    if(num < from->value)
        return remove(from->left, num);
    if(num > from->value)
        return remove(from->right, num);

    if (from->left == NULL || from->right == NULL)
    {
        node *point = from;
        from = from->left == NULL ? from->right : from->left;
        delete point;
        return true;
    }

    node *point=minvalue(from->right);
    from->value = point->value;
    return remove(from->right, from->value);
}

searchtree::node* searchtree::minvalue(node *from){
    if(from->left == NULL)
        return from;
    return minvalue(from->left);
}

int searchtree::find(int num){
    return find(root, num);
}

int searchtree::find(node *from, int num){
    if(from == NULL)
        return -1;
    if(num < from->value)
        return find(from->left, num);
    if(num > from->value)
        return find(from->right, num);
    if(num == from->value)
        return 1;
}

