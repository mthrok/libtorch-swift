import XCTest
@testable import Switch


final class TensorOptionsTests: XCTestCase {
    static let patterns = [
      ("int", "int"),
      ("long", "long"),
      ("int32", "int"),
      ("int64", "long"),
      ("float", "float"),
      ("double", "double"),
    ]

    func testDtype() {
        for (input_dtype, expected) in TensorOptionsTests.patterns {
            let name = TensorOptionsFromDtype(input_dtype).dtype().name()
            XCTAssertEqual(name, expected)
        }
    }

    static var allTests = [
      ("testDtype", testDtype),
    ]
}
