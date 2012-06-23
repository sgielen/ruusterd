#include "resultset.hpp"

namespace ruuster
{
	namespace mysql
	{
		bool resultset::next() const
		{
			return data->next();
		}
		
		std::string resultset::get_string(const std::string col) const
		{
			return data->getString(col);
		}
	}
}
