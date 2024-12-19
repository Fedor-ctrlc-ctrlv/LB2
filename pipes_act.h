#pragma once
#include "pipe.h"
#include <unordered_map>
#include <unordered_set>
using namespace std;

void ChangePipesRepair(unordered_map<int, Pipe>& spisok_pipe, const unordered_set<int>& spisok_pipe_vibr);