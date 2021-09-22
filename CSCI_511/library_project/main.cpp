#include <iostream>
#include <string>

#include "Library.h"

using namespace std;

int main() {

   Library gavelton;

   int user_choice;
   while (1) {
      cout << "1) call number " << endl;
      cout << "2) title " << endl;
      cout << "3) subject " << endl;
      cout << "4) other " << endl;
      cout << "5) exit " << endl;

      cin >> user_choice;

      string search_phrase;
      vector<Media*> matches;

      if (user_choice == 1) {

         cout << "Enter keyphrase: "; 
         //cin >> search_phrase;
         cin.ignore();
         getline(cin, search_phrase);
   
         cout << search_phrase << endl;

         matches = gavelton.find_everything_with_call_number(search_phrase);
         for (unsigned int i = 0; i < matches.size(); i++) {
            matches[i]->display();
         }

      }
      else if (user_choice == 2) {

         cout << "Enter keyphrase: ";

         cin.ignore();
         getline(cin, search_phrase);

         matches = gavelton.find_everything_with_title(search_phrase);
         for (unsigned int i = 0; i < matches.size(); i++) {
            matches[i]->display();
         }

      }
      else if (user_choice == 3) {

         cout << "Enter keyphrase: ";

         cin.ignore();
         getline(cin, search_phrase);

         matches = gavelton.find_everything_with_subject(search_phrase);
         for (unsigned int i = 0; i < matches.size(); i++) {
            matches[i]->display();
         }

      }
      else if (user_choice == 4) {

         cout << "Enter keyphrase: ";

         cin.ignore();
         getline(cin, search_phrase);

         matches = gavelton.find_everything_with_other(search_phrase);
         for (unsigned int i = 0; i < matches.size(); i++) {
            matches[i]->display();
         }

      }
      else {
         return 0;
      }

   }


   return 0;
}