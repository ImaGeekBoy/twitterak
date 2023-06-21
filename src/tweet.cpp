#include "../include/tweet.hpp"


    tweet::tweet(std::string m)
    {
        this -> text = m;
    }
    std::string tweet::get_text()
    {        
        return text;
    }
    void tweet::edit_tweet(std::string newtext)
    {
        text = newtext;
    }
    void tweet::show_tweet(std::string& text, int& likes)
    {
        text = get_text();
        likes = likes_number();
    }
    

    void tweet::set_like(account* x)
    {
        likes.push_back(x);
    }
    int tweet::likes_number()
    {
        return likes.size();
    }
    account* tweet::who_liked_(int index)
    {
        return likes[index];
    }
    void tweet::dislike(std::string requester, std::vector<std::string> others)
    {
        for (unsigned int i = 0; i < likes.size(); i++)
        {
            if ( others[i] == requester )
            {
                likes.erase(likes.begin() + i);
            }
        }
    }