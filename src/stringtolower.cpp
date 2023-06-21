#include "../include/stringtolower.hpp"

std::string to_lower(std::string inp, bool w_space )
{
    int len = inp.size();
    char c[len + 1];
    std::string result;
    
    for ( size_t i = 0; i < len; i++ )
    {
        c[i] = inp[i];
        result += tolower(c[i]);
    }
    
    if ( w_space == true )
    {
        result.erase(remove_if(result.begin(), result.end(), isspace), result.end());
    } 

    return result;
}
