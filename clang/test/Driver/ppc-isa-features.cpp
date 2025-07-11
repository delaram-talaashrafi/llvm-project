// RUN: %clang -target powerpc64-unknown-unknown -mcpu=pwr6 -S -emit-llvm %s -o - | FileCheck %s -check-prefix=CHECK-PWR6
// RUN: %clang -target powerpc64-unknown-unknown -mcpu=a2 -S -emit-llvm %s -o - | FileCheck %s -check-prefix=CHECK-A2
// RUN: %clang -target powerpc64-unknown-unknown -mcpu=pwr7 -S -emit-llvm %s -o - | FileCheck %s -check-prefix=CHECK-PWR7
// RUN: %clang -target powerpc64le-unknown-unknown -mcpu=pwr8 -S -emit-llvm %s -o - | FileCheck %s -check-prefix=CHECK-PWR8
// RUN: %clang -target powerpc64-unknown-aix -mcpu=pwr9 -S -emit-llvm %s -o - | FileCheck %s -check-prefix=CHECK-PWR9
// RUN: %clang -target powerpc-unknown-aix -mcpu=pwr10 -S -emit-llvm %s -o - | FileCheck %s -check-prefix=CHECK-PWR10

// CHECK-PWR6-NOT: isa-v206-instructions
// CHECK-PWR6-NOT: isa-v207-instructions
// CHECK-PWR6-NOT: isa-v30-instructions

// CHECK-A2:     +isa-v206-instructions
// CHECK-A2-NOT: isa-v207-instructions
// CHECK-A2-NOT: isa-v30-instructions

// CHECK-PWR7:     +isa-v206-instructions
// CHECK-PWR7-NOT: isa-v207-instructions
// CHECK-PWR7-NOT: isa-v30-instructions

// CHECK-PWR8:     +isa-v207-instructions
// CHECK-PWR8-NOT: isa-v30-instructions

// CHECK-PWR9: +isa-v207-instructions
// CHECK-PWR9: +isa-v30-instructions

// CHECK-PWR10: +isa-v207-instructions
// CHECK-PWR10: +isa-v30-instructions
// CHECK-PWR10: +isa-v31-instructions

int main(int argc, char *argv[]) {
  return 0;
}
