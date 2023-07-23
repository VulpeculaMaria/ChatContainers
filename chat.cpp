#include"chat.h"
#include<algorithm>
#include<iterator>

Users::Users(string login, int pass):_login(login),_password(pass)
{
    users.insert(pair<string,int>(login,pass));
}

void Users::delUser(string login)
{
    users.erase(login);
}

Users::~Users()
{
    users.clear();
}

void Chat::AddUser(Users *user, Chat *chat)
{
    users.push_back(*user);
    user->chats.emplace_back(chat);
    cout << "User was added:" << user->_login <<endl;
}

void Chat::DelUser(Users* user)
{
    vector<Users>::iterator it = find(users.begin(), users.end(), user);
    users.erase(it);
    cout << "User was deleted:" << user->_login << endl;
}

void Chat::AddMessage(Users *from, string text)
{
    Message txt(from, text);
    story.push_back(txt);
    cout << from->_login << ":" << text << endl;
}
