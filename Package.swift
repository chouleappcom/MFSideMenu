// swift-tools-version:5.1
import PackageDescription

let package = Package(
    name: "MFSideMenu",
    platforms: [
        .iOS(.v11)
    ],
    products: [
        .library(name: "MFSideMenu", targets: ["MFSideMenu"])
    ],
    dependencies: [
    ],
    targets: [
        .target(
            name: "MFSideMenu",
            dependencies: [],
            path: ".",
            sources: [
                "MFSideMenu"
            ],
            publicHeadersPath: "MFSideMenu",
            linkerSettings: [
                .linkedFramework("UIKit")
            ]
        )
    ],
    swiftLanguageVersions: [.v5]
)
