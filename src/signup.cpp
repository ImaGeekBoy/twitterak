#include "../include/signup.hpp"
#include "../include/account.hpp"
#include "../include/password.hpp"
#include "../include/twitterak.hpp"
#include "../include/menu.hpp"

std::vector <char> nums = {'0','1','2','3','4','5','6','7','8','9'};

account* signup(std::string usern)
{   
    account *newone = new account(usern);
    std::string temp;
    std::string phone_numb;
    unsigned int number;
    int error = 1;   
    std::cout << std::endl << "please enter your information carefully." << std::endl;
    Sleep(1200);

    
    // simply set the name
    while ( error == 1 )
    {
        fflush(stdin);
        std::cout << "please enter your full name : ";
        std::getline(std::cin, temp);
        if ( temp.length() <= 30 && temp.length() >= 1 )
        {
            newone->set_name(temp);
            fflush(stdin);
            error = 0;
        }
        else if ( temp.length() > 30)
        {
            std::cout << "!Name is too long. *MAX 30 Characters." << std::endl;
        }
        else if ( temp.empty() )
        {
            std::cout << "!Name can't be empty." << std::endl;
        }    
    }












    // set the phone number
    std::cout << std::endl << "Now please enter your phone number in this form : 1 1234567891 or 98 9128888888" << std::endl;
    std::cout <<  "so put a space between Area code and phone number. NO NEED TO ENTER THE PLUS'+' SIGN. " << std::endl;
    // check if the phone number is valid.
    error = 1;
    while( error == 1 )
    {
        unsigned int spaces_in_phone = 0;
        unsigned int numbers_in_phone = 0;
        unsigned int index_of_space = 0;
        unsigned int index_of_last_space = 0;
        bool validity = true;
        std::cout << "+";
        fflush(stdin);
        std::getline(std::cin, phone_numb);
        fflush(stdin);
        if( phone_numb.size() < 12 )
        {
            std::cout << std::endl << "!too short to be a valid phone number." << std::endl;
            std::cout << "Please enter it again." << std::endl;
        }
        else if( phone_numb.size() > 16 )
        {
            std::cout << std::endl << "!too long to be a valid phone number." << std::endl;
            std::cout << "Please enter it again." << std::endl;
        }
        else if( phone_numb[0] == 0 )
        {
            std::cout << std::endl << "!Enter a valid phone number." << std::endl;
            std::cout << "Please enter it again." << std::endl;
        }
        else if( phone_numb.size() >= 12 && phone_numb.size() <= 16 )
        {   
            for ( int i = 0; i < phone_numb.length(); i++ )
            {
                for ( int j = 0; j < 10; j++ )
                {
                    if ( phone_numb[i] == nums[j] )
                    {
                        numbers_in_phone++;
                    }
                }
                if ( phone_numb[i] == ' ' )
                {
                    spaces_in_phone++;
                    if ( spaces_in_phone == 1 )
                    {
                        index_of_space = i;
                    }
                    index_of_last_space = index_of_space;
                    index_of_space = i;
                    if ( spaces_in_phone > 1 )
                    {
                        if( index_of_space -1 != index_of_last_space )
                        {
                            validity = false;
                        }
                    }
                }   
            }
            if ( numbers_in_phone == phone_numb.size()- spaces_in_phone && spaces_in_phone > 0 && validity == true )
            {  
                error = 0;
                //phone_numb.erase(phone_numb.begin() + index_of_space);     this line removes space from phone_numb *not needed
                newone->set_phone_n(phone_numb);
            }
            else
            {
            std::cout << std::endl << "!please enter your phone number in this form : 1 1234567891 or 98 9128888888" << std::endl;
            std::cout << "enter it again." << std::endl;
            }
            
        }
    }














    // first i tried to set country by area code of phone number but you said it's not necessary
    error = 1;
    while( error == 1 )
    {
        std::cout << "Enter your Country : ";
        std::getline( std::cin, temp );
        if ( temp.length() >= 1 && temp.length() <= 30 )
        {
            error = 0;
            newone->set_country(temp);
        }
        else if ( temp.length() > 30 )
        {
            std::cout << std::endl << "!Country can't be longer than 30 characters." << std::endl;
        }
        else if ( temp.empty() )
        {
            std::cout << std::endl << "!Country can't be empty." << std::endl;
        }
    }

    // time to set the birth date. if user be under 13 won't be allowed to register.
    error = 1;
    std::cout << "Please enter your birth year : ";
    while( error == 1 )
    {   
        std::cin >> number;
        fflush(stdin);
        if( number < 1900 || number > 2023 )
        {
            std::cout << "!Please enter a valid year." << std::endl;
            std::cout << "Enter again : ";
            std::cin.clear();
        }
        else if( number >= 2010 && number <= 2023 )
        {
            std::cout << "!You're too young to use Twitterak! " << std::endl;
            menu();
        }
        else if( number >= 1900 && number < 2010 )
        {
            error = 0;
            newone->set_birthyear(number);
        }
    }

    // users should enter their birth month between 1 and 12
    std::cout << "Please enter your birth month : ";
    error = 1;
    while( error == 1 )
    {   
        std::cin >> number;
        fflush(stdin);

        if( number < 1 || number > 12 )
        {
            std::cout << "!Please enter a valid month." << std::endl;
            std::cout << "Enter again : ";
            std::cin.clear();
        }
        else if( number >= 1 && number <= 12 )
        {
            error = 0;
            newone->set_birthmonth(number);
        }
    }

    // users should enter their birth day between 1 and 31
    std::cout << "Please enter your birth day : ";
    error = 1;
    while( error == 1 )
    {   
        int month = newone->get_birthmonth();
        std::cin >> number;
        fflush(stdin);

        if ( month >= 1 && month <= 6 )
        {
            if( number >= 1 && number <= 31 )
            {
            error = 0;
            newone->set_birthday(number);
            }
        }
        else if ( month >= 7 && month <= 12 )
        {
            if( number >= 1 && number <= 30 )
            {
            error = 0;
            newone->set_birthday(number);
            }   
            else if ( number == 31 )
            {
                std::cout << "!The month you get born in, has 30 days." << std::endl;
                std::cout << "Enter again : ";
                std::cin.clear();
            }
        }
        if( number < 1 || number > 31 )
        {
            std::cout << "!Please enter a valid day." << std::endl;
            std::cout << "Enter again : ";
            std::cin.clear();
        }        
    }

    // now user should enter a safe pass (details in password.cpp file)
    //std::string passwordd = password();
    std::cout << "Please enter your password : ";
    newone->set_password(password(""));

    std::cout << std::endl << "* Congratulations!" << std::endl;
    std::cout << "Your twitterak account has been successfully created." << std::endl;
    std::cout << "you can edit optional things like your biography, link and header color in Edit Settings." << std::endl;

    return newone;
}