#include <torch/torch.h>
#include "c10_scalar.h"

int scalarIsFloatingPoint(Scalar* scalar) {
  auto *p = (c10::Scalar *)scalar;
  return (int)p->isFloatingPoint();
}

int scalarIsIntegral(Scalar* scalar) {
  auto *p = (c10::Scalar *)scalar;
  return (int)p->isIntegral();
}

int scalarIsComplex(Scalar* scalar) {
  auto *p = (c10::Scalar *)scalar;
  return (int)p->isComplex();
}

int32_t scalarToInt32(Scalar* scalar) {
  auto *p = (c10::Scalar *)scalar;
  return p->to<int32_t>();
}

int64_t scalarToInt64(Scalar* scalar) {
  auto *p = (c10::Scalar *)scalar;
  return p->to<int64_t>();
}

float scalarToFloat(Scalar* scalar) {
  auto *p = (c10::Scalar *)scalar;
  return p->to<float>();
}

double scalarToDouble(Scalar* scalar) {
  auto *p = (c10::Scalar *)scalar;
  return p->to<double>();
}
