#include "../include/menu.hpp"
#include "../include/signup.hpp"
#include "../include/twitterak.hpp"
#include "../include/loggedin.hpp"
#include "../include/checkuser.hpp"
#include "../include/help.hpp"
#include "../include/credits.hpp"
#include "../include/stringtolower.hpp"

extern twitterak game;

void menu()
{
    std::string choose;
    std::cout << std::endl << "******** Welcome to the Tweeterak ********" << std::endl;
    std::cout << "\t\t1- signup" << std::endl;
    std::cout << "\t\t2- login" << std::endl;
    std::cout << "\t\t3- help" << std::endl;
    std::cout << "\t\t4- credits" << std::endl;
    std::cout << "\t\t5- exit" << std::endl;
    std::cout << "\t\t-----> ";
    fflush(stdin);
    std::getline(std::cin, choose);
    std::string lowered_choose = to_lower(choose, false);

    {   // short commands

        if ( choose[0] == '1')
        {
            sign_up(choose);
        }
        else if ( choose[0] == '2')
        {
            login_();
        }
        else if ( choose[0] == '3')
        {
            help();
        }
        else if ( choose[0] == '4')
        {
            credits();
        }
        else if ( choose[0] == '5' || choose[0] == 'q' || choose[0] == 'Q' )
        {
            exit(0);
        }
    }

    {   // sign up

        std::string str1 = "signup";
        std::string str2 = "sign up";

        size_t found = lowered_choose.find(str1);
        if (found != std::string::npos )
        {
            choose.erase(found, found + 6);
            sign_up(choose);
            menu();
        }
        found = lowered_choose.find(str2);
        if (found != std::string::npos )
        {
            choose.erase(found, found + 7);
            sign_up(choose);
            menu();
        }
    }

    { // login
        std::string str1 = "login"; 
        std::string str2 = "log in";     

        size_t found = lowered_choose.find(str1);
        if (found != std::string::npos )
        {
            choose.erase(found, found + 5);
            login_(choose);
        }
        found = lowered_choose.find(str2);
        if (found != std::string::npos )
        {
            choose.erase(found, found + 6);
            login_(choose);
        }
    }

    { // help
        std::string str1 = "help";

        size_t found = lowered_choose.find(str1);
        if (found != std::string::npos )
        {
            choose.erase(found, found + 4);
            help();
            menu();
        }
    }

    { // credits
        std::string str1 = "credits";

        size_t found = lowered_choose.find(str1);
        if (found != std::string::npos )
        {
            choose.erase(found, found + 4);
            credits();
        }
    }

    {
        std::string str1 = "exit";
        std::string str2 = "quit";

        size_t found = lowered_choose.find(str1);
        if (found != std::string::npos )
        {
            choose.erase(found, found + 4);
            exit(-1);
        }
        found = lowered_choose.find(str2);
        if (found != std::string::npos)
        {
            choose.erase(found, found + 4);
            exit(-1);
        }
        else
        {
            system("cls"); 
            std::cout << "undefined order." << std::endl;
            std::cout << "you can find helpful things in help^^" << std::endl;
            menu();
        }

    }

}



void sign_up(std::string x)
{   
    // std::vector <int> spaces;
    // for (size_t i = 0; i < x.length(); i++)
    // {
    //     if ( x[i] == ' ' )
    //     {
    //         spaces.push_back(i);
    //     }
    // }
    x.erase(remove_if(x.begin(), x.end(), isspace), x.end());

    int error = 1;
    int loop_count = 0;
    while ( error == 1 )
    {   
        bool errorr = false;
            
        if ( x == "1" )
        {   
            while ( errorr == false )
            {
                std::string y={};
                int condition = 0;
                int at_in_usern = 0;
                error = 1;
                if( loop_count == 0 )
                {
                std::cout << "Enter your username : ";
                }
                fflush(stdin);
                std::getline(std::cin, y);
                fflush(stdin);
                if ( y[0] != '@')
                {
                    y.insert( y.begin(), '@');
                }

                check_username(y,at_in_usern,condition,errorr);
                if ( errorr == true )
                {
                    game.add_user(signup(y));
                    menu();
                }
                loop_count++;
            }
        }
        else
        {
            int condition = 0;
            int at_in_usern = 0;
            if ( x[0] != '@')
            {
                x.insert( x.begin(), '@');
            }
            check_username(x,at_in_usern,condition, errorr);
            if ( errorr == true )
            {
                game.add_user(signup(x));
                menu();
            }
            fflush(stdin);
            std::getline(std::cin, x);
            fflush(stdin);
        }
    }
}
    
void login_()
{
    std::string username;
    std::string password;
    bool was_successful = false;
    account* currently;
    std::cout << "Enter your Username : ";
    std::cin >> username;
    if ( username[0] != '@' )
    {
        username.insert( username.begin(), '@');
    }
    fflush(stdin);
    std::cout << "Enter your Password : ";
    getline(std::cin, password);
    currently = game.is_login(username, password, was_successful);
    if ( was_successful == true )
    {
        loggedin(currently);
    }
    else 
    {
        menu();
    }
}

void login_(std::string x)
{
    std::string user={};
    std::string pass={};
    account* currently;
    bool was_successful = false;
    separator(x, user, pass);
    currently = game.is_login(user ,pass ,was_successful);
    
    if ( was_successful == true )
    {
        loggedin(currently);
    }
    else 
    {
        menu();
    }
}

void separator(std::string x, std::string& user, std::string& pass)
{
    std::string copy = x;
    copy.erase(remove_if(copy.begin(), copy.end(), isspace), copy.end());
    if ( copy[0] == '@' )
    {
        user_and_pass(x, user, pass);
    }

    else if ( copy[0] != '@' )
    {
        bool till = false;
        for ( unsigned int i = 0; till == false; )
        {
            
            if ( x[i] == ' ' )
            {
                x.erase(x.begin() + i);
            }
            else if ( x[i] != ' ' )
            {
                till = true;
            }
        }
        x.insert(x.begin(), '@');
        user_and_pass(x, user, pass);
    }
}


void user_and_pass(std::string x, std::string& user, std::string& pass)
{
    int ats_in_user = 0;
    int last_char;
    int spaces_in_pass = 0;

    // find and separate user from characters
    for (unsigned int i = 0; i < x.length(); i++)
    {
        if ( x[i] == '@' && ats_in_user == 0 )
        {
            ats_in_user++;
            for ( unsigned int j = i; j < x.length(); j++ )
            {
                if (x[j] != ' ')
                {
                    user += x[j];
                }
                else if ( x[j] == ' ' )
                {   
                    last_char = j;
                    break;
                }   
            }
            x.erase(i, last_char);  
        }
    }
    // doing the same thing for password
    for (unsigned int i = 1; i < x.length(); i++)
    {
        pass += x[i];
    }
    for (unsigned int i = 0; i < pass.length(); i++)
    {   
        if ( pass[i] == ' ' )
        {
            spaces_in_pass++;
        }
    }

    if ( pass.length() == spaces_in_pass )
    {
        std::cout << "Password : ";
        fflush(stdin);
        getline(std::cin, pass);
        fflush(stdin);
    }
}