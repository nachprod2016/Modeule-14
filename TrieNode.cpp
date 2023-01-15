#include "TrieNode.h"

TrieNode::TrieNode(int alphabet)
{
    children = new TrieNode*[alphabet];
    for (int i = 0; i < alphabet; i++)
    {
        children[i] = nullptr;
    }
    isEndOfWord = false;
}

TrieNode::~TrieNode()
{
    delete [] children;
}