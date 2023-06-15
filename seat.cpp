#include "planeClass.h"

void seat::setR(int r) { row = r; }
void seat::setC(int c) { column = c; }
void seat::setReserved(bool v) { reserved = v; }
int seat::getR() { return row; }
char seat::getC() { return column; }
bool seat::getReserved() { return reserved; }
