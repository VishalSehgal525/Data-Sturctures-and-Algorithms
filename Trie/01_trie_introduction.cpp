#include<iostream>
using namespace std;

/*
Operation | Time Complexity | Auxiliary Space
Insertion |      O(n)       |     O(n*m)
Searching |      O(n)       |     O(1)
*/

/*
Alphabet Array => |a|b|c|d|e|f|g|h|i|j|k |l |m |n |o |p |q |r |s |t |u |v |w |x |y |z |
Index =>          |0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17|18|19|20|21|22|23|24|25|
Total Elements => 26 at each node
*/

struct TrieNode
{
    TrieNode *child[26]; // Creating 26 child. [For Alphabet Array]
    bool isEnd; // Checking if it is the end of word.
    // Initializing an empty Node
    TrieNode()
    {
        isEnd = false;
        for(int i = 0; i<26; i++)
            child[i] = NULL;
    }
};

// Insertion in a Trie
void Insert(TrieNode *root, string key)
{
    TrieNode *curr = root;
    for(int i = 0; i<key.length(); i++) // Loop will iterate on the string
    {
        int index = key[i] - 'a';   // Index will iterate on the alphabet array.
        // Check if curr element's particular child has a root node or not? This is checked for example take it for words "trie" and "tree". So when tree is inserted node for t and r are already created.
        if(curr->child[index] == NULL) 
            curr->child[index] = new TrieNode();
        // Iterate to the next node
        curr = curr->child[index];
    }
    curr->isEnd = true;
}

// Searching in a Trie
bool search(TrieNode *root, string key)
{
    TrieNode *curr = root;
    for(int i = 0; i<key.length(); i++)
    {
        int index = key[i] - 'a';
        // For example in trie containing words ['the', 'a', 'an'] and we search for 'gantu' g's node is already empty and full word cannot be spanned. So we return false at instant.
        if(curr->child[index]==NULL)
            return false;
        curr = curr->child[index];
    }
    // We check for 'the' in trie, we find if 't' is a word or not. Node exists for 't' but it is not a word.
    return curr->isEnd;
}

// Used to check whether the node is empty or not.
bool isEmpty(TrieNode *root)
{
    for(int i = 0; i<26; i++)
        if(root->child[i]!=NULL)
            return false;
    return true;
}

// Deleting a string from the trie data structure
TrieNode *delKey(TrieNode *root, string key, int i)
{
    if(root == NULL) return NULL;
    if(i==key.length()) 
    {
        root->isEnd = false;
        if(isEmpty(root) == true)
        {
            delete(root);
            root = NULL;
        }
        return root;
    }
    int index = key[i] - 'a';
    root->child[index] = delKey(root->child[index], key, i+1);
    if(isEmpty(root) && root->isEnd == false)
    {
        delete(root);
        root = NULL;
    }
    return root;
}

int main()
{
    TrieNode *root;
    root = new TrieNode();
    Insert(root, "hello");
    Insert(root, "hi");
    Insert(root, "hemlo");
    Insert(root, "love");
    Insert(root, "lovely");
    Insert(root, "gantu");
    Insert(root, "bkl");
    cout<<search(root, "love")<<endl;
    cout<<search(root, "gantubkl")<<endl;
    cout<<delKey(root, "love", 0)<<endl;
    cout<<search(root, "love")<<endl;
    cout<<search(root, "lovely")<<endl;
    return 0;
}