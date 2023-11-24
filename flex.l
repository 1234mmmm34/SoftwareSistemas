%{

%}


%%
xxa*bb {printf("\nVlida\n");}
.      {printf("\nInvalida\n");}
\n     {return 0;}
("("|"")[0-9][0-9][0-9](")"|"")(-|"")[0-9][0-9][0-9](-|"")[0-9][0-9][0-9][0-9] {printf("\nNumero Valido");}

%%

yywrap(){}
int main(){

yylex();

return 0;
}
