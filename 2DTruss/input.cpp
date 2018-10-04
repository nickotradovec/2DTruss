#include "stdafx.h"
using namespace std;

bool GetYN(string strQuestion);
void CreateData(vector<StructureNode> vctNodes, vector<StructureElement> vctElements);
int CreatePredefinedStructure(vector<StructureNode> vctNodes, vector<StructureElement> vctElements);
void CreateStructureFromUser(vector<StructureNode> vctNodes, vector<StructureElement> vctElements);
int GetPredefinedStructure();

void CreatePredefinedBoundaryConditions(vector<StructureNode> vctNodes, int intStructure);
void CreateBoundaryConditionsFromUser(vector<StructureNode> vctNodes);

void CreateData(vector<StructureNode> vctNodes, vector<StructureElement> vctElements)
{
	bool blnPredefinedStructure = GetYN("Would you like to use a predefined Structure?");
	int intPredefinedStructure = -1;

	if (blnPredefinedStructure) 
	{ 
		intPredefinedStructure = CreatePredefinedStructure(vctNodes, vctElements);

		bool blnPredefinedBoundaryConditions = GetYN("Would you like to use predefined boundary conditions?");
		if (blnPredefinedBoundaryConditions) { CreatePredefinedBoundaryConditions(vctNodes, intPredefinedStructure); }
		else { CreateBoundaryConditionsFromUser(vctNodes); }
	}
	else 
	{
		CreateStructureFromUser(vctNodes, vctElements);
		CreateBoundaryConditionsFromUser(vctNodes); 
	}

	// save data option to export to XML?
}

bool GetYN(string strQuestion)
{
	string response;
	do
	{
		cout << strQuestion << " (y/n)" <<endl;
		getline(cin, response);
		//transform(response.begin(), response.end(), response.begin(), ::tolower);
		
		if (response == "y") { return true; }
		else if (response == "n") { return false; }		
		else { cout << "Invalid response, please try again. "; }
	}
	while (true);
};

int CreatePredefinedStructure(vector<StructureNode> vctNodes, vector<StructureElement> vctElements)
{
	int intPredefined = GetPredefinedStructure();

	// store these in xml files later on so that they may be mroe configurable and extensive.
	switch (intPredefined)
	{
		case 1 : 	
					//StructureNode sn = {0.0, 0.0;};
					
					vctNodes.push_back(StructureNode(0.0, 0.0)); // Node 0
					vctNodes.push_back(StructureNode(4.0, 0.0)); // Node 1
					vctNodes.push_back(StructureNode(2.0, 4.0)); // Node 2

					vctElements.push_back(StructureElement(0,1));
					vctElements.push_back(StructureElement(1,2));
					vctElements.push_back(StructureElement(0,2));
					break;

		case 2 : 	vctNodes.push_back(StructureNode(0.0, 0.0)); // Node 0
					vctNodes.push_back(StructureNode(4.0, 0.0)); // Node 1
					vctNodes.push_back(StructureNode(4.0, 4.0)); // Node 2
					vctNodes.push_back(StructureNode(0.0, 4.0)); // Node 3

					vctElements.push_back(StructureElement(0, 1));
					vctElements.push_back(StructureElement(1, 2));
					vctElements.push_back(StructureElement(2, 3));
					vctElements.push_back(StructureElement(1, 3));
					vctElements.push_back(StructureElement(2, 0));
					break;

		default : cout << "Could not find structure." << endl;
	}

	return intPredefined;
};

int GetPredefinedStructure()
{
	string response;
	do
	{
		cout << "Please select one of the following structures by entering the associated number." << endl;
		cout << "1 - Simple Triangle" << endl << "2 - Cross Braced Square" << endl;
		getline(cin, response);

		if (response == "1") { return 1; }
		else if (response == "2") { return 2; }
		else { cout << "Invalid response, please try again. "; }
	}
	while (true);
};

void CreateStructureFromUser(vector<StructureNode> vctNodes, vector<StructureElement> vctElements)
{
	throw "Not yet implemented";
};

void CreatePredefinedBoundaryConditions(vector<StructureNode> vctNodes, int intStructure)
{
	// Set Degrees of freedom for nodes. for both cases, we'll set the bottom two nodes as fixed.
	switch(intStructure)
	{
		case 1 : 	vctNodes[0].blnDOFX = false;
					vctNodes[0].blnDOFY = false;
					vctNodes[1].blnDOFX = false;
					vctNodes[1].blnDOFY = false;

					vctNodes[2].fltForceExternalX = 1;
					vctNodes[2].fltForceExternalY = 10;
					break;

		case 2 : 	vctNodes[0].blnDOFX = false;
					vctNodes[0].blnDOFY = false;
					vctNodes[1].blnDOFX = false;
					vctNodes[1].blnDOFY = false;

					vctNodes[3].fltForceExternalX = 1;
					vctNodes[3].fltForceExternalY = 10;
					break;

		default : throw "not configured";
	}

	// Set the external forces
	switch(intStructure)
	{
		case 1 :	vctNodes[2].fltForceExternalX = 10;
		case 2 :	vctNodes[3].fltForceExternalX = 10;
		default : 	throw "not configured";
	}
};

void CreateBoundaryConditionsFromUser(vector<StructureNode> vctNodes)
{
	throw "Not yet implemented";
};
