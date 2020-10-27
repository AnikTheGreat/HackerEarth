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
int FindWords(string str);

int main(){
    int n;
    cin>>n;

    string str[2];
    for(int i=0;i<n;i++){
        cin>>str[0];
        cin>>str[1];

        if(str[0]=="add"){
            insertWord(str[1]);
        }
        if(str[0]=="find"){
            int c = FindWords(str[1]);
            cout<<c<<endl;
        }
    }
}

int FindWords(string str){
    struct Trie_Node *temp;
    temp = &root ;

    for(int i=0;i<str.size();i++){
        if(temp->character.find(str[i]) != temp->character.end()){
            temp = temp->character[str[i]];
        }
        else{
            return 0;
        }
    }

    return temp->pass;
}


//Creating New Node
struct Trie_Node * Get_newNode(){
    struct Trie_Node *newNode;
    newNode = new struct Trie_Node;
    newNode->endofword = false ;
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

