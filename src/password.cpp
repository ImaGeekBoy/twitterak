#include "../include/password.hpp"
#include "../include/account.hpp"

std::vector <char> numbers = {'0','1','2','3','4','5','6','7','8','9'};
std::vector <char> lowercases = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
'n','o','p','q','r','s','t','u','v','w','x','y','z'};
std::vector <char> uppercases = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

std::string password(std::string pass)
{
    int error = 1;
    std::string temp;
    int temp_num = 0;
    if ( pass.empty() != true )
    {
        for ( size_t i = 1; i < pass.size(); i++ )
        {
            temp += pass[i];
        }
    }
    while ( error == 1 )
    {   
        int numbersInPass = 0;
        int lowercasesInPass = 0;
        int uppercasesInPass = 0;
        if ( pass.empty() == true )
        {
            fflush(stdin);
            getline(std::cin, temp);
            fflush(stdin);
        }
        if ( temp.length() >= 8 )
        {

            for ( int i = 0; i < temp.length(); i++ )
            {
                for ( int j = 1; j < numbers.size(); j++ )
                {
                    if ( temp[i] == numbers[j] )
                    {
                        numbersInPass++;
                    }
                
                }
            }  
            for ( int i = 0; i < temp.length(); i++ )
            {
                for ( int j = 0; j < lowercases.size(); j++ )
                {
                    if ( temp[i] == lowercases[j] )
                    {
                        lowercasesInPass++;
                    }
                }
            }
            for ( int i = 0; i < temp.length(); i++ )
            {
                for ( int j = 0; j < uppercases.size(); j++ )
                {
                    if ( temp[i] == uppercases[j] )
                    {
                        uppercasesInPass++;
                    }
                }
            }

            //int allowedchars = numbersInPass + lowercasesInPass + uppercasesInPass;
            if ( numbersInPass > 0 && lowercasesInPass > 0 && uppercasesInPass > 0 )
            {
                error = 0;
                std::cout << "Good pass!" << std::endl;
                return temp;
            }

            else if ( numbersInPass < 1 || lowercasesInPass < 1 || uppercasesInPass < 1  )
            {
                std::cout << "your password must be at least 8 characters and contain at least one number, a uppercase letter, and a lowercase letter." << std::endl;
                std::cout << "choose a safer one! : ";
            }
          
        }
        else if ( temp.length() < 8 )
        {
            std::cout << "Password is too short." << std::endl;
            std::cout << "choose a safer one! : ";
        }

        pass.clear();
    }
    
    return "0";

}