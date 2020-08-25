#include "bits/stdc++.h"
#include "C:\MinGW64\opt\include\sqlite3.h"
#define whatsappargs std::string Date, std::string time, std::string name, std::string message
#include "MyP.hpp"
int callback(void *ptr, int Ccount, char **Cvalue, char **Cname)
{
    std::cout << (const char *)ptr;
    for (int i = 0; i < Ccount; ++i)
    {
        std::cout << Cvalue[i];
    }
    std::cout << "\n";
    return 0;
}
void Whatsapp::FileToDatabase(const std::string &ChatFileName)
{
    std::string t;
    sqlite3_open("MyWhatsapp.db", &db);
    CreateTable();
    std::ifstream chat(ChatFileName);
    while (getline(chat, this->Date, ','))
    {
        chat.seekg(chat.tellg() + 1);
        getline(chat, t, '-');
        this->time = t.substr(0, t.length() - 1);
        chat.seekg(chat.tellg() + 1);
        getline(chat, this->name, ':');
        chat.seekg(chat.tellg() + 1);
        getline(chat, this->message);
        storeRecord();
    }
    chat.close();
    sqlite3_close(db);
}
std::string Whatsapp::getname() const { return name; }
std::string Whatsapp::getdate() const { return Date; }
std::string Whatsapp::gettime() const { return time; }
std::string Whatsapp::getmessage() const { return message; }

void Searchmessage(const std::string &Text)
{
    sqlite3 *db;
    sqlite3_open("MyWhatsapp.db", &db);
    char *Err = 0;
    char *check = "Call Back Called";
    const std::string Searchcmd = "Select name,message from WhatsappData"
                                  " WHERE Message Like '%" +
                                  Text + "%';";
    if (!sqlite3_exec(db, Searchcmd.c_str(), callback, (void *)check, &Err))
    {
        std::cout << "Searched";
    }
    else
    {
        std::cout << "Error Occured" << Err;
    }
    sqlite3_close(db);
}

void Whatsapp::CreateTable()
{
    std::string createtable = "Create Table IF NOT EXIST WhatsappData( Date TEXT Not Null , Time Text Not Null,"
                              "Name Text Not Null , Message Text Not Null);";
    char *Err;
    if (!sqlite3_exec(db, createtable.c_str(), nullptr, nullptr, &Err))
    {
        std::cout << "Table Created Successfully Name: WhatsappData";
    }
    else
    {
        std::cout << "Error Occured" << Err;
    }
}
void Whatsapp::storeRecord()
{
    std::string InsertQueries = "Insert Into WhatsappData(Date , Time , Name , Message)"
                                "Values('" +
                                Date + "','" + time + "','" + name + "','" + message + "');";

    char *Err;
    if (!sqlite3_exec(db, InsertQueries.c_str(), nullptr, nullptr, &Err))
    {
        std::cout << "QueryInserted";
    }
    else
    {
        std::cout << "Error Occured" << Err;
    }
}
