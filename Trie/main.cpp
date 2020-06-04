#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

//maximum occuring words in a given set of strings
// A Trie node
struct Trie
{
    // count and key will be set only for leaf nodes
    // key stores the string and count stores its frequency so far
    string key;
    int count = 0;

    // each node stores a map to its child nodes
    unordered_map<char, Trie*> character;
};

// Iterative function to insert a string in Trie
void insert(Trie* const &head, string const &str)
{
    // start from root node
    Trie* curr = head;

    for (char ch: str)
    {
        // create a new node if path doesn't exists
        if (curr->character.find(ch) == curr->character.end()) {
            curr->character[ch] = new Trie();
        }

        // go to next node
        curr = curr->character[ch];
    }

    // store key and its count in leaf nodes
    curr->key = str;
    curr->count += 1;
}

// Function to perform pre-order traversal of given Trie
// and find word with maximum frequency
void preorder(Trie* const curr, int &max_count, string &key)
{
    // base condition
    if (curr == nullptr) {
        return;
    }

    for (auto pair: curr->character)
    {
           // leaf node have non-zero count
         if (max_count < pair.second->count )
         {
             key = pair.second->key;
             max_count = pair.second->count;
         }

         // recur for current node children
        preorder(pair.second, max_count, key);
    }
}

// main function
int main()
{
    // given set of keys
    string dict[] =
    {
        "code", "coder", "coding", "codable", "codec", "codecs", "coded",
        "codeless", "codec", "codecs", "codependence", "codex", "codify",
        "codependents", "codes", "code", "coder", "codesign", "codec",
        "codeveloper", "codrive", "codec", "codecs", "codiscovered"
    };

    // insert all keys into the Trie
    Trie* head = new Trie();
    for (string word: dict) {
        insert(head, word);
    }

    int count = 0;
    string key;

    // perform pre-order traversal of given Trie and find key
    // with maximum frequency
    preorder(head, count, key);

    cout << "Word : " << key   << '\n';
    cout << "Count: " << count << '\n';

    return 0;
}
