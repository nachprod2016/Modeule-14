#pragma once
#include <string>
  
// Структура узела дерева 
struct TrieNode
{ 
    TrieNode ** children;
    bool isEndOfWord;

    TrieNode(int alphabet_);
    ~TrieNode();
};