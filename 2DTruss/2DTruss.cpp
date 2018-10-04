#include "stdafx.h"
#include "input.cpp"
#include "assemble.cpp"

using namespace std;
using namespace Eigen;
using std::vector;

int _tmain(int argc, _TCHAR* argv[])
{		
	vector<StructureNode> vctNodes;
	vector<StructureElement> vctElements;
	CreateData(vctNodes, vctElements);

	MatrixXf mtxK = AssembleMatrix(vctNodes, vctElements);
	

	// Solve k matrix
	// Output results

	return 0;
};
