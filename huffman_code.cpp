#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void printCodes(Node* root, string str, unordered_map<char, string>& codes) {
    if (!root) return;

    if (!root->left && !root->right) {
        codes[root->ch] = str;
        cout << root->ch << ": " << str << "\n";
    }

    printCodes(root->left, str + "0", codes);
    printCodes(root->right, str + "1", codes);
}

void HuffmanCoding(char chars[], int freq[], int n) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for (int i = 0; i < n; i++) {
        minHeap.push(new Node(chars[i], freq[i]));
    }

    while (minHeap.size() != 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    unordered_map<char, string> codes;
    printCodes(minHeap.top(), "", codes);

    int totalBits = 0;
    for (int i = 0; i < n; i++) {
        totalBits += freq[i] * codes[chars[i]].size();
    }
    cout << "\nTotal encoded size = " << totalBits << " bits\n";
    cout << " = " << totalBits / 8.0 << " bytes\n";
}

int main() {

    char chars[] = {'a','c','d','e','o','m','s','t','u'};
    int freq[]  = {2000,1100,200,1000,1500,800,1000,2200,200};
    int n = sizeof(chars) / sizeof(chars[0]);

    HuffmanCoding(chars, freq, n);
    return 0;
}
