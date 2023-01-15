#pragma once
#include "Trie.h"

class TestingPanel
{
private:
    Trie & tr;
    std::string str;
public:
    TestingPanel(Trie & tr);
    ~TestingPanel();
    void stringSet();
};