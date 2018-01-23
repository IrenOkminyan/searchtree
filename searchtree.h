#include <iostream>
#include <string>
using namespace std;

class searchtree {

public:
    searchtree();
    ~searchtree();

    bool isempty();
    int getsize();

    void insert(int newnum);
    void remove(int  num);
    int find(int num);




private:
    struct node{
        int value;
        node *left, *right;
        node(int num) : value(num), left(NULL), right(NULL){};
    };

    node *root;
    int size;

    bool insert(node *&from, int num);
    bool remove(node *&from, int num);
    int find(node *from, int num);
    node* minvalue(node *from);
};