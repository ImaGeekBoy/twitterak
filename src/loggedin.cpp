#include "../include/loggedin.hpp"
#include "../include/menu.hpp"
#include "../include/edit.hpp"
#include "../include/twitterak.hpp"
#include "../include/stringtolower.hpp"

#include <iostream>
#include <algorithm>
#include <windows.h>

extern twitterak game;



void loggedin(account *user)
{
    Sleep(2000);
    bool running = true;
    std::string order;
    std::cout << std::endl <<"***Twitterak***" << std::endl;
    std::cout << "1- Tweet " << std::endl;
    std::cout << "2- Logout " << std::endl;
    std::cout << "3- Exit " << std::endl;
    order = takeOrder(user);  
    std::string lowered_order = to_lower(order, false); 

    {   // number commands
        if ( order[0] == '1')
        {
            tweet_here(user);
        }
        else if ( order[0] == '2')
        {
            menu();
        }
        else if ( order[0] == '3' || order[0] == 'q' || order[0] == 'Q' )
        {
            exit(0);
        }
    }

        { // delete tweet
        std::string todelete;
        std::string lowertodelete;

        std::string str1 = "delete tweet";
        size_t found = lowered_order.find(str1);
    
        if ( found != std::string::npos )
        {
            int index;
            order.erase(remove_if(order.begin(), order.end(), isspace), order.end());
            order.erase(found, found+11);
            try 
            {
                index = stoi(order);
            }
            catch(std::invalid_argument& e)
            {
                std::cout << "you should enter number of a tweet to delete it.";
                loggedin(user);
            }
            if ( user->get_size_of_tweets() == 0 )
            {
                std::cout << "You have no Tweets yet." << std::endl;
                loggedin(user);
            }
            else if ( index > user->get_size_of_tweets() )
            {
                if ( user->get_size_of_tweets() == 1 )
                {
                    std::cout << "You have only 1 Tweet." << std::endl;
                    loggedin(user);
                }
                else 
                {
                    std::cout << "You have only " << user->get_size_of_tweets() << " Tweets." << std::endl;
                    loggedin(user);
                }
            }
            else
            {
                int likes;
                std::string text;
                user->get_tweett(index-1, text, likes);
                std::cout << "you're going to delete this tweet: " << std::endl;
                std::cout << text << std::endl << "which liked by " << likes << " people."<< std::endl;
                std::cout << "you sure? (yes/no) ---->";
                getline(std::cin, todelete);
                lowertodelete = to_lower(todelete, true);
                if ( lowertodelete == "y" || lowertodelete == "yes" )
                {
                    user->delete_tweet(index-1);
                    std::cout << "Tweet deleted successfully. " << std::endl;
                    loggedin(user);
                }
                else if ( lowertodelete == "n" || lowertodelete == "no" )
                {
                    std::cout << "ok then" << std::endl;
                    loggedin(user);
                }
                else
                {
                    std::cout << "undefined order" << std::endl;
                    loggedin(user);
                }
            }
        }
    }

    { // edit tweet
        std::string toedit;
        std::string str1 = "edit tweet";
        size_t found = lowered_order.find(str1);
    
        if ( found != std::string::npos )
        {
            int index;
            order.erase(remove_if(order.begin(), order.end(), isspace), order.end());
            order.erase(found, found+9);
            try 
            {
                index = stoi(order);
            }
            catch(std::invalid_argument& e)
            {
                std::cout << "you should enter number of a tweet to edit it.";
                loggedin(user);
            }
            if ( user->get_size_of_tweets() == 0 )
            {
                std::cout << "You no Tweets yet." << std::endl;
                loggedin(user);
            }
            else if ( index > user->get_size_of_tweets() )
            {
                if ( user->get_size_of_tweets() == 1 )
                {
                    std::cout << "You have only 1 Tweet." << std::endl;
                    loggedin(user);
                }
                else 
                {
                    std::cout << "You have only " << user->get_size_of_tweets() << " Tweets." << std::endl;
                    loggedin(user);
                }
            }
            else
            {
                int likes;
                std::string text;
                user->get_tweett(index-1, text, likes);
                std::cout << index << "- " << text << std::endl;
                std::cout << "Enter the new text for tweet " << index <<  " ---->";
                getline(std::cin, toedit);
                if ( toedit.empty() )
                {
                    std::cout << "Tweet can't be empty." << std::endl;
                    loggedin(user);
                }
                else if ( toedit.size() > 280 )
                {
                    std::cout << "Tweet cant be longer then 280 Characters." << std::endl;
                    loggedin(user);
                }
                else
                {
                    user->edit_tweet(index-1, toedit);
                    std::cout << index << "- " << toedit << std::endl;
                    std::cout << "Tweet edited successfully" << std::endl;
                    loggedin(user);
                }
            }
        }
    }


    { // tweet
        std::string str1 = "tweet";
        
        size_t found = lowered_order.find(str1);
        if (found != std::string::npos )
        {
            order.erase(found, found + 5);
            if ( order[0] == ' ')
            {
                order.erase(remove(order.begin(), order.begin() + 1, ' '));
            }
            if ( order.empty() == true )
            {
                std::cout << "Tweet can't be empty" << std::endl;
                loggedin(user);
            }
            else if ( order.size() > 280 )
            {
                std::cout << "Tweet cant be longer then 280 Characters." << std::endl;
                loggedin(user);
            }
            else
            {
            tweet *newtweet = new tweet(order);
            user->set_tweett(newtweet);
            std::cout << "Tweeted successfully" << std::endl;
            loggedin(user);
            }
        }
    }

    { // edit
        std::string str1 = "edit profile";

        size_t found = lowered_order.find(str1);
        if ( found != std::string::npos )
        {
            order.erase(found, found + 12);
            size_t found2 = lowered_order.find('"');
            if ( found2 != std::string::npos )
            {
                order.erase(remove(order.begin(), order.end(), '"'));
                order.erase(remove(order.begin(), order.end(), '"'));
            }
            edit(user, order);
            loggedin(user);
        }
    }

    { // logout
        std::string str1 = "logout";
        size_t found = lowered_order.find(str1);
        if ( found != std::string::npos )
        {
            menu();
        }
    }


    { // exit
        std::string str1 = "exit";
        std::string str2 = "quit";

        size_t found = lowered_order.find(str1);
        if (found != std::string::npos )
        {
            exit(0);
        }
        found = lowered_order.find(str2);
        if (found != std::string::npos)
        {
            exit(0);
        }
    }    
    
    { // delete account

        std::string todelete;
        std::string lowertodelete;

        std::string str1 = "delete account";
        size_t found = lowered_order.find(str1);
        if ( found != std::string::npos )
        {
            std::cout << "you're going to delete your account." << std::endl;
            std::cout << "you sure? (yes/no) ---->";
            getline(std::cin, todelete);
            lowertodelete = to_lower(todelete, true);
            if ( lowertodelete == "y" || lowertodelete == "yes" )
            {
                std::cout << user->get_username() << " account deleted."<< std::endl;
                game.deleteuser(user->get_username());
            }
            else if ( lowertodelete == "n" || lowertodelete == "no" )
            {
                std::cout << "ok then" << std::endl;
                loggedin(user);
            }
            else
            {
                std::cout << "undefined order" << std::endl;
                loggedin(user);
            }
        }
    }


    { // to call show tweets and likes
        std::string str = to_lower(order, true);
        if ( str[0] == '@' )
        {
            size_t found = str.find(":");
            if ( found != std::string::npos ) 
            {   
                int index;
                size_t found2 = str.find("likes");
                if ( found2 != std::string::npos ) 
                {
                    std::string username;
                    username.insert(0, str, 0, found);
                    str.erase(0, found+1);
                    try 
                    {
                        index = stoi(str);
                    }
                    catch(std::invalid_argument& e)
                    {
                        std::cout << "you should enter number of a tweet to show its likes." << std::endl;
                        loggedin(user);
                    }
                    showlikes(username, index, user);
                    loggedin(user);
                }
                else
                {
                    std::string username;
                    username.insert(0, str, 0, found);
                    str.erase(0, found+1);
                    try 
                    {
                        index = stoi(str);
                    }
                    catch(std::invalid_argument& e)
                    {
                        std::cout << "you should enter number of a tweet to show it." << std::endl;
                        loggedin(user);
                    }
                    showtweets(username, index, user);
                    loggedin(user);
                }
            }
            else 
            {
                if ( order == "@me" )
                {
                    str = user->get_username();
                }
                showtweets(str , 0, user);
                loggedin(user);
            }
        }
    }    

    { // like and dislike 
        std::string str1 = "dislike";
        std::string str2 = "like";

        size_t found = lowered_order.find(str1);
        size_t found2 = lowered_order.find(str2); 
        if ( found != std::string::npos ) 
        {
            order.erase(found, found + 7);
            order.erase(remove_if(order.begin(), order.end(), isspace), order.end());
            forlikeanddis(order, false, user);
            loggedin(user);
        }
        else if ( found2 != std::string::npos )
        {
            order.erase(found2, found2 + 4);
            order.erase(remove_if(order.begin(), order.end(), isspace), order.end());
            forlikeanddis(order, true, user);
            loggedin(user);
        }
        
    }


    { // show profiles
        std::string str1 = "me";
        std::string str2 = "profile";

        size_t found = lowered_order.find(str1);
        size_t found2 = lowered_order.find(str2); 
        if ( found != std::string::npos ) 
        {
            order.erase(found, found + 2);
            game.show_info(user->get_username(), user);
            loggedin(user);
        }
        else if ( found2 != std::string::npos )
        {
            order.erase(found2, found2 + 7);
            order.erase(remove_if(order.begin(), order.end(), isspace), order.end());
            if ( order[0] != '@' )
            {
                order.insert( order.begin(), '@');
            }
            game.show_info(order, user);
            loggedin(user);
        }
        else
        {
            std::cout << "undefined order." << std::endl;
            std::cout << "you can get back to menu main and read manuals." << std::endl;
            loggedin(user);
        }

    }
        

}
 

