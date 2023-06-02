#pragma once

#include "node/node.h"
#include "../utils/utils.h"

void initialize(void);
void terminate(void);
void insert(nodeType, keyType, valueType);
valueType lookup(nodeType, keyType);
valueType smartLookup(nodeType, keyType);