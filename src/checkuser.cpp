#include "../include/checkuser.hpp"
#include "../include/twitterak.hpp"
#include "../include/signup.hpp"

extern twitterak game;

std::vector <char> allowed_char_for_usern = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m',
'n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M',
'N','O','P','Q','R','S','T','U','V','W','X','Y','Z','@','_'};

void check_username(std::string x,int at_in_usern, int condition, bool& ok)
{
    bool isavail = false;
    bool reserved = false;
    for ( int i = 0; i < x.length(); i++ )
    {
        if ( x[i] == '@' )
            {
                at_in_usern++;
            }       
        for ( int j = 0; j < allowed_char_for_usern.size(); j++ )
        {
            if ( x[i] == allowed_char_for_usern[j] )
            {
                condition++;
            }
        }
    }  

        if ( condition == x.length() )
        { 
            if ( at_in_usern == 1 )
            {
                if ( x[0] == '@' )
                {
                    if( x[1] == allowed_char_for_usern[0] || 
                        x[1] == allowed_char_for_usern[1] || 
                        x[1] == allowed_char_for_usern[2] || 
                        x[1] == allowed_char_for_usern[3] || 
                        x[1] == allowed_char_for_usern[4] || 
                        x[1] == allowed_char_for_usern[5] || 
                        x[1] == allowed_char_for_usern[6] || 
                        x[1] == allowed_char_for_usern[7] || 
                        x[1] == allowed_char_for_usern[8] || 
                        x[1] == allowed_char_for_usern[9] )
                    {
                        std::cout << std::endl << "username can't get strarted with number." << std::endl;
                        std::cout << "Enter another username : ";
                        ok = false;
                    }
                    else
                    {   if ( x.length() >= 6 && x.length() <= 17 )
                        {
                            game.is_username_available(x,isavail,reserved);
                            if ( isavail == true )
                            {
                                ok = true;
                            }
                            else if ( isavail == false && reserved == false )
                            {
                                std::cout << "Username is taken by someone else" << std::endl;
                                std::cout << "Enter another username : ";
                                ok = false;
                            }
                            else if ( reserved == true ) 
                            {
                                std::cout << "Enter another username : ";
                                ok = false;
                            }
                        
                        }
                        else if ( x.length() < 6 )
                        {
                            std::cout << std::endl << "username should be at least 5 characters long." << std::endl;
                            std::cout << "Enter another username : ";
                            ok = false;
                        }
                        else if ( x.length() > 17 )
                        {
                            std::cout << std::endl << "username should'nt be longer than 16 characters." << std::endl;
                            std::cout << "Enter another username : ";
                            ok = false;
                        }
                    }
                }
                else if ( x[0] != '@' )
                {
                    std::cout << std::endl << "the username itself should'nt include @" << std::endl;
                    std::cout << "Enter another username : ";
                    ok = false;
                }
            }
            /*else if ( at_in_usern == 0 )
            {
                if( x[0] == allowed_char_for_usern[0] || 
                    x[0] == allowed_char_for_usern[1] || 
                    x[0] == allowed_char_for_usern[2] || 
                    x[0] == allowed_char_for_usern[3] || 
                    x[0] == allowed_char_for_usern[4] || 
                    x[0] == allowed_char_for_usern[5] || 
                    x[0] == allowed_char_for_usern[6] || 
                    x[0] == allowed_char_for_usern[7] || 
                    x[0] == allowed_char_for_usern[8] || 
                    x[0] == allowed_char_for_usern[9] )
                {
                    std::cout << std::endl << "username can't get strarted with number." << std::endl;
                    std::cout << "Enter another username : ";
                    ok = false;
                }
                else
                {
                    if ( x.length() >= 5 && x.length() <= 16 )
                    {
                        game.is_username_available(x, isavail, reserved);
                        if ( isavail == true )
                        {   
                        ok = true;
                        }
                        else if ( isavail != true && reserved == false )
                        {
                            std::cout << std::endl << "Username is taken by someone else" << std::endl;
                            std::cout << "Enter another username : ";
                            ok = false;
                        }
                    }
                    else if ( x.length() < 5 )
                    {
                        std::cout << std::endl << "username should be at least 5 characters long." << std::endl;
                        std::cout  << "Enter another username : ";
                        ok = false;
                    }
                    else if ( x.length() > 16 )
                    {
                        std::cout << std::endl << "username should'nt be longer than 16 characters." << std::endl;
                        std::cout << "Enter another username : ";
                        ok = false;
                    }
                }
            }*/
            else if ( at_in_usern > 1 )
            {
                std::cout << std::endl << "the username itself should'nt include @" << std::endl;
                std::cout << "Enter another username : ";
                ok = false;
            }
        }
        else if ( condition != x.length() )
        {
            std::cout << std::endl << "you've used unallowed characters in username." << std::endl;
            std::cout << "only Alphbets and integers are allowed." << std::endl;
            std::cout << "Enter another username : ";
            ok = false;
        }

    
    
}