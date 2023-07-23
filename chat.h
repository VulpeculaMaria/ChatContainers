#include<string>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Users
{
    public:
    Users(string login, int pass);
    void delUser(string login);
    ~Users();
    string _login;
    vector<Chat> chats;

    private:
    int _password;
    map<string, int> users;
    bool operator ==(const Users &user)
    {
        if(_login == user._login && _password == user._password)
            return true;
        return false;
    }
};

class Chat
{
    public:
    Chat(){};
    ~Chat(){};
    void AddUser(Users *user, Chat *chat);
    void DelUser(Users* user);
    void AddMessage(Users *from, string text);
    void Registration(string login, int pass);

    private:
    vector<Users> users;
    vector<Message> story;
};

class Message
{
    string _text;
    Users *_from;

    public:
    Message(Users *from, string text):_text(text),_from(from){};
    ~Message();
};