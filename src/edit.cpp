#include "../include/edit.hpp"
#include "../include/stringtolower.hpp"


extern twitterak game;

void edit(account* user, std::string order)
{
    std::string lowered_order = to_lower(order, false);

    { // edit username    
        std::string str1 = "username";
        size_t found = lowered_order.find(str1);
        if ( found != std::string::npos ) 
        {
            order.erase(found, found + 8);
            order.erase(remove_if(order.begin(), order.end(), isspace), order.end());
            change_user(user, order);
        }
    }
    

    { // edit name
        std::string str1 = "name";

        size_t found = lowered_order.find(str1);
        if ( found != std::string::npos ) 
        {
            order.erase(found, found + 4);
            order.erase(remove_if(order.begin(), order.end(), isspace), order.end());
            change_name(user, order);
        }
    }

    { // edit bio
        std::string str1 = "bio";

        size_t found = lowered_order.find(str1);
        if ( found != std::string::npos ) 
        {
            order.erase(found, found + 3);
            order.erase(remove_if(order.begin(), order.end(), isspace), order.end());
            change_bio(user, order);
        }
    }

    { // edit link
        std::string str1 = "link";
        std::string to_add_https;
        
        size_t found = lowered_order.find(str1);
        if ( found != std::string::npos ) 
        {
            order.erase(found, found + 4);
            order.erase(remove_if(order.begin(), order.end(), isspace), order.end());
            to_add_https.insert(0, order, 0, 8);
            if ( to_add_https != "https://" )
            {
                order.insert(0, "https://");
            }
            change_link(user, order);
        }
    }

    { // edit country
        std::string str1 = "country";

        size_t found = lowered_order.find(str1);
        if ( found != std::string::npos ) 
        {
            order.erase(found, found + 7);
            order.erase(remove_if(order.begin(), order.end(), isspace), order.end());
            change_country(user, order);
        }
    }

    { // edit birth day
        std::string str1 = "birthday";
        std::string str2 = "birth day";

        size_t found = lowered_order.find(str1);
        if ( found != std::string::npos ) 
        {
            order.erase(found, found + 8);
            order.erase(remove_if(order.begin(), order.end(), isspace), order.end());
            change_birthday(user, order);
        }
        found = lowered_order.find(str2);
        if ( found != std::string::npos ) 
        {
            order.erase(found, found + 9);
            order.erase(remove_if(order.begin(), order.end(), isspace), order.end());
            change_birthday(user, order);
        }
    }

    { // edit birth month
        std::string str1 = "birthmonth";
        std::string str2 = "birth month";

        size_t found = lowered_order.find(str1);
        if ( found != std::string::npos ) 
        {
            order.erase(found, found + 10);
            order.erase(remove_if(order.begin(), order.end(), isspace), order.end());
            change_birthmonth(user, order);
        }
        found = lowered_order.find(str2);
        if ( found != std::string::npos ) 
        {
            order.erase(found, found + 11);
            order.erase(remove_if(order.begin(), order.end(), isspace), order.end());
            change_birthmonth(user, order);
        }
    }

    { // edit birth year
        std::string str1 = "birthyear";
        std::string str2 = "birth year";

        size_t found = lowered_order.find(str1);
        if ( found != std::string::npos ) 
        {
            order.erase(found, found + 9);
            order.erase(remove_if(order.begin(), order.end(), isspace), order.end());
            change_birthyear(user, order);
        }
        found = lowered_order.find(str2);
        if ( found != std::string::npos ) 
        {
            order.erase(found, found + 10);
            order.erase(remove_if(order.begin(), order.end(), isspace), order.end());
            change_birthyear(user, order);
        }
    }

    { // edit phone number
        std::string str1 = "phone number";

        size_t found = lowered_order.find(str1);
        if ( found != std::string::npos ) 
        {
            order.erase(found, found + 12);
            change_phone_n(user, order);
        }
    }

    { // edit password
        std::string str1 = "password";
        std::string str2 = "Password";

        size_t found = lowered_order.find(str1);
        if ( found != std::string::npos ) 
        {
            order.erase(found, found + 8);
            change_password(user, order);
        }
    }

    { // edit header
        std::string str1 = "header";
        std::string str2 = "header color";

        size_t found = lowered_order.find(str1);
        if ( found != std::string::npos ) 
        {
            order.erase(found, found + 6);
            order.erase(remove_if(order.begin(), order.end(), isspace), order.end());
            change_header(user, order);
        }
        found = lowered_order.find(str2);
        if ( found != std::string::npos ) 
        {
            order.erase(found, found + 12);
            order.erase(remove_if(order.begin(), order.end(), isspace), order.end());
            change_header(user, order);
        }
    }
}



