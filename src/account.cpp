#include "../include/account.hpp"

    extern twitterak game;

    account::account(std::string m)
    {
        this -> username = m;
    }

    void account::set_name(std::string x)
    {
        name = x;
    }
    std::string account::get_name()
    {
        return name;
    }

    void account::set_username(std::string x)
    {
        username = x;
    }
    std::string account::get_username()
    {
        return username;
    }

    void account::set_biography(std::string x)
    {
        biography = x;
    }
    std::string account::get_biography()
    {
        return biography;
    }

    void account::set_link(std::string x)
    {
        link = x;
    }
    std::string account::get_link()
    {
        return link;
    }

    void account::set_birthday(unsigned int x)
    {
        birth_day = x;
    }
    unsigned int account::get_birthday()
    {
        return birth_day;
    }

    void account::set_birthmonth(unsigned int x)
    {
        birth_month = x;
    }
    unsigned int account::get_birthmonth()
    {
        return birth_month;
    }

    void account::set_birthyear(unsigned int x)
    {
        birth_year = x;
    }
    unsigned int account::get_birthyear()
    {
        return birth_year;
    }

    void account::set_phone_n(std::string x)
    {
        phone_number = x;
    }
    std::string account::get_phone_n()
    {
        return phone_number;
    }

    void account::set_password(std::string x)
    {
        password = x;
    }
    std::string account::get_password()
    {
        return password;
    }

    void account::set_country( std::string x )
    {
        country = x;
    }
    std::string account::get_country()
    {
        return country;
    }


    void account::set_color( std::string x )
    {
        color = x;
    }
    std::string account::get_color()
    {
        return color;
    }
    

    void account::set_tweett(tweet* x)
    {
        tweets.push_back(x);
    }
    void account::get_tweett(int index, std::string& text, int& likes)
    {
        tweets[index]->show_tweet(text, likes);
    }
    tweet* account::which_tweet(int index)
    {
        return tweets[index];
    }
    void account::delete_tweet(int index)
    {
        tweets.erase(tweets.begin() + index);
    }
    void account::edit_tweet(int index, std::string text)
    {
        tweets[index]->edit_tweet(text);
    }
    int account::get_size_of_tweets()
    {
        return tweets.size();
    }

    void account::who_liked(std::vector<account *>& vec, int howmany, int index)
    {
        for ( int i = 0; i < howmany; i++ )
        {
            vec.push_back(tweets[index]->who_liked_(i));
        }
    }
    int account::get_size_of_likes(int i)
    {
        return tweets[i]->likes_number();
    }
