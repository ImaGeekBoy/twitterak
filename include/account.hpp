#ifndef FB1B2831_6285_463E_9521_8277A9C23E4E
#define FB1B2831_6285_463E_9521_8277A9C23E4E

#include <string>
#include <vector>
#include "../include/tweet.hpp"
#include "../include/twitterak.hpp"

class account
{
    std::string name;
    std::string username;
    std::string biography;
    std::string country;
    std::string link;
    unsigned int birth_day;
    unsigned int birth_month;
    unsigned int birth_year;
    std::string color;
    std::string phone_number;
    std::string password;
    std::vector<tweet*> tweets;

public:
 
    account(std::string);

    void set_name(std::string);
    std::string get_name();

    void set_username(std::string);
    std::string get_username();

    void set_biography(std::string);
    std::string get_biography();

    void set_link(std::string);
    std::string get_link();

    void set_birthday(unsigned int);
    unsigned int get_birthday();

    void set_birthmonth(unsigned int);
    unsigned int get_birthmonth();

    void set_birthyear(unsigned int);
    unsigned int get_birthyear();

    void set_phone_n(std::string);
    std::string get_phone_n();

    void set_password(std::string);
    std::string get_password();

    void set_country(std::string);
    std::string get_country();

    void set_color(std::string);
    std::string get_color();
    
    void set_tweett(tweet*);
    void get_tweett(int, std::string&, int&);
    tweet* which_tweet(int);
    void delete_tweet(int);
    void edit_tweet(int, std::string);
    int get_size_of_tweets();

    void who_liked(std::vector<account*>&, int, int);
    int get_size_of_likes(int);
   

};






    #endif /* FB1B2831_6285_463E_9521_8277A9C23E4E */