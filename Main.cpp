#include <bits/stdc++.h>
#include "MyP.hpp"

int main()
{

    int Option;
    std::cout << "Enter 1 to Store chat data in Database(1 Time Operation)\nEnter 2 to search from Message(Select this if your chat"
                 "data is stored in DB)";
    std::cin >> Option;
    if (Option == 1)
    {
        std::string FileName;
        std::cout << "Enter File Name Where Chat is Stored(With Extension)" << std::endl;
        Whatsapp Chat;
        Chat.FileToDatabase(FileName);
    }
    else if (Option == 2)
    {
        std::string Search;
        std::cout << "What to Search";
        std::cin >> Search;
        Searchmessage(Search);
    }
    else
        throw std::invalid_argument("Wrong Choice\n");
}
