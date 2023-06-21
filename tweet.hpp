#ifndef C0A1063C_D11D_4787_BA8F_9CB108B9FAF7
#define C0A1063C_D11D_4787_BA8F_9CB108B9FAF7

#include <string>
#include <ctime>
#include <vector>
#include <iostream>


class account;

class tweet
{
    std::string text;
    std::vector <account*> likes;
    bool is_public;
    

public:
    tweet(std::string);
    std::string get_text();
    void edit_tweet(std::string);
    void show_tweet(std::string& , int&);

    void set_public(bool);

    void set_like(account*);
    int likes_number();
    account* who_liked_(int);
    void dislike(std::string, std::vector<std::string>);

};


#endif /* C0A1063C_D11D_4787_BA8F_9CB108B9FAF7 */
