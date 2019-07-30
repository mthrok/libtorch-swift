import LibTorch


class Tensor {
    let _p:OpaquePointer

    init (_ pointer:OpaquePointer) {
        self._p = pointer
    }

    func dim() -> Int64 {
        return LibTorch.tensorDim(self._p)
    }

    func sizes() -> [UInt64] {
        var s =  Array(repeating: UInt64(0), count: Int(LibTorch.tensorDim(self._p)))
        LibTorch.tensorSizes(self._p, &s)
        return s
    }

    func index(_ i:Int64) -> Tensor {
        return Tensor(LibTorch.tensorIndex(self._p, i))
    }

    func item() -> Scalar {
        return Scalar(LibTorch.tensorItem(self._p))
    }

    func slice(_ dim:Int64=0, _ start:Int64=0, _ end:Int64=Int64.max, _ step:Int64=1) -> Tensor {
        return Tensor(LibTorch.tensorSlice(self._p, dim, start, end, step));
    }

    func isSame(_ other: Tensor) -> Bool {
        // Check if underlying object Tensor objects are identical object
        return LibTorch.tensorIsSame(self._p, other._p) == 1
    }

    func isHip() -> Bool { return LibTorch.tensorIsHip(self._p) == 1 }
    func isCuda() -> Bool { return LibTorch.tensorIsCuda(self._p) == 1 }
    func isSparse() -> Bool { return LibTorch.tensorIsSparse(self._p) == 1 }
    func isMkldnn() -> Bool { return LibTorch.tensorIsMkldnn(self._p) == 1 }
    func isQuantized() -> Bool { return LibTorch.tensorIsQuantized(self._p) == 1 }
}

extension Tensor {
    static func == (left: Tensor, right: Tensor) -> Tensor {
        LibTorch.printTensor(LibTorch.tensorEqual(left._p, right._p));
        return Tensor(LibTorch.tensorEqual(left._p, right._p))
    }

    static func + (left: Tensor, right: Tensor) -> Tensor {
        return Tensor(LibTorch.tensorAdd(left._p, right._p))
    }
}

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
