#include "stdafx.h"
#include "OPGAnalyzer.h"


OPGAnalyzer::OPGAnalyzer()
{
}

OPGAnalyzer::OPGAnalyzer(std::string expressions):
	buffer(expressions),
	analyzing("#"),
	readPtr(0),
	records() 
{

}


OPGAnalyzer::~OPGAnalyzer()
{
}

OPGAnalyzer::Relation OPGAnalyzer::getPrecedence(char a, char b)
{
	return precedenceTable[m[a]][m[b]];
}

void OPGAnalyzer::analyze()
{
	while (readPtr < buffer.size())
	{
		records.push_back(singleAnalyze());
	}
}

OPGAnalyzer::OperationRecord OPGAnalyzer::singleAnalyze()
{
	if (readPtr >= buffer.size())
		return OperationRecord();
	char ch = buffer[readPtr];

}


