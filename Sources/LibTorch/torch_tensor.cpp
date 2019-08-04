#include <torch/torch.h>

#include "torch_tensor.h"

using std::swap;

////////////////////////////////////////////////////////////////////////////////
// Tensor Attributes
////////////////////////////////////////////////////////////////////////////////
int64_t tensorDim(Tensor* t) {
  torch::Tensor *tensor = (torch::Tensor*) t;
  return tensor->dim();
}

void tensorSizes(Tensor* tensor, uint64_t* values) {
  auto s = ((torch::Tensor*)tensor)->sizes();
  for (uint64_t i = 0; i < s.size(); i++) {
    values[i] = s[i];
  }
}

TensorOptions* tensorOptions(Tensor* tensor) {
  auto opt = ((torch::Tensor*)tensor)->options();
  auto *p = new c10::TensorOptions();
  swap(opt, *p);
  return (TensorOptions*) p;
}

Dtype* tensorDtype(Tensor* tensor) {
  auto dtype = ((torch::Tensor*)tensor)->dtype();
  auto *p = new caffe2::TypeMeta();
  swap(dtype, *p);
  return (Dtype*) p;
}

int tensorIsCuda(Tensor* tensor) {
  auto p = (torch::Tensor*)tensor;
  return (int)p->is_cuda();
}

int tensorIsHip(Tensor* tensor) {
  auto p = (torch::Tensor*)tensor;
  return (int)p->is_hip();
}

int tensorIsSparse(Tensor* tensor) {
  auto p = (torch::Tensor*)tensor;
  return (int)p->is_sparse();
}

int tensorIsMkldnn(Tensor* tensor) {
  auto p = (torch::Tensor*)tensor;
  return (int)p->is_mkldnn();
}

int tensorIsQuantized(Tensor* tensor) {
  auto p = (torch::Tensor*)tensor;
  return (int)p->is_quantized();
}

////////////////////////////////////////////////////////////////////////////////
// Accessors
////////////////////////////////////////////////////////////////////////////////
TensorAccessor* tensorAccessorFloat1(Tensor* tensor) {
  auto a = ((torch::Tensor*)tensor)->accessor<float, 1>();
  at::TensorAccessor<float, 1> *p = new at::TensorAccessor<float, 1>(nullptr, nullptr, nullptr);
  using std::swap;
  swap(a, *p);
  return (TensorAccessor*) p;
}

TensorAccessor* tensorAccessorFloat2(Tensor* tensor) {
  auto a = ((torch::Tensor*)tensor)->accessor<float, 2>();
  at::TensorAccessor<float, 2> *p = new at::TensorAccessor<float, 2>(nullptr, nullptr, nullptr);
  using std::swap;
  swap(a, *p);
  return (TensorAccessor*) p;
}

TensorAccessor* tensorAccessorFloat3(Tensor* tensor) {
  auto a = ((torch::Tensor*)tensor)->accessor<float, 3>();
  at::TensorAccessor<float, 3> *p = new at::TensorAccessor<float, 3>(nullptr, nullptr, nullptr);
  using std::swap;
  swap(a, *p);
  return (TensorAccessor*) p;
}

TensorAccessor* tensorAccessorDouble1(Tensor* tensor) {
  auto a = ((torch::Tensor*)tensor)->accessor<double, 1>();
  at::TensorAccessor<double, 1> *p = new at::TensorAccessor<double, 1>(nullptr, nullptr, nullptr);
  using std::swap;
  swap(a, *p);
  return (TensorAccessor*) p;
}

TensorAccessor* tensorAccessorDouble2(Tensor* tensor) {
  auto a = ((torch::Tensor*)tensor)->accessor<double, 2>();
  at::TensorAccessor<double, 2> *p = new at::TensorAccessor<double, 2>(nullptr, nullptr, nullptr);
  using std::swap;
  swap(a, *p);
  return (TensorAccessor*) p;
}

TensorAccessor* tensorAccessorDouble3(Tensor* tensor) {
  auto a = ((torch::Tensor*)tensor)->accessor<double, 3>();
  at::TensorAccessor<double, 3> *p = new at::TensorAccessor<double, 3>(nullptr, nullptr, nullptr);
  using std::swap;
  swap(a, *p);
  return (TensorAccessor*) p;
}

Scalar* tensorItem(Tensor* tensor) {
  auto val = ((torch::Tensor*) tensor)->item();
  c10::Scalar *p = new c10::Scalar();
  swap(val, *p);
  return (Scalar*) p;
}

Tensor* tensorIndex(Tensor* tensor, int64_t index) {
  auto t = (*((torch::Tensor*) tensor))[index];
  torch::Tensor *p = new torch::Tensor();
  swap(t, *p);
  return (Tensor*) p;
}

Tensor* tensorSlice(Tensor* tensor, int64_t dim, int64_t start, int64_t end, int64_t step)  {
  auto t = ((torch::Tensor*) tensor)->slice(dim, start, end, step);
  torch::Tensor *p = new torch::Tensor();
  swap(t, *p);
  return (Tensor*) p;
}

int tensorIsSame(Tensor* tensor1, Tensor* tensor2) {
  torch::Tensor *p1 = (torch::Tensor*) tensor1;
  torch::Tensor *p2 = (torch::Tensor*) tensor2;
  return (int)p1->is_same(*p2);
}


////////////////////////////////////////////////////////////////////////////////
// Operator Overloads
////////////////////////////////////////////////////////////////////////////////
Tensor* tensorAdd(Tensor* tensor1, Tensor* tensor2) {
  torch::Tensor *p1 = (torch::Tensor*) tensor1;
  torch::Tensor *p2 = (torch::Tensor*) tensor2;

  auto t = (*p1) + (*p2);
  torch::Tensor *p = new torch::Tensor();
  swap(t, *p);
  return (Tensor*) p;
}

Tensor* tensorEqual(Tensor* tensor1, Tensor* tensor2) {
  torch::Tensor *p1 = (torch::Tensor*) tensor1;
  torch::Tensor *p2 = (torch::Tensor*) tensor2;

  auto t = p1->eq(*p2);
  torch::Tensor *p = new torch::Tensor();
  swap(t, *p);
  return (Tensor*) p;
}
