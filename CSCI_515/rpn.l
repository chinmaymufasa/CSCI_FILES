%option noyywrap
%option nodefault

%{
  #include "rpn.tab.h"
  #include<string>
  using std::stoi;
%}

%%

[0-9]+  { yylval=stoi(yytext); return T_INT_CONSTANT; }
"+"     { return T_PLUS; }
"-"     { return T_MINUS; }
"*"     { return T_MULTIPLY; }
"/"     { return T_DIVIDE; }
\.      { return T_PRINT; }
\?      { return T_SIZE; }
[ \t\n]      /* do nothing */
.       { return T_ERROR; }

%%
