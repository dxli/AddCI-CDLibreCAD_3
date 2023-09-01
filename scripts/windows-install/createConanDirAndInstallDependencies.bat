echo "conan"
pwd
mkdir conan
pushd conan
conan profile detect --force
conan install .. -s build_type=Release --build missing
conan profile update settings.compiler.version=17  default
conan profile update settings.compiler.cppstd=17  default
conan install .. -s build_type=Release --build missing
popd