std::string takeOrder(account *account)
{
    std::string order;
    std::cout << account->get_username() << " >";
    fflush(stdin);
    std::getline(std::cin, order);
    fflush(stdin);
    return order;
}



void tweet_here(account *user)
{
    std::string order;

    std::cout << "write here what you want to tweet" << std::endl;
    order = takeOrder(user);
    if ( order[0] == ' ')
    {
        order.erase(remove(order.begin(), order.begin() + 1, ' '));
    }
    if ( order.empty() == true )
    {
        std::cout << "Tweet can't be empty" << std::endl;
        loggedin(user);
    }
    tweet *newtweet = new tweet(order);
    user->set_tweett(newtweet);
    loggedin(user);
}


int showtweets(std::string order, int index,  account *requester)
{
    account *userhere = game.which_account(order);
    if ( userhere == nullptr )
    {
        std::cout << "User not found" << std::endl;
        return -1;
    }
    
    if ( userhere->get_size_of_tweets() == 0 )
    {
        if ( userhere->get_username() == requester->get_username() )
        {
            std::cout << "You have no Tweets yet." << std::endl;
            return 0;
        }
        else
        {
            std::cout << userhere->get_username() << " has no Tweets yet." << std::endl;
            return 0;
        }
    }
    else if ( userhere->get_size_of_tweets() < index )
    {
        if ( userhere->get_username() == requester->get_username() )
        {
            if ( requester->get_size_of_tweets() == 1 )
                {
                    std::cout << "You have only 1 Tweet." << std::endl;
                    return 0;
                }
                else 
                {
                    std::cout << "You have only " << requester->get_size_of_tweets() << " Tweets." << std::endl;
                    return 0;
                }
        }
        else
        {
            if ( userhere->get_size_of_tweets() == 1 )
            {
                std::cout << userhere->get_username() << " has only 1 Tweet." << std::endl;
                return 0;
            }
            else 
            {
                std::cout << userhere->get_username() << " has only " << userhere->get_size_of_tweets();
                std::cout << " Tweets." << std::endl;
                return 0;
            }
        }
    }
    if ( index == 0 )
    {
        std::cout << std::endl << "\t" << userhere->get_username();
        for (int i = 1; i <= userhere->get_size_of_tweets() ; i++)
        {
            std::string text ={};
            int likes = 0;
            userhere->get_tweett(i-1, text, likes);
            std::cout << std::endl << i << ": "  << text << std::endl;
            std::cout << "likes: " << likes << std::endl;
        }
    }
    else if ( index != 0 )
    {
        std::cout << "\t" << userhere->get_username();
        std::string text ={};
        int likes = 0;
        userhere->get_tweett(index-1, text, likes);
        std::cout << std::endl << index << ": "  << text << std::endl;
        std::cout << "likes: " << likes << std::endl;
    }
    return 0;
}


