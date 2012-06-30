#include <iostream>

#include "storage.hpp"

int main(int argc, char **argv)
{
	ruuster::storage s("tcp://localhost:3306", "test", "test", "ruusternltrunk");

	const auto rev = s.fetch_latest_revision(1);
	if(rev)
		std::cout << "Latest revision for institute 1: " << rev.get() << std::endl;
	else
		std::cout << "No revisions found :(" << std::endl;

	return 0;
}
