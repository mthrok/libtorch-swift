import XCTest

#if !canImport(ObjectiveC)
public func allTests() -> [XCTestCaseEntry] {
    return [
      testCase(TensorOptionsTests.allTests),
      testCase(TensorClassTests.allTests),
      testCase(TensorFactoryTests.allTests),
      testCase(DtypeTests.allTests),
    ]
}
#endif
