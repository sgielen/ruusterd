#pragma once

#include <string>
#include <memory>

#include <cppconn/resultset.h>

namespace ruuster
{
	namespace mysql
	{
		class resultset
		{
		private:
			std::unique_ptr<sql::ResultSet> data;
		
		public:
			resultset(sql::ResultSet* data)
			: data(data)
			{}
			
			bool next() const;
			
			std::string get_string(const std::string col) const;
		};
	}
}
