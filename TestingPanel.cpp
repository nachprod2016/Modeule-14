#include "TestingPanel.h"
#include <iostream>
#include <cstdlib>

TestingPanel::TestingPanel(Trie & tr) : tr(tr) {}

TestingPanel::~TestingPanel(){}

void TestingPanel::stringSet()
{
    std::string prefix;
    std::string choice;
    while (true)
    {
        std::cout << "1 - Искать слово" << std::endl;
        std::cout << "2 - Выйти из программы" << std::endl;
        std::cin >> choice;
        if (choice == "1")
        {
            std::vector<std::string> words;
            std::cout << "Введите префикс или слово целиком: ";
            std::cin >> prefix;
            if (tr.checkWord(prefix) == false)
            {
                continue;
            }
            tr.getWords(words, prefix);
            size_t size = words.size();
            if (size == 0)
            {
                continue;
            }
            for (size_t i = 0; i < size; i++)
            {
                std::cout << i << " - " << words[i] << std::endl; 
            }
            std::cout << "Выбрать слово из списка?" << std::endl;
            std::cout << "1 - Да" << std::endl;
            std::cout << "2 - Нет" << std::endl;
            std::cin >> choice;
            if (choice == "1")
            {
                size_t index;
                std::cout << "Введите номер слова из списка: ";
                std::cin >> choice;
                if (choice == "0")
                {
                    index = 0;
                }
                else
                {
                    index = atoi(&choice[0]);
                    if (index == 0 || index > words.size())
                    {
                        index = -1;
                    }
                }
                if (index != -1)
                {
                    tr.insertStr(str, words[index]);   
                }
            }
            else if (choice == "2")
            {
                tr.insertStr(str, prefix);
            }
            std::cout << "Строка: " << str << std::endl;
        }
        else if (choice == "2")
        {
            break;
        }
    }
}