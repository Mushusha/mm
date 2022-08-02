#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int Input(const char *filename, char (***array), int *size);
int part (char **arr, int n, int m);
char* statk(char **arr, int k, int size); 
