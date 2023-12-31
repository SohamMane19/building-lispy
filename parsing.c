#include<stdio.h>
#include "mpc.h"
/* Declare a buffer for user input of size 2048 */
static char input[2048];

int main(int argc,char** argv)
{
	/* Create Some Parsers */
	mpc_parser_t* Number   = mpc_new("number");
	mpc_parser_t* Operator = mpc_new("operator");
	mpc_parser_t* Expr     = mpc_new("expr");
	mpc_parser_t* Lispy    = mpc_new("lispy");

	/* Define them with the following Language */
	mpca_lang(MPCA_LANG_DEFAULT,
	  "                                                     \
	    number   : /-?[0-9]+/ ;                             \
	    operator : '+' | '-' | '*' | '/' ;                  \
	    expr     : <number> | '(' <operator> <expr>+ ')' ;  \
	    lispy    : /^/ <operator> <expr>+ /$/ ;             \
	  ",
	  Number, Operator, Expr, Lispy);

	puts("2023 Developed by Soham Mane");
	puts("LispScript Version 0.0.1");
	puts("Press Ctrl+c to Exit");
	puts("############################\n");
	while(1)
	{
		fputs("LispScript>>",stdout);
		fgets(input,2048,stdin);
		 /* Attempt to parse the user input */
		mpc_result_t r;
		if(mpc_parse("<stdin>",input,Lispy,&r))
		{
			 /* On success print and delete the AST */
			mpc_ast_print(r.output);
			mpc_ast_delete(r.output);
		}
		else
		{
			 /* Otherwise print and delete the Error */
			mpc_err_print(r.error);
			mpc_err_delete(r.error);
		}
		free(input);
	}
	mpc_cleanup(4, Number, Operator, Expr, Lispy);
	return 0;
}