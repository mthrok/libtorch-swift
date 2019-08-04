import LibTorch

/// <#Description#>
/// Dtype class is for read-only purpose.
/// Factory function -> Tensor Object -> Dtype object.
class Dtype {
    var _p: OpaquePointer

    init (_ pointer:OpaquePointer) {
        self._p = pointer
    }

    deinit {
        LibTorch.deleteDtype(self._p)
    }

    func name() -> String {
        return String(cString: LibTorch.dtypeName(self._p))
    }
}

extension Dtype: Equatable {
    static func == (left: Dtype, right: Dtype) -> Bool {
        return LibTorch.dtypeEqual(left._p, right._p) == 1
    }
}