void change_user(account* user, std::string x)
{
    int error = 1;
    int loop_count = 0;
    while ( error == 1 )
    {   
        bool errorr = false;
        
        int condition = 0;
        int at_in_usern = 0;
        if ( x[0] != '@')
        {
            x.insert( x.begin(), '@');
        }
        check_username(x,at_in_usern,condition, errorr);
        if ( errorr == true )
        {
            user->set_username(x);
            std::cout << "Username changed succesfully." << std::endl;
            loggedin(user);
        }
        fflush(stdin);
        std::getline(std::cin, x);
        fflush(stdin);    
    }
}

void change_name(account* user, std::string temp)
{
    if ( temp.length() <= 30 && temp.length() >= 1 )
    {
        user->set_name(temp);
        std::cout << "Name changed succesfully." << std::endl;
        loggedin(user);
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

void change_bio(account* user, std::string temp)
{
    if ( temp.length() <= 160 && temp.length() >= 1 )
    {
        user->set_biography(temp);
        std::cout << "Bio changed succesfully." << std::endl;
        loggedin(user);
    }
    else if ( temp.length() > 160)
    {
        std::cout << "!Bio is too long. *MAX 160 Characters." << std::endl;
    }
    else if ( temp.empty() )
    {
        user->set_biography(temp);
        std::cout << "Bio is empty now." << std::endl;
        loggedin(user);
    }    
}

void change_link(account* user, std::string temp)
{
    if ( temp.length() <= 100 && temp.length() >= 1 )
    {
        user->set_link(temp);
        std::cout << "Link changed succesfully." << std::endl;
        loggedin(user);
    }
    else if ( temp.length() > 100)
    {
        std::cout << "!Link is too long. *MAX 100 Characters." << std::endl;
    }
    else if ( temp.empty() )
    {
        user->set_biography(temp);
        std::cout << "Link is empty now." << std::endl;
        loggedin(user);
    }    
}

void change_country(account* user, std::string temp)
{
    if ( temp.length() >= 1 && temp.length() <= 30 )
    {
        user->set_country(temp);
        std::cout << "Country changed succesfully." << std::endl;
        loggedin(user);
    }
    else if ( temp.length() > 30 )
    {
        std::cout << std::endl << "!Country can't be longer than 30 characters." << std::endl;
        loggedin(user);
    }
    else if ( temp.empty() )
    {
        std::cout << std::endl << "!Country can't be empty." << std::endl;
        loggedin(user);    
    }
}

void change_birthyear(account* user, std::string temp)
{
    int number = stoi(temp);
    if( number < 1900 || number > 2023 )
        {
            std::cout << "!Please enter a valid year." << std::endl;
            loggedin(user);
        }
        else if( number >= 2010 && number <= 2023 )
        {
            std::cout << "!You're too young to use Twitterak! " << std::endl;
            menu();
        }
        else if( number >= 1900 && number < 2010 )
        {
            user->set_birthyear(number);
            std::cout << "Birthyear changed succesfully." << std::endl;
            loggedin(user);
        }
}

void change_birthmonth(account* user, std::string temp)
{
    int number = stoi(temp);
    if( number < 1 || number > 12 )
        {
            std::cout << "!Please enter a valid month." << std::endl;
            loggedin(user);
        }
        else if( number >= 1 && number <= 12 )
        {
            user->set_birthmonth(number);
            std::cout << "Birthmonth changed succesfully." << std::endl;
            loggedin(user);
        }
}

void change_birthday(account* user, std::string temp)
{
    int number = stoi(temp);
    int month = user->get_birthmonth();

    if ( month >= 1 && month <= 6 )
    {
        if( number >= 1 && number <= 31 )
        { 
            user->set_birthday(number);
            std::cout << "Birthday changed succesfully." << std::endl;
            loggedin(user);
        }
    }
    else if ( month >= 7 && month <= 12 )
    {
        if( number >= 1 && number <= 30 )
        {
            user->set_birthday(number);
            std::cout << "Birthday changed succesfully." << std::endl;
            loggedin(user);
        }   
        else if ( number == 31 )
        {
            std::cout << "!The month you get born in, has 30 days." << std::endl;
            loggedin(user);
        }
    }
    if( number < 1 || number > 31 )
    {
        std::cout << "!Please enter a valid day." << std::endl;
        loggedin(user);
    }
}

void change_phone_n(account* user, std::string temp)
{
    if ( temp[0] == ' ')
    {
        temp.erase(remove(temp.begin(), temp.begin() + 1, ' '));
    }
    std::vector <char> nums = {'0','1','2','3','4','5','6','7','8','9'};
    unsigned int spaces_in_phone = 0;
    unsigned int numbers_in_phone = 0;
    unsigned int index_of_space = 0;
    unsigned int index_of_last_space = 0;
    bool validity = true;
    fflush(stdin);
    std::cout << temp << std::endl;
    if( temp.size() < 12 )
    {
        std::cout << std::endl << "!too short to be a valid phone number." << std::endl;
        loggedin(user);
    }
    else if( temp.size() > 16 )
    {
        std::cout << std::endl << "!too long to be a valid phone number." << std::endl;
        loggedin(user);
    }
    else if( temp[0] == 0 )
    {
        std::cout << std::endl << "!Enter a valid phone number." << std::endl;
        loggedin(user);
    }
    else if( temp.size() >= 12 && temp.size() <= 16 )
    {   
        for ( int i = 0; i < temp.length(); i++ )
        {
            for ( int j = 0; j < 10; j++ )
            {
                if ( temp[i] == nums[j] )
                {
                    numbers_in_phone++;
                }
            }
            if ( temp[i] == ' ' )
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
        if ( numbers_in_phone == temp.size()- spaces_in_phone && spaces_in_phone > 0 && validity == true )
        {  
            //temp.erase(temp.begin() + index_of_space);     this line removes space from temp *not needed
            user->set_phone_n(temp);
            std::cout << "Phone number changed succesfully." << std::endl;
            loggedin(user);
            
        }
        else
        {
        std::cout << std::endl << "!please enter your phone number in this form : 1 1234567891 or 98 9128888888" << std::endl;
        loggedin(user);
        }
            
    }
}

void change_password(account* user, std::string temp)
{
    user->set_password(password(temp));
    std::cout << "Password changed succesfully." << std::endl;
    loggedin(user);
}

void change_header(account* user, std::string temp)
{
    std::string color = to_lower(temp,false);
    if ( color == "white")
    {
        user->set_color("white");
        std::cout << "Header color changed to white succesfully." << std::endl;
        loggedin(user);
    }
    else if ( color == "red" )
    {
        user->set_color("red");
        std::cout << "Header color changed to red succesfully." << std::endl;
        loggedin(user);
    }
    else if ( color == "orange" )
    {
        user->set_color("orange");
        std::cout << "Header color changed to orange succesfully." << std::endl;
        loggedin(user);
    }
    else if ( color == "yellow" )
    {
        user->set_color("yellow");
        std::cout << "Header color changed to yellow succesfully." << std::endl;
        loggedin(user);
    }
    else if ( color == "green" )
    {
        user->set_color("green");
        std::cout << "Header color changed to green succesfully." << std::endl;
        loggedin(user);
    }
    else if ( color == "blue" )
    {
        user->set_color("blue");
        std::cout << "Header color changed to blue succesfully." << std::endl;
        loggedin(user);
    }
    else if ( color == "purple" )
    {
        user->set_color("purple");
        std::cout << "Header color changed to purple succesfully." << std::endl;
        loggedin(user);
    }
    else if ( color == "black" )
    {
        user->set_color("black");
        std::cout << "Header color changed to black succesfully." << std::endl;
        loggedin(user);
    }
    else
    {
        std::cout << "undefined color" << std::endl;
        loggedin(user);
    }
}