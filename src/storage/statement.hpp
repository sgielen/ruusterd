#pragma once

#include <memory>
#include <cppconn/prepared_statement.h>

#include "resultset.hpp"

namespace ruuster
{
	namespace mysql
	{
		class statement
		{
		private:
			std::unique_ptr<sql::PreparedStatement> stmt;
			
		public:
			statement(sql::PreparedStatement* stmt)
			: stmt(stmt)
			{}
			
			void set(const size_t i, const std::string value) const;
			
			bool execute() const;
			int update() const;
			resultset query() const;
		};
	}
}
