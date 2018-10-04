#ifndef FEADATA_HPP
#define FEADATA_HPP

struct StructureNode
{	
	StructureNode(float x, float y) : fltX(x), fltY(y), blnDOFX(true), blnDOFY(true) {};
	float fltX;
	float fltY;
	bool blnDOFX;
	bool blnDOFY;
	float fltForceExternalX;
	float fltForceExternalY;
};

struct StructureElement
{
	StructureElement(int int1, int int2) : intNode1ID(int1), intNode2ID(int2) {}
	float fltStiffness;
	int intNode1ID;
	int intNode2ID;
};

#endif