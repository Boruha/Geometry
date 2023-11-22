from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake
from conan.tools.files import copy
from os import path

class GeometryRecipe(ConanFile):
    name    = "geometry"
    version = "0.1.0"

    # Optional metadata
    license     = "GNU-3.0"
    author      = "Borja Pozo Wals", "borja.pozo@gmail.com"
    url         = "https://github.com/Boruha/Geometry.git"
    description = "Set of functions, structures and types for mathematical operations."
    topics      = "Math", "STL-like"

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options  = {
        "shared"         : [True, False],
        "fPIC"           : [True, False],
        "unit_test"      : [True, False],
        "benchmark_test" : [True, False]
    }
    default_options = {
        "shared"         : False, 
        "fPIC"           : True,
        "unit_test"      : False,
        "benchmark_test" : False
    }
    generators = "CMakeDeps"

    def requirements(self):
        if self.options.get_safe("unit_test"):
            self.requires("gtest/1.14.0")

        if self.options.get_safe("benchmark_test"):
            self.requires("benchmark/1.8.3")

    def config_options(self):
        if self.settings.os == "Windows":
            self.options.rm_safe("fPIC")

    def configure(self):
        if self.options.shared:
            self.options.rm_safe("fPIC")

    def layout(self):
        self.folders.generators = path.join("build", self.settings.get_safe("os"), "generator")
        self.folders.build      = path.join("build", self.settings.get_safe("os"),
                                    self.settings.get_safe("arch"), self.settings.get_safe("build_type"))

    def generate(self):
        tc = CMakeToolchain(self)
        tc.variables["UNIT_TEST"]      = self.options.get_safe("unit_test")
        tc.variables["BENCHMARK_TEST"] = self.options.get_safe("benchmark_test")
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package_info(self):
        self.cpp_info.libs = ["Geometry"]
        self.cpp_info.includedirs = ['include']

        self.cpp_info.set_property("cmake_find_mode", "both")

    def package(self):
        copy(self, "*.hpp", path.join(self.source_folder, "include"), path.join(self.package_folder, "include"))

        copy(self, "conanfile.py", self.source_folder, self.package_folder)
        copy(self, "CMakeLists.txt", self.source_folder, self.package_folder)
        copy(self, "compiler_options.cmake", self.source_folder, self.package_folder)

    
