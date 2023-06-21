#ifndef D4D376DB_ECDE_43FE_BD09_C610411E9325
#define D4D376DB_ECDE_43FE_BD09_C610411E9325

#include "../include/twitterak.hpp"
#include "../include/account.hpp"
#include "../include/checkuser.hpp"
#include "../include/loggedin.hpp"
#include "../include/menu.hpp"
#include "../include/password.hpp"
#include "../include/stringtolower.hpp"
#include <algorithm>

void edit(account*, std::string);
void change_user(account*, std::string);
void change_name(account*, std::string);
void change_bio(account*, std::string);
void change_link(account*, std::string);
void change_country(account*, std::string);
void change_birthday(account*, std::string);
void change_birthmonth(account*, std::string);
void change_birthyear(account*, std::string);
void change_phone_n(account*, std::string);
void change_password(account*, std::string);
void change_header(account*, std::string);

#endif /* D4D376DB_ECDE_43FE_BD09_C610411E9325 */
