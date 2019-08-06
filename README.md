# Switch (Swift LibTorch Wrapper)

This is some experimental attempt to wrap LibTorch, PyTorch's C++ API, with Swift.

# Why
It's one of my random Sunday afternoon project, in which I am learning something new, so not much reason or discussion of pros/cons.

# Goal

The goal of this project is to reproduce <Details><Summary>[the C++ end-to-end example](https://pytorch.org/cppdocs/frontend.html#end-to-end-example)</Summary>

```
#include <torch/torch.h>

// Define a new Module.
struct Net : torch::nn::Module {
  Net() {
    // Construct and register two Linear submodules.
    fc1 = register_module("fc1", torch::nn::Linear(784, 64));
    fc2 = register_module("fc2", torch::nn::Linear(64, 32));
    fc3 = register_module("fc3", torch::nn::Linear(32, 10));
  }

  // Implement the Net's algorithm.
  torch::Tensor forward(torch::Tensor x) {
    // Use one of many tensor manipulation functions.
    x = torch::relu(fc1->forward(x.reshape({x.size(0), 784})));
    x = torch::dropout(x, /*p=*/0.5, /*train=*/is_training());
    x = torch::relu(fc2->forward(x));
    x = torch::log_softmax(fc3->forward(x), /*dim=*/1);
    return x;
  }

  // Use one of many "standard library" modules.
  torch::nn::Linear fc1{nullptr}, fc2{nullptr}, fc3{nullptr};
};

int main() {
  // Create a new Net.
  auto net = std::make_shared<Net>();

  // Create a multi-threaded data loader for the MNIST dataset.
  auto data_loader = torch::data::make_data_loader(
      torch::data::datasets::MNIST("./data").map(
          torch::data::transforms::Stack<>()),
      /*batch_size=*/64);

  // Instantiate an SGD optimization algorithm to update our Net's parameters.
  torch::optim::SGD optimizer(net->parameters(), /*lr=*/0.01);

  for (size_t epoch = 1; epoch <= 10; ++epoch) {
    size_t batch_index = 0;
    // Iterate the data loader to yield batches from the dataset.
    for (auto& batch : *data_loader) {
      // Reset gradients.
      optimizer.zero_grad();
      // Execute the model on the input data.
      torch::Tensor prediction = net->forward(batch.data);
      // Compute a loss value to judge the prediction of our model.
      torch::Tensor loss = torch::nll_loss(prediction, batch.target);
      // Compute gradients of the loss w.r.t. the parameters of our model.
      loss.backward();
      // Update the parameters based on the calculated gradients.
      optimizer.step();
      // Output the loss and checkpoint every 100 batches.
      if (++batch_index % 100 == 0) {
        std::cout << "Epoch: " << epoch << " | Batch: " << batch_index
                  << " | Loss: " << loss.item<float>() << std::endl;
        // Serialize your model periodically as a checkpoint.
        torch::save(net, "net.pt");
      }
    }
  }
}
```

</Details>

# Planning and Progress

- [x] Set up a workspace for wrapping LibTorch with C and Swift.

- <Details><Summary>WIP: Port basic Tensor creation</Summary>

  - [ ] Scalar
  - [ ] Tensor
    - [ ] [Accessor](https://pytorch.org/cppdocs/notes/tensor_basics.html#efficient-access-to-tensor-elements)
    - [ ] [External Data](https://pytorch.org/cppdocs/notes/tensor_basics.html#using-externally-created-data)
  - [ ] TensorOptions
    - [x] dtype
    - [ ] device
  - [ ] [Factory functions](https://pytorch.org/cppdocs/notes/tensor_creation.html#factory-functions)
    - [x] variable size
    - [ ] arange
    - [ ] empty
    - [ ] eye
    - [ ] full
    - [ ] linspace
    - [ ] logspace
    - [ ] ones
    - [ ] rand
    - [ ] randn
    - [ ] randint
    - [ ] randperm
    - [ ] zeros

</Details>

- <Details><Summary>Port basic Tensor manipulation.</Summary>

    - [x] resize
    - [x] subscript

</Details>

- [ ] Build computational graph with AutoGrad module.
- [ ] Wrap NN module.
- [ ] Build Module.

# How to use

#### 1. Build a Docker image for dev.

```
./docker/build.sh
```

This will build two images.

1. An image which only contains LibTorch built from source.
1. Development image with Swift and LibTorch.

#### 2. Start a container

```
./start_container.sh
```

#### 3. Run unit test

```
./run_test.sh
```
