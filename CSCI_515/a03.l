/*definition*/

%option noyywrap

%{
 #include<iostream>
 using std::cout;
%}

%%


the|The { cout << "T_DEFINITE_ARTICLE";}

quick|brown|lazy { cout << "T_ADJECTIVE";}

fox|dog|wall|liquid|bottles { cout << "T_NOUN";}

jumped|see { cout << "T_VERB";}

over|on|of { cout << "T_PREPOSITION";}

[.] { cout << "T_PERIOD";}

I { cout << "T_PRONOUN";}

[0-9]+ { cout << "T_INTEGER";}


%%
/*literal code*/


int main()
{
  yylex();
  0; //return 0;
}
