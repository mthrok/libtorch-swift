#include "c10_tensor_options.h"
#include <c10/core/TensorOptions.h>

using std::swap;


TensorOptions* newTensorOptions() {
  auto *p = new c10::TensorOptions();
  return (TensorOptions*) p;
}

void deleteTensorOptions(TensorOptions* opt) {
  auto* p = (c10::TensorOptions*) opt;
  delete p;
}

Dtype* tensorOptionsDtype(TensorOptions* opt) {
  auto dtype = ((c10::TensorOptions*) opt)->dtype();
  auto *p = new caffe2::TypeMeta();
  swap(dtype, *p);
  return (Dtype *) p;
}

TensorOptions* newTensorOptionsFromDtypeInt32() {
  auto opt = c10::TensorOptions().dtype(caffe2::TypeMeta::Make<int32_t>());
  auto *p = new c10::TensorOptions();
  swap(opt, *p);
  return (TensorOptions*) p;
}

TensorOptions* newTensorOptionsFromDtypeInt64() {
  auto opt = c10::TensorOptions().dtype(caffe2::TypeMeta::Make<int64_t>());
  auto *p = new c10::TensorOptions();
  swap(opt, *p);
  return (TensorOptions*) p;
}

TensorOptions* newTensorOptionsFromDtypeFloat() {
  auto opt = c10::TensorOptions().dtype(caffe2::TypeMeta::Make<float>());
  auto *p = new c10::TensorOptions();
  swap(opt, *p);
  return (TensorOptions*) p;
}

TensorOptions* newTensorOptionsFromDtypeDouble() {
  auto opt = c10::TensorOptions().dtype(caffe2::TypeMeta::Make<double>());
  auto *p = new c10::TensorOptions();
  swap(opt, *p);
  return (TensorOptions*) p;
}
