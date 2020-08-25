#ifndef __MYP_HPP__
#define __MYP_HPP__
#include "C:\MinGW64\opt\include\sqlite3.h"
#include <iostream>

class Whatsapp
{
private:
    std::string Date;
    std::string name;
    std::string time;
    std::string message;
    sqlite3 *db;
    void CreateTable();
    void storeRecord();

public:
    Whatsapp(){};
    void FileToDatabase(const std::string &);
    std::string getname() const;
    std::string getdate() const;
    std::string gettime() const;
    std::string getmessage() const;
    ~Whatsapp(){};
};
#include "MyP.cpp"
#endif // __MYP_HPP__
