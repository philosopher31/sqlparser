#ifndef __INSERT_STATEMENT_H__
#define __INSERT_STATEMENT_H__

#include "SQLStatement.h"
#include "SelectStatement.h"

namespace sql {
   
    struct InsertStatement : SQLStatement {
        enum InsertType {
            kInsertValues,
            kInsertSelect
        };

        InsertStatement(InsertType type) :
            SQLStatement(kStmtInsert),
            type(type),
            tableName(NULL),
            columns(NULL),
            values(NULL),
            select(NULL) {}

        virtual ~InsertStatement() {
            delete tableName;
            delete columns;
            delete values;
            delete select;
        }

        InsertType type;
        const char* tableName;
        std::vector<char*>* columns;
        std::vector<Expr*>* values;
        SelectStatement* select;
    };

} // namsepace sql
#endif