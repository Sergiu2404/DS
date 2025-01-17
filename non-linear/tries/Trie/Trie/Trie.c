#include "Trie.h";

TrieNode* create_node() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->is_end_of_word = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(TrieNode* root, const char* word) {
    TrieNode* node = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';  // map 'a' to 0, 'b' to 1, ..., 'z' to 25
        if (node->children[index] == NULL) {
            node->children[index] = create_node();
        }
        node = node->children[index];
    }
    node->is_end_of_word = true;
}

// search for a word in the trie
bool search(TrieNode* root, const char* word) {
    TrieNode* node = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (node->children[index] == NULL) {
            return false;
        }
        node = node->children[index];
    }
    return node != NULL && node->is_end_of_word;
}

// check for any word in the trie that starts with the given prefix
bool starts_with(TrieNode* root, const char* prefix) {
    TrieNode* node = root;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';
        if (node->children[index] == NULL) {
            return false;
        }
        node = node->children[index];
    }
    return true;
}

void free_trie(TrieNode* root) {
    if (root == NULL) return;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        free_trie(root->children[i]);
    }
    free(root);
}