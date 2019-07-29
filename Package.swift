// swift-tools-version:5.0

import PackageDescription

let package = Package(
    name: "Switch",
    products: [
        .library(
          name: "Switch",
          targets: ["Switch"]),
        .library(
          name: "LibTorch",
          targets: ["LibTorch"]),
    ],
    dependencies: [
        .package(url: "https://github.com/apple/swift-log.git", from: "1.0.0"),
    ],
    targets: [
        .target(
            name: "LibTorch",
            path: "./Sources/LibTorch"
        ),
        .target(
            name: "Switch",
            dependencies: ["LibTorch", "Logging"]
        ),
        .testTarget(
            name: "SwitchTests",
            dependencies: ["Switch"]),
    ]
)
