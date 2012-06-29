#include <iostream>

#include "storage/storage.hpp"

int main(int argc, char **argv)
{
	ruuster::storage s("tcp://localhost:3306", "test", "test", "ruusternltrunk");

	return 0;
}
