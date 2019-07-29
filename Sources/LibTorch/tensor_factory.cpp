#include <torch/torch.h>
#include "tensor_factory.h"

extern "C" {

Tensor* zeros(long* sizes, uint64_t length) {
  using std::swap;

  auto t = at::zeros(c10::IntArrayRef(sizes, length));
  torch::Tensor* p = new torch::Tensor();
  std::swap(t, *p);
  return (Tensor*) p;
}

Tensor* ones(long* sizes, uint64_t length) {
  using std::swap;

  auto t = at::ones(c10::IntArrayRef(sizes, length));
  torch::Tensor* p = new torch::Tensor();
  std::swap(t, *p);
  return (Tensor*) p;
}

Tensor* randn(long* sizes, uint64_t length) {
  using std::swap;

  auto t = torch::randn(c10::IntArrayRef(sizes, length));
  torch::Tensor *p = new torch::Tensor();
  std::swap(t, *p);
  return (Tensor*) p;
}

Tensor* randint(int64_t low, int64_t high, long* sizes, uint64_t length) {
  using std::swap;

  auto t = torch::randint(low, high, c10::IntArrayRef(sizes, length));
  torch::Tensor *p = new torch::Tensor();
  std::swap(t, *p);
  return (Tensor*) p;
}
}
