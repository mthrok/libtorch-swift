import XCTest

#if !canImport(ObjectiveC)
public func allTests() -> [XCTestCaseEntry] {
    return [
      testCase(TensorOptionsTests.allTests),
      testCase(TensorClassTests.allTests),
      testCase(TensorClassSliceTests.allTests),
      testCase(TensorResizeTests.allTests),
      testCase(TensorFactoryTests.allTests),
      testCase(DtypeTests.allTests),
    ]
}
#endif
