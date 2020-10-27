#include <bits/stdc++.h>
using namespace std;

struct Trie_Node{
    map < char, struct Trie_Node* > character;
    bool endofword = false ;
    int pass=0;
};

struct Trie_Node root;
void insertWord(string str);
struct Trie_Node* Get_newNode();

int cnt=1;

int main(){
   int n;
   cin>>n;

   string str[n];
   for(int i=0;i<n;i++){
    cin>>str[i];
    insertWord(str[i]);
   }

   cout<<cnt;
}


//Creating New Node
struct Trie_Node * Get_newNode(){
    struct Trie_Node *newNode;
    newNode = new struct Trie_Node;
    newNode->endofword = false ;
    cnt++;
    return newNode;
}



//Inserting on The Trie Tree
void insertWord(string str){
    struct Trie_Node *temp ;
    temp = &root ;

    for(int i=0;i<str.size();i++){
        char ch = str[i];

        if(temp->character.find(ch) == temp->character.end()){
            temp->character[ch];
            temp->character[ch] = Get_newNode();
        }
        temp->pass++;
        temp = temp->character[ch];
    }
    temp->pass++;
    temp->endofword = true;
}
