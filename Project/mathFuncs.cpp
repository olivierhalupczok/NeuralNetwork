#include <math.h>

#include "mathFuncs.h"

double sigmoid(double arg)
{
    return 1 / (1 + std::exp(-arg));
}
