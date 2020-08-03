#pragma once
#ifndef cidea_value_h
#define cidea_value_H

#include "common.h"

// store the constants
typedef double Value;

typedef struct
{
	int capacity;
	int count;
	Value* values;
} ValueArray;

void initValueArray(ValueArray* array);

void writeValueArray(ValueArray* array, Value value);

void freeValueArray(ValueArray* array);

void printValue(Value value);
#endif

