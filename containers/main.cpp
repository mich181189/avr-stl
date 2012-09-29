#include <stdlib.h>

#include "vector.h"

int main()
{
	std::vector<int> nVec;
	std::vector<char> cVec;
	std::vector<float> fVec;
	int n = nVec.size();
	n += cVec.size();
	n += fVec.size();
	return n;
}

void operator delete(void * p) // or delete(void *, std::size_t)
{
  free(p);
}

void * operator new(size_t size)
{
  return malloc(size);
}
