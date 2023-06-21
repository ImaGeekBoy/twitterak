#ifndef C3344339_F7A9_473B_BC10_0AE030B9AA38
#define C3344339_F7A9_473B_BC10_0AE030B9AA38

#include <string>
#include "../include/account.hpp"

void loggedin(account*);
std::string takeOrder(account *account);
void tweet_here(account*);
void showtweets(std::string);
int showtweets(std::string, int, account*);
int showlikes(std::string, int, account*);
int forlikeanddis(std::string, bool, account*);

#endif /* C3344339_F7A9_473B_BC10_0AE030B9AA38 */
