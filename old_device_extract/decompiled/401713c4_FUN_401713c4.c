// Function : FUN_401713c4
// Address  : 0x401713c4
// Size     : 73 bytes


undefined4 FUN_401713c4(uint param_1,int param_2)

{
  if (param_1 != 0xff) {
    param_1 = param_1 & 0x70;
    if (param_1 == 0x20) {
      return *(undefined4 *)(param_2 + 4);
    }
    if (param_1 < 0x21) {
      if (param_1 == 0) {
        return 0;
      }
      if (param_1 == 0x10) {
        return 0;
      }
    }
    else {
      if (param_1 == 0x30) {
        return *(undefined4 *)(param_2 + 8);
      }
      if (param_1 == 0x50) {
        return 0;
      }
    }
    (*(code *)&SUB_40094bc8)();
  }
  return 0;
}

