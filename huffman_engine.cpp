#include "huffman_engine.h"

using namespace std;

void generateCodes(Node* root, string str, map<char, string>& huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    generateCodes(root->left, str + "0", huffmanCode);
    generateCodes(root->right, str + "1", huffmanCode);
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
