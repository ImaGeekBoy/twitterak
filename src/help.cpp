#include "../include/help.hpp"
#include "../include/menu.hpp"

int loop = 0;  

void help()
{   
    std::string choose;
    if ( loop == 0 )
    {
    std::cout << "what part of app you have question about?" << std::endl;
    }
    else
    {    
    std::cout << std::endl << "what else?" << std::endl;
    }
    std::cout << "1- signup" << std::endl;
    std::cout << "2- login" << std::endl;
    std::cout << "3- tweet" << std::endl;
    std::cout << "4- profile" << std::endl;
    std::cout << "5- back" << std::endl;

    fflush(stdin);
    getline(std::cin, choose);
    fflush(stdin);
    
    if (choose == "1" || choose == "signup")
    {
        std::cout << std::endl;
        std::cout << "You can signup in twitterak by entring 1 or signup keyword." << std::endl;
        std::cout << "by entering 1 you should enter your wanted username." << std::endl;
        std::cout << "you can also simply put your username after signup to register." << std::endl;
        std::cout << "name and country have no any restrictions." << std::endl;
        std::cout << "password should include at least one uppercase, one lowercase and one integer." << std::endl;
        std::cout <<  "username should'nt start with integers and should not contain symbols." << std::endl;
        std::cout << "you should enter phone number like this: areacode+one blankspace+numbers." << std::endl;
        loop++;
        help();
    }
    else if (choose == "2" || choose == "login")
    {
        std::cout << std::endl;
        std::cout << "You can easily login by entering 2 or login keyword." << std::endl;
        std::cout << "if you enter 2 you should then enter your username and password." << std::endl;
        std::cout << "now if you've entered login you can simply put your username and password after it." << std::endl;
        std::cout << "like : login + blank space + @username + blank space + pass" << std::endl; 
        loop++;
        help();
    }
    else if (choose == "3" || choose == "tweet")
    {
        std::cout << std::endl;
        std::cout << "you can also tweet by writing the keyword tweet and whatever u want." << std::endl;
        std::cout << "note that every tweet can contain maximum 280 characters and they can't be empty too." << std::endl;
        std::cout << "to edit or delete a tweet you should enter: edit/delete + tweet + tweet number." << std::endl;
        std::cout << "to see others tweets simply enter their username w at sign." << std::endl; 
        std::cout << "if you have any particular tweet in mind enter in follow order -> @username+:+tweet number" << std::endl;
        std::cout << "to others tweet simply enter their username + at sign." << std::endl; 
        loop++;
        help();
    }   
    else if (choose == "4" || choose == "profile")
    {
        std::cout << std::endl;
        std::cout << "if u want see yours/others profile info enter--> profile + @username " << std::endl;
        std::cout << "you can also enter me to see your info." << std::endl;
        std::cout << "to edit any profile info enter-> edit profile + thing to edit + new value. *double quotes not neccesary" << std::endl;
        std::cout << "if you want to delete your Twiiterak account enter delete account and then prove your request." << std::endl; 
        loop++;
        help();
    }
    else if ( choose == "5" || choose == "back" )
    {
        system("cls");
        loop++;
        menu();
    }
    else 
    {
        std::cout << std::endl;
        std::cout << "undefined order." << std::endl;
        help();
    }


}