int showlikes(std::string order, int index, account *requester)
{

    account *userhere = game.which_account(order);
    if ( userhere == nullptr )
    {
        std::cout << "User not found." << std::endl;
        return -1;
    }
    if ( userhere->get_size_of_tweets() == 0 )
    {
        if ( userhere->get_username() == requester->get_username() )
        {
            std::cout << "You have no Tweets yet." << std::endl;
            return 0;
        }
        else
        {
            std::cout << userhere->get_username() << " has no Tweets yet." << std::endl;
            return 0;
        }
    }
    else if ( userhere->get_size_of_tweets() < index )
    {
        if ( userhere->get_username() == requester->get_username() )
        {
            if ( requester->get_size_of_tweets() == 1 )
                {
                    std::cout << "You have only 1 Tweet." << std::endl;
                    return 0;
                }
                else 
                {
                    std::cout << "You have only " << requester->get_size_of_tweets() << " Tweets." << std::endl;
                    return 0;
                }
        }
        else
        {
            if ( userhere->get_size_of_tweets() == 1 )
            {
                std::cout << userhere->get_username() << " has only 1 Tweet." << std::endl;
                return 0;
            }
            else 
            {
                std::cout << userhere->get_username() << " has only " << userhere->get_size_of_tweets();
                std::cout << " Tweets." << std::endl;
                return 0;
            }
        }
    }


    if ( userhere->get_size_of_likes(index-1) == 0 )
    {
        std::cout << "This Tweet has no likes yet." << std::endl;
        return 0;
    }
    else 
    {
        std::string text ={};
        int likes = 0;
        userhere->get_tweett(index-1, text, likes);
        std::vector <account*> likers = {};
        userhere->who_liked(likers, userhere->get_size_of_likes(index-1), index-1);

        std::cout << text << " by " << userhere->get_username() << " liked by :" << std::endl;
        for ( int i = 1; i <= userhere->get_size_of_likes(index-1) ; i++ )
        {
            std::cout << i << "- " << likers[i-1]->get_username() << std::endl;
        }
    }
    return 0;
}

