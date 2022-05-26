#ifndef QUINE_H
#define QUINE_H

//------Includes
#include "types.h"

//------Functions
bool quine(CNF* formula, int** val, int n);
void use_quine(CNF* formula, bool verbose);

#endif