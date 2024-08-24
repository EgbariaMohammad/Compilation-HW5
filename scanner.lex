%{
    #include "Symbol.hpp"
    #include "parser.tab.hpp"
    #include "hw3_output.hpp"
%}
%option yylineno
%option noyywrap
%option nounput

whiteSpace ([\n\r\t ])
Comment (\/\/[^\r\n]*(\r|\n|\r\n)?)
CompOp ((<=)|(>=)|(<)|(>))
Equality ((==)|(\!=))
Id ([a-zA-Z][a-zA-Z0-9]*)
Num (0|[1-9][0-9]*)
STR (\"([^\n\r\"\\]|\\[rnt\"\\])+\")
%%
void  return VOID;
int   return INT;
byte  return BYTE;
b     return B;
bool  return BOOL;
and   return AND;
or    return OR;
not   return NOT;
true  {
    yylval = new Symbol("BOOL", "BOOL");
    return TRUE;
    }
false {
    yylval = new Symbol("BOOL", "BOOL");
    return FALSE;
    }
return return RETURN;
if return IF;
else  return ELSE;
while return WHILE;
break  return BREAK;
continue return CONTINUE;
; return SC;
\( return LPAREN;
\) return RPAREN;
\{ return LBRACE;
\} return RBRACE;
= return ASSIGN;
\* return MUL;
\- return SUB;
\+ return ADD;
\/ return DIV;
{Comment} ;
{whiteSpace} ;


{Equality} {
    yylval = new Symbol(yytext, yytext);
    return EQUALITY;
}

{CompOp} {
    yylval = new Symbol(yytext, yytext);
	return NONASSOCCRELOP;
}

{Id} {
    yylval = new Symbol(yytext, yytext);
    return ID;
}

{Num} {
    yylval = new Num(yytext, atoi(yytext));
    return NUM;
}

{STR} {
    yylval = new myString(yytext, yytext);
    return STRING;
}

.	{output::errorLex(yylineno); exit(0);}
%%
