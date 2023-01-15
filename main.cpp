#include <iostream>
#include <locale>
#include "Trie.h"
#include "TestingPanel.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    std::string fileName = "dictionary.txt";
    size_t alphabet = 26;
    Trie* tr = new Trie(alphabet, fileName);
    TestingPanel tp(*tr);
    tp.stringSet();
    delete tr;
    return 0;
}