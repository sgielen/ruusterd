#include "statement.hpp"

namespace ruuster
{
	namespace mysql
	{
		void statement::set(const size_t i, const std::string value) const
		{
			stmt->setString(i, value);
		}
			
		bool statement::execute() const
		{
			return stmt->execute();
		}
		
		int statement::update() const
		{
			return stmt->executeUpdate();
		}
		
		resultset statement::query() const
		{
			return resultset(stmt->executeQuery());
		}
	}
}
