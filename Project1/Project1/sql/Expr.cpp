
#include "Expr.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>
#pragma warning(disable:4996)

#define _SCL_SECURE_NO_WARNINGS

namespace sql {

	char* substr(const char* source, int from, int to) {
		int len = to - from;
		char* copy = new char[len + 1];
		strncpy(copy, source + from, len);
		copy[len] = '\0';
		return copy;
	}

	Expr* Expr::makeOpUnary(OperatorType op, Expr* expr) {
		Expr* e = new Expr(kExprOperator);
		e->op_type = op;
		e->expr = expr;
		e->expr2 = NULL;
		return e;
	}



	Expr* Expr::makeOpBinary(Expr* expr1, OperatorType op, Expr* expr2) {
		Expr* e = new Expr(kExprOperator);
		e->op_type = op;
		e->op_char = 0;
		e->expr = expr1;
		e->expr2 = expr2;
		return e;
	}

	Expr* Expr::makeOpBinary(Expr* expr1, char op, Expr* expr2) {
		Expr* e = new Expr(kExprOperator);
		e->op_type = SIMPLE_OP;
		e->op_char = op;
		e->expr = expr1;
		e->expr2 = expr2;
		return e;
	}



	Expr* Expr::makeLiteral(int64_t val) {
		Expr* e = new Expr(kExprLiteralInt);
		e->ival = val;
		return e;
	}

	Expr* Expr::makeLiteral(char* string) {
		Expr* e = new Expr(kExprLiteralString);
		e->name = string;
		return e;
	}


	Expr* Expr::makeColumnRef(char* name) {
		Expr* e = new Expr(kExprColumnRef);
		e->name = name;
		return e;
	}

	Expr* Expr::makeColumnRef(char* table, char* name) {
		Expr* e = new Expr(kExprColumnRef);
		e->name = name;
		e->table = table;
		return e;
	}

	

}