int forlikeanddis(std::string x, bool liking, account* requester)
{
    std::vector<account*> likers;
    account *userhere;
    tweet* tweethere;
    std::string username;
    int index;
    size_t found = x.find(":");
    username.insert(0, x, 0, found);
    x.erase(0, found+1);
    try 
    {
        index = stoi(x);
    }
    catch(std::invalid_argument& e)
    {
        std::cout << "You should enter number of a Tweet." << std::endl;
        return 0;
    }
    userhere = game.which_account(username);
    if ( userhere == nullptr )
    {
        std::cout << "User not found." << std::endl;
        return -1;
    }
    if( index < 1 )
    {
        std::cout << "Tweets started form number 1." << std::endl;
        return 0;
    }
    if ( index > userhere->get_size_of_tweets() )
    {
        std::cout << "User has only " << userhere->get_size_of_tweets() << " Tweets." << std::endl;
        return 0;
    }
    else
    {
        tweethere = userhere->which_tweet(index-1);
        for (int i = 0; i < userhere->get_size_of_likes(index-1); i++)
        {
            likers.push_back(tweethere->who_liked_(i));
        }
        
    }


    if ( liking == true ) 
    {
        if ( userhere->get_size_of_likes(index-1) == 0 )
        {
            tweethere->set_like(requester);
            std::cout << "Tweet liked succesfully." << std::endl;
            return 0;
        }
        else
        {
            for (int i = 0; i < userhere->get_size_of_likes(index-1); i++)
            {
                if ( userhere->get_username() == likers[i]->get_username() )
                {
                    std::cout << "You've already liked this post." << std::endl;
                    return 0;
                }
                else
                {
                    tweethere->set_like(requester);
                    std::cout << "Tweet liked succesfully." << std::endl;
                    return 0;
                }
            }
        } 
    }
    else if ( liking == false ) 
    {
        if ( userhere->get_size_of_likes(index-1) == 0 ) 
        {
            std::cout << "This Tweet has no likes." << std::endl;
            return 0;
        }
        else
        {
            for (int i = 0; i < userhere->get_size_of_likes(index-1); i++)
            {
                if ( requester->get_username() == likers[i]->get_username() )
                {   
                    std::vector<std::string> others;
                    for (int j = 0; j < userhere->get_size_of_likes(index-1); j++)
                    {
                        others.push_back(tweethere->who_liked_(index-1)->get_username());
                    }
                    
                    tweethere->dislike(requester->get_username(), others);
                    std::cout << "Tweet disliked succesfully." << std::endl;
                    return 0;
                }
                else
                {
                    std::cout << "You haven't liked this Post yet." << std::endl;
                    return 0;
                }
            } 
        }
    }
    return 0;
}
