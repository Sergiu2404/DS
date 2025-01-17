#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26  // only lowercase english letters

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool is_end_of_word;  // indicates end of a word
} TrieNode;

TrieNode* create_node();

void insert(TrieNode* root, const char* word);

bool search(TrieNode* root, const char* word);

bool starts_with(TrieNode* root, const char* prefix);

void free_trie(TrieNode* root);