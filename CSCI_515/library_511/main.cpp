//Chinmay Satpanthi
//CSCI 511
//Library Project
//File main.cpp

#include <iostream>
#include <string>

#include "Library.h"

using namespace std;

int main() {

   Library gavelton;       //Making a new library obj begins by reading txt files upon initialization.

   int user_choice;
   while (1) {
      cout << "1) call number " << endl;
      cout << "2) title " << endl;
      cout << "3) subject " << endl;
      cout << "4) other " << endl;
      cout << "5) exit " << endl;

      cin >> user_choice;

      string search_phrase;      //What the user chooses to search, will include spaces
      vector<Media*> matches;    //stores the matches found in here

      //If users selects 1,2,3 or 4 find the specified request, else exit

      //Call Number
      if (user_choice == 1) {

         cout << "Enter keyphrase: "; 
         cin.ignore();
         getline(cin, search_phrase);

         matches = gavelton.find_everything_with_call_number(search_phrase);
         for (unsigned int i = 0; i < matches.size(); i++) {
            matches[i]->display();     //displays the results
         }

      }
      //Title
      else if (user_choice == 2) {

         cout << "Enter keyphrase: ";

         cin.ignore();
         getline(cin, search_phrase);

         matches = gavelton.find_everything_with_title(search_phrase);
         for (unsigned int i = 0; i < matches.size(); i++) {
            matches[i]->display();     //displays the results
         }

      }
      //Subject
      else if (user_choice == 3) {

         cout << "Enter keyphrase: ";

         cin.ignore();
         getline(cin, search_phrase);

         matches = gavelton.find_everything_with_subject(search_phrase);
         for (unsigned int i = 0; i < matches.size(); i++) {
            matches[i]->display();     //displays the results
         }

      }
      //Other
      else if (user_choice == 4) {

         cout << "Enter keyphrase: ";

         cin.ignore();
         getline(cin, search_phrase);

         matches = gavelton.find_everything_with_other(search_phrase);
         for (unsigned int i = 0; i < matches.size(); i++) {
            matches[i]->display();     //displays the results
         }

      }
      //Exit
      else {
         return 0;
      }

   }


   return 0;
}