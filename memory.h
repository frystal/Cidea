#pragma once
#ifndef cidea_memory_h
#define cidea_memory_h

#include "common.h"
#include "object.h"

#define STEP 8

#define ALLOCATE(type, count)       (type*)reallocate(NULL, 0, sizeof(type) * (count))
// grow factor common for 2 or 1.5
#define GROW_CAPACITY(capacity)     ((capacity) < 8 ? 8 : (capacity) * 2)

#define FREE(type, pointer) reallocate(pointer, sizeof(type), 0)

#define GROW_ARRAY(type, pointer, oldCount, newCount)       (type*)reallocate(pointer, sizeof(type) * (oldCount), sizeof(type) * (newCount))

#define FREE_ARRAY(type, pointer, oldCount)		reallocate(pointer, sizeof(type) * (oldCount), 0)

// do the basic memory work
void* reallocate(void* pointer, size_t oldSize, size_t newSize);
void markObject(Obj* object);
void markValue(Value value);
void collectGarbage();
void freeObjects();

#endif