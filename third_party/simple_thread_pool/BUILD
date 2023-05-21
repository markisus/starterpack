package(default_visibility = ["//visibility:public"])

COPTS = select({
    "@bazel_tools//src/conditions:windows": ["/std:c++17"],
    "//conditions:default": ["-std=c++17"],})


cc_library(
    name = "thread_pool",
    hdrs = ["thread_pool.h"],
    srcs = ["thread_pool.cpp"],
    copts = COPTS,
    strip_include_prefix = "/third_party/simple_thread_pool",
)

cc_binary(
    name = "thread_pool_example",
    srcs = ["thread_pool_example.cpp"],
    deps = [":thread_pool"],
)

