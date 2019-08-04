import LibTorch


func zeros(_ sizes:Int..., dtype:String="float") -> Tensor {
    var sizes64 = sizes;
    let opt:TensorOptions = TensorOptionsFromDtype(dtype);
    return Tensor(LibTorch.zeros(&sizes64, UInt64(sizes.count), opt._p))
}

func ones(_ sizes:Int..., dtype:String="float") -> Tensor {
    var sizes64 = sizes;
    let opt:TensorOptions = TensorOptionsFromDtype(dtype);
    return Tensor(LibTorch.ones(&sizes64, UInt64(sizes.count), opt._p))
}

func randn(_ sizes:Int..., dtype:String="float") -> Tensor {
    var sizes64 = sizes;
    let opt:TensorOptions = TensorOptionsFromDtype(dtype);
    return Tensor(LibTorch.randn(&sizes64, UInt64(sizes.count), opt._p))
}

func randint(_ low:Int, _ high:Int, _ sizes:Int..., dtype:String="float") -> Tensor {
    var sizes64 = sizes;
    let opt:TensorOptions = TensorOptionsFromDtype(dtype);
    return Tensor(LibTorch.randint(Int64(low), Int64(high), &sizes64, UInt64(sizes.count), opt._p))
}
