#include <torch/torch.h>
#include "c10_tensor_options.h"


TensorOptions* newTensorOptions() {
  auto *p = new c10::TensorOptions();
  return (TensorOptions*) p;
}

void deleteTensorOptions(TensorOptions* opt) {
  auto* p = (c10::TensorOptions*) opt;
  delete p;
}

TensorOptions* newTensorOptionsFromDtypeInt32() {
  using std::swap;
  auto opt = c10::TensorOptions().dtype(caffe2::TypeMeta::Make<int32_t>());
  auto *p = new c10::TensorOptions();
  swap(opt, *p);
  return (TensorOptions*) p;
}

TensorOptions* newTensorOptionsFromDtypeInt64() {
  using std::swap;
  auto opt = c10::TensorOptions().dtype(caffe2::TypeMeta::Make<int64_t>());
  auto *p = new c10::TensorOptions();
  swap(opt, *p);
  return (TensorOptions*) p;
}

TensorOptions* newTensorOptionsFromDtypeFloat() {
  using std::swap;
  auto opt = c10::TensorOptions().dtype(caffe2::TypeMeta::Make<float>());
  auto *p = new c10::TensorOptions();
  swap(opt, *p);
  return (TensorOptions*) p;
}

TensorOptions* newTensorOptionsFromDtypeDouble() {
  using std::swap;
  auto opt = c10::TensorOptions().dtype(caffe2::TypeMeta::Make<double>());
  auto *p = new c10::TensorOptions();
  swap(opt, *p);
  return (TensorOptions*) p;
}
