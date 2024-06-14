#pragma once
#include "../DataStructures/Vector.h"
#include "TestMacros.h"
#include "../DataTypes/Complex.h"

void testVector();
void testIntegerVectorSizeConstructor();
void testIntegerVectorItemsConstructor();
void testIntegerVectorCopyConstructor();
void testIntegerVectorEqualsOperator();
void testIntegerVectorAssignmentOperator();
void testIntegerVectorGetters();
void testIntegerVectorSetters();
void testIntegerVectorAddition();
void testIntegerVectorMultiplicationByScalar();
void testIntegerVectorNorm();
void testIntegerVectorScalarMultiplication();

void testComplexVectorItemsConstructor();
void testComplexVectorCopyConstructor();
void testComplexVectorEqualsOperator();
void testComplexVectorAssignmentOperator();
void testComplexVectorGetters();
void testComplexVectorSetters();
void testComplexVectorAddition();
void testComplexVectorMultiplicationByScalar();
void testComplexVectorNorm();
void testComplexVectorScalarMultiplication();

int intSquareRoot(const int &);
int getIntegerZero();
int getIntegerOne();
const dt::Complex getComplexZero();

const dt::Complex getComplexOne();