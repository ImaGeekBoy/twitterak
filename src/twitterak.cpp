#include "../include/twitterak.hpp"
#include "../include/menu.hpp"

    twitterak game;
    void twitterak::run()
    {
        menu();
    }

    void twitterak::add_user(account* user)
    {
        users.push_back(user);
    }
    void twitterak::deleteuser(std::string user)
    {
        for (unsigned int i = 0; i < game.users.size(); i++)
        {
            if ( users[i]->get_username() == user )
            {
                users.erase(users.begin() + i);
                menu();
            }
        }
    }

    account* twitterak::is_login(std::string username, std::string password, bool& x)
    {
        
        char thisuser_lowercase[username.length()];
        for (int i = 0; i <= username.length(); i++)
        {
            thisuser_lowercase[i] = (tolower(username[i]));
        }

        if (users.size() == 0)
        {
            std::cout << std::endl << "!No any users in ram.\nYou should sign up first." << std::endl;
            x = false;
        }

        for ( unsigned int i = 0; i < users.size() ; i++ )
        {
            int condition = 0;
            std::string user = users[i]->get_username();
            char user_lowercase[users[i]->get_username().length()];
            for (int i = 0; i <= user.length(); i++)
            {
                user_lowercase[i] = (tolower(user[i]));
            }
            for (int i = 0; i < user.length(); i++)
            {
                if (user_lowercase[i] == thisuser_lowercase[i])
                {
                    condition++;
                }
            }

            if ( condition == user.length() )
            {
                if ( users[i]->get_password() == password )
                {
                    std::cout << "Welcome " << users[i]->get_name() << std::endl;
                    x = true;
                    return users[i];
                }
                else
                {
                std::cout << "Wrong password. " << std::endl;
                break;
                }
                
            }

            if ( i == users.size()-1 )
            {
                std::cout << "Username doesnt exist. " << std::endl;
            }
        }
    }

    int twitterak::is_username_available(std::string username, bool& ok, bool& reserved)
    {
        char user_lowercase[username.length()];
        unsigned int equal = 0;
        //std::strcpy( user_lowercase, username.c_str() );

        for (int i = 0; i <= username.length(); i++)
        {
            user_lowercase[i] = (tolower(username[i]));
        }
    
        if ( strcmp(user_lowercase, "@login") == 0 || 
            strcmp(user_lowercase, "@signup") == 0 ||
            strcmp(user_lowercase, "@profile") == 0 ||
            strcmp(user_lowercase, "@tweet") == 0 ||
            strcmp(user_lowercase, "@delete") == 0 ||
            strcmp(user_lowercase, "@dislike") == 0 ||
            strcmp(user_lowercase, "@logout") == 0 )
        {
            std::cout << std::endl << "this is a reserved keyword sheytoon bala." << std::endl;
            ok = false;
            reserved = true;
            return 0;
        }
        
        for ( int i = 0; i < users.size(); i++ )
        {
            equal = 0;
            // creating a char array in size of username[i]
            std::string temp = users[i]->get_username();
            // x foor loop.
            int x = temp.length();
            char users_in_ram[x];
            
            // converting all previous usernames to lowercase one by one
            for ( int j = 0; j < x; j++ )
            {
                users_in_ram[j] = ( tolower(temp[j]) );
            }
            users_in_ram[x] = '\0';
            
            //
            if ( strcmp(users_in_ram, user_lowercase) == 0 )
            {
                ok = false;
                return 0;
            }
            
        }
        ok = true;
        return 0;
    
    }



    void twitterak::show_info(std::string user, account* account)
    {
        bool printed = false;
        for ( int i = 0; i < users.size(); i++ )
        {
            if ( users[i]->get_username() == user )
            {
                printed = true;
                std::cout << std::endl << "1- Username: " << users[i]->get_username() << std::endl;
                std::cout << "2- Name: " << users[i]->get_name() << std::endl;
                std::cout << "3- Biography: " << users[i]->get_biography() << std::endl;
                std::cout << "4- Link: " << users[i]->get_link() << std::endl;
                std::cout << "5- Country: " << users[i]->get_country() << std::endl;
                std::cout << "6- Header color: " << users[i]->get_color() << std::endl;
                
                if ( account->get_username() == user )
                {
                    std::cout << "7- Birthday: " << users[i]->get_birthyear() << "-" << users[i]->get_birthmonth();
                    std::cout << "-" << users[i]->get_birthday() << std::endl;
                    std::cout << "8- Phone number: +" << users[i]->get_phone_n() << std::endl;
                    std::cout << "9- Password: " << users[i]->get_password() << std::endl;
                }
            }

            if ( i == users.size() - 1 && printed == false )
            {
                std::cout << "No such user." << std::endl;
            }

        }
    }

    account* twitterak::which_account( std::string account )
    {
        for ( int i = 0; i < users.size(); i++ )
        {
            if ( account == users[i]->get_username() )
            {
                return users[i];
            }
        }
    }

    /*for ( int j = 0; j < x; j++ )
            {
                if ( users_in_ram[j] == user_lowercase[j] )
                { 
                    equal++;
                }                
            }

            if ( equal == strlen(user_lowercase) && equal == strlen(users_in_ram) )
            {
                ok = false;
                return 0;
            }*/