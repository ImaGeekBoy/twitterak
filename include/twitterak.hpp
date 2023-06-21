#ifndef AF0CDFD6_92D6_4970_8F85_57B36315CF5B
#define AF0CDFD6_92D6_4970_8F85_57B36315CF5B

#include <ctype.h>
#include <cstring>
#include <vector>
#include "../include/account.hpp"

class twitterak
{
private:
    std::vector<account*> users;

public:

    void run();
    void add_user(account*);
    void deleteuser(std::string);

    void show_info(std::string, account*);
    account* is_login(std::string, std::string, bool&);
    int get_size_of_users();
    int is_username_available(std::string, bool&, bool&);
    account* which_account( std::string );

};
//extern twitterak game;

#endif /* AF0CDFD6_92D6_4970_8F85_57B36315CF5B */
