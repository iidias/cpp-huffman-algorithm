#ifndef HUFFMAN_ENGINE_H
#define HUFFMAN_ENGINE_H

#include <string>
#include <map>

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f, Node* l = nullptr, Node* r = nullptr)
        : ch(c), freq(f), left(l), right(r) {}
};

struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void generateCodes(Node* root, std::string str, std::map<char, std::string>& huffmanCode);
void deleteTree(Node* root);

#endif
