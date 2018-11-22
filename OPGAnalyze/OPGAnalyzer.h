#pragma once
#include <string>
#include <map>
#include <vector>

class OPGAnalyzer
{
public:
	enum Relation
	{
		PRECEDE,
		INFERIOR,
		EQUAL,
		UNDEFINED
	};
	OPGAnalyzer();
	OPGAnalyzer(std::string expressions);
	virtual ~OPGAnalyzer();

	Relation getPrecedence(char a, char b);
	class OperationRecord
	{
	public:
		OperationRecord(){}
		OperationRecord(int stepNumber, char chRead, int readPtr, std::string analyzeStack, Relation relation, std::string action):
			stepNumber(stepNumber),
			chRead(chRead),
			readPtr(readPtr),
			analyzeStack(analyzeStack),
			relation(relation),
			action(action)
		{
			//Empty constructor body
		}

		~OperationRecord(){}

		int stepNumber;
		char chRead;
		int readPtr;
		std::string analyzeStack;
		Relation relation;
		std::string action;
		
	};

	void analyze();
	OperationRecord singleAnalyze();

private:
	std::string buffer;
	std::string analyzing;
	int readPtr;
	std::vector<OperationRecord> records;
	Relation precedenceTable[6][6] = {
		PRECEDE, INFERIOR, INFERIOR, INFERIOR, PRECEDE, PRECEDE,
		PRECEDE, PRECEDE, INFERIOR, INFERIOR, PRECEDE, PRECEDE,
		PRECEDE, PRECEDE, UNDEFINED, UNDEFINED, PRECEDE, PRECEDE,
		INFERIOR, INFERIOR, INFERIOR, INFERIOR, EQUAL, UNDEFINED,
		PRECEDE, PRECEDE, UNDEFINED, UNDEFINED, PRECEDE, PRECEDE,
		INFERIOR, INFERIOR, INFERIOR, INFERIOR, UNDEFINED, UNDEFINED
	};

	std::map<char, int> m = { {'+', 0}, {'*', '1'}, {'i', 2}, {'(', 3}, {')', 4}, {'#', 5} };
};

