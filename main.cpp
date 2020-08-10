#include <iostream>
#include <vector>
#include <fstream>
//#include "tree.hh"
#include <bits/stdc++.h>

using namespace std;

struct Node {
    //contains a char
    char data;

    //how often char occurs
    int freq;

    //children nodes
    Node *left , *right;
};
void encryptionTraversal(Node* root, string key, unordered_map<char,string> &hCode){
if(root == nullptr){
    return;
    }
//encountering a leaf node
if(!root->left && !root->right){
    hCode[root->data] = key;
}
//if you traverse left node add 0
encryptionTraversal(root->left, key + "0", hCode);
//if you traverse right node add 1
encryptionTraversal(root->right, key + "1", hCode);

}

void decryptionTraversal(Node* root, int &count, string key){
    if (root == nullptr) {
        return;
    }
    // found a leaf node
    if (!root->left && !root->right)
    {
        cout << root->data;
        return;
    }

    count++;

    if (key[count] =='0') {
        decryptionTraversal(root->left, count, key);
    }
    else{
        decryptionTraversal(root->right, count, key);
    }

}

struct comp{
    bool operator()(Node* l, Node* r){
        return l->freq > r->freq;
    }
};


void Compress(vector <char> ls){
    unordered_map<char,int> mp;
    //find all chars from array map them with their frequencies
    for(char c : ls){
        mp[c]++;
    }
    priority_queue<Node*, vector<Node*>,comp> prioQ;
    //iterate through each map value and assign it to a node
    for(auto it: mp){
        Node* temp;
        temp->freq = it.second;
        temp->data = it.first;
        prioQ.push(temp);
    }
    //pull lowest 2 nodes from prioQ and create new node
    while(prioQ.size() != 1){
        Node* left = prioQ.top();
        //remove after
        prioQ.pop();
        Node* right = prioQ.top();
        prioQ.pop();
        Node* combinedNode;
        //assign new freq by summing the two individual node freq
        combinedNode->freq = left->freq + right->freq;
        //keep left and right connected to combined node
        combinedNode->left = left;
        combinedNode->right = right;
        prioQ.push(combinedNode);
    }

    Node* root = prioQ.top();
    unordered_map<char,string> hCode;
    encryptionTraversal(root,"",hCode);

    //output huffman code
    for(auto it : hCode){
        cout << it.first << " " << it.second << endl;
    }
    cout << endl << endl << endl;

}


int main() {

    //feed in text file into a vector
    vector <char> ls;
    ifstream inpF("C:/Users/Bomin/CLionProjects/HuffmanEncode/Ishmael");
    if(!inpF){
        cout << "error, empty or corrupted file" << endl;
        return -1;
    }

    string contents((std::istreambuf_iterator<char>(inpF)),
                         std::istreambuf_iterator<char>()); //capture entire file into string


    //apply huffman algorithm to it
    //Compress(ls);
    Compress(ls);
    //output compressed version into new text
    return 0;
}
