#include <fstream>
#include <iostream>
#include "Trie.h"

Trie::Trie(int alphabet, std::string & fileName) : alphabet_(alphabet)
{
    root = new TrieNode(alphabet_);
    std::ifstream fin(fileName, std::ios_base::in);
    std::string buffer;
    while (true)
    {
        getline(fin, buffer);
        insert(buffer);
        if (fin.eof() == true)
        {
            break;
        }
    }
    fin.close();
}

Trie::~Trie() 
{
    removeAll(root);
}

void Trie::insert(std::string & key)
{
    TrieNode* ptr = root;
    size_t size = key.size();
    for (size_t i = 0; i < size; i++)
    {
        int index = getIndex(key[i]);
        if (index != -1)
        {
            if (ptr->children[index] == nullptr)
            {
                ptr->children[index] = new TrieNode(alphabet_);
            }
            ptr = ptr->children[index];
        }
        else
        {
            ptr = root;
        }
    }
    ptr->isEndOfWord = true;
}

int Trie::getIndex(char ch)
{
    int index = (int)(ch);
    if (index >= 65 && index <= 90)
    {
        index -= 65;
    }
    else if (index >= 97 && index <= 122)
    {
        index -= 97;
    }
    else
    {
        index = -1;
    }
    return index;
}

void Trie::getWords(std::vector<std::string> & words, std::string & word)
{
    setRegister(word);
    size_t size = word.size();
    TrieNode* ptr = root;
    char buf[256];
    int index = 0;
    for (size_t i = 0; i < size; i++)
    {
        int ind = getIndex(word[i]);
        if (ptr->children[ind] != nullptr)
        {
            buf[index] = word[i];
            index++;
            ptr = ptr->children[ind];
        }
        else
        {
            return;
        }
    }
    walk(ptr, buf, index, words);
}

void Trie::walk(TrieNode* root, char* buf, int index, std::vector<std::string> & words)
{
    if (root->isEndOfWord == true)
    {
        std::string input;
        for (size_t i = 0; i < index; i++)
        {
            input.push_back(buf[i]);
        }
        words.push_back(input);
    }
    for (size_t i = 0; i < alphabet_; i++)
    {
        if (root->children[i] != nullptr)
        {
            buf[index] = i + 'a';
            walk(root->children[i], buf, index + 1, words);
        }
    }
}

void Trie::setRegister(std::string & str)
{
    size_t size = str.size();
    for (size_t i = 0; i < size; i++)
    {
        if ((int)str[i] >= 65 && (int)str[i] <= 90)
        {
            int ch = (int)str[i] + 32;
            str[i] = (char)ch;
        }
    }
}

void Trie::removeAll(TrieNode* node)
{
    for (size_t i = 0; i < alphabet_; i++)
    {
        if (node->children[i] != nullptr)
        {
            removeAll(node->children[i]);
        }
    }
    delete node;
    node = nullptr;
}

bool Trie::checkWord(std::string & str)
{
    bool flag = true;
    size_t size = str.size();
    for (size_t i = 0; i < size; i++)
    {
        if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122)
        {
            flag = false;
            break;
        }
    }
    if (flag == true)
    {
        setRegister(str);
    }
    return flag;
}

void Trie::insertStr(std::string & str, std::string & word)
{
    size_t size = word.size();
    for (size_t i = 0; i < size; i++)
    {
        str.push_back(word[i]);
    }
    str.push_back(' ');
}