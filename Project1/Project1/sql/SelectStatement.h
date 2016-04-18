#ifndef __SELECT_STATEMENT_H__
#define __SELECT_STATEMENT_H__

#include "SQLStatement.h"
#include "Expr.h"
#include "Table.h"

namespace sql {

	struct AggregationFunction {
		typedef enum {
			kSum,
			kCount
		} AggregationType;

		AggregationFunction(AggregationType type,char* attribute) :
			attribute(attribute),
			type(type){}
		AggregationFunction(AggregationType type,char* tableName, char* attribute) :
			tableName(tableName),
			attribute(attribute),
			type(type) {}
		inline bool hasTableName() {
			return IsTableName;
		}

		virtual ~AggregationFunction() {
			delete attribute;
		}
		char* attribute;
		char* tableName;
		AggregationType type;
		bool IsTableName = false;
	};
	struct SelectStatement : SQLStatement {
		SelectStatement() :
			SQLStatement(kStmtSelect),
			fromTable(NULL),
			selectList(NULL),
			whereClause(NULL) {};

		virtual ~SelectStatement() {
			delete fromTable;
			delete selectList;
			delete whereClause;
		}
		std::vector<AggregationFunction*>* aggregation_list;
		std::vector<TableRef*>* fromTable;
		std::vector<Expr*>* selectList;
		Expr* whereClause;
		bool IsAggregationExist = false;
		bool IsSelectListExist = false;
		
		inline bool hasAggregation(){
			return IsAggregationExist;
		}
		inline bool hasSelect() {
			return IsSelectListExist;
		}
		inline bool hasWhere() {
			if (whereClause == NULL)
				return false;
			else
				return true;
		}
	};
}
#endif