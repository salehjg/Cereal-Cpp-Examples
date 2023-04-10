#include <iostream>
#include <memory>
#include <fstream>

#include "CSymbolic.h"
#include "CSymbol.h"
#include "CConst.h"
#include "CSymLink.h"

#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/memory.hpp>

using namespace std;
using CSymbolicPtr = shared_ptr<CSymbolic>;

CEREAL_REGISTER_TYPE(CSymbol)
CEREAL_REGISTER_TYPE(CConst)
CEREAL_REGISTER_TYPE(CSymLink)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CSymbolic, CSymbol)  // not needed
CEREAL_REGISTER_POLYMORPHIC_RELATION(CSymbolic, CConst)   // not needed
CEREAL_REGISTER_POLYMORPHIC_RELATION(CSymbolic, CSymLink) // not needed

vector<CSymbolicPtr> GetTestVec() {
	vector< CSymbolicPtr > vec;
	vec.push_back(make_shared<CSymbol>(0, 0));
	vec.push_back(make_shared<CConst>(1, 1, 1.5f));
	vec.push_back(make_shared<CSymLink>(2, 2));
	return vec;
}

void TestCase01(){
	std::cout << "TestCase01\n";
	{
		std::ofstream os("data.json");
		auto vec = GetTestVec(); 
		cereal::JSONOutputArchive arout(os);
		arout(vec);
	}

	//std::cout << ss.str() << endl;
	{
		std::ifstream is("data.json");
		cereal::JSONInputArchive arin(is);
		vector< CSymbolicPtr > vecR;
		arin(vecR);
		for (CSymbolicPtr ptr : vecR) {
			std::cout << ptr->GetType() << endl;
		}
	}
}


int main()
{
	TestCase01();
}
