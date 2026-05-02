// Function : FUN_4017138c
// Address  : 0x4017138c
// Size     : 54 bytes


undefined4 FUN_4017138c(uint param_1)

{
  if (param_1 != 0xff) {
    param_1 = param_1 & 7;
    if (param_1 == 2) {
      return 2;
    }
    if (param_1 < 3) {
      if (param_1 == 0) {
        return 4;
      }
    }
    else {
      if (param_1 == 3) {
        return 4;
      }
      if (param_1 == 4) {
        return 8;
      }
    }
    (*(code *)&SUB_40094bc8)();
  }
  return 0;
}

