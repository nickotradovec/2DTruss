#include "stdafx.h"
#include <math.h>

using namespace std;
using namespace Eigen;
using std::vector;

void ProcessElement(StructureElement structElement, vector<StructureNode> vctNodes, MatrixXf mtxK)
{
    float dx = vctNodes[structElement.intNode2ID].fltX - vctNodes[structElement.intNode1ID].fltX; // always in this order
    float dy = vctNodes[structElement.intNode2ID].fltY - vctNodes[structElement.intNode1ID].fltY;

    

};



MatrixXf AssembleMatrix(vector<StructureNode> vctNodes, vector<StructureElement> vctElements)
{
    int nodeCount = static_cast<int>(vctNodes.size());
	MatrixXf mtxReturn = MatrixXf(2 * nodeCount, 2 * nodeCount);

    for (int i = 0; i < vctElements.size(); i++)
    {
        ProcessElement(vctElements[i], vctNodes, mtxReturn);
    }

    return mtxReturn;
};