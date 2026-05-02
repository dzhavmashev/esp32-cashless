// Function : FUN_4018514c
// Address  : 0x4018514c
// Size     : 39 bytes


undefined4 FUN_4018514c(int param_1)

{
  if (param_1 == 8) {
    return 3;
  }
  if (param_1 < 9) {
    if (param_1 == 2) {
      return 2;
    }
  }
  else {
    if (param_1 == 0x80) {
      return 1;
    }
    if (param_1 == 0x100) {
      return 5;
    }
  }
  return 0;
}

