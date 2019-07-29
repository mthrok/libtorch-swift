#ifndef __SWITCH_C10_SCALAR_H
#define __SWITCH_C10_SCALAR_H

#include "typedefs.h"

#ifdef __cplusplus
extern "C" {
#endif
  int scalarIsFloatingPoint(Scalar*);
  int scalarIsIntegral(Scalar*);
  int scalarIsComplex(Scalar*);

  int32_t scalarToInt32(Scalar*);
  int64_t scalarToInt64(Scalar*);
  float scalarToFloat(Scalar*);
  double scalarToDouble(Scalar*);

#ifdef __cplusplus
}
#endif

#endif
