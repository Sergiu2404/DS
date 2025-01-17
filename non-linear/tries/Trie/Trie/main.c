#include "Trie.h";


int main() {
    TrieNode* root = create_node();

    insert(root, "hello");
    insert(root, "world");
    insert(root, "helium");

    printf("Search for 'hello': %s\n", search(root, "hello") ? "Found" : "Not Found");
    printf("Search for 'hell': %s\n", search(root, "hell") ? "Found" : "Not Found");

    printf("Prefix 'hel': %s\n", starts_with(root, "hel") ? "Exists" : "Doesn't Exist");
    printf("Prefix 'wo': %s\n", starts_with(root, "wo") ? "Exists" : "Doesn't Exist");
    printf("Prefix 'hey': %s\n", starts_with(root, "hey") ? "Exists" : "Doesn't Exist");

    free_trie(root);

    return 0;
}
