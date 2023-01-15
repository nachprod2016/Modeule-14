#pragma once
#include <vector>
#include <string>
#include "TrieNode.h"

class Trie
{
private:
    size_t alphabet_;
    TrieNode* root;
    void removeAll(TrieNode* node);
    void walk(TrieNode* root, char* buf, int index, std::vector<std::string> & words);
public:
    Trie(int alphabet, std::string & fileName);
    ~Trie();
    void insert(std::string & key);
    int getIndex(char ch);
    void getWords(std::vector<std::string> & words, std::string & word);
    void setRegister(std::string & str);
    bool checkWord(std::string & str);
    void insertStr(std::string & str, std::string & word);
};