// Function : FUN_40103150
// Address  : 0x40103150
// Size     : 87 bytes


undefined4 FUN_40103150(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 6;
  if (param_1 != 0x20) {
    if (param_1 < 0x21) {
      if (param_1 == 2) {
        return 3;
      }
      if (param_1 < 3) {
        iVar1 = param_1 - 1;
        uVar2 = 0;
      }
      else {
        if (param_1 == 8) {
          return 4;
        }
        iVar1 = param_1 - 10;
        uVar2 = 5;
      }
    }
    else {
      if (param_1 == 0x400) {
        return 7;
      }
      if (param_1 < 0x401) {
        if (param_1 == 0x80) {
          return 1;
        }
        iVar1 = param_1 - 0x100;
        uVar2 = 2;
      }
      else {
        if (param_1 == 0x800) {
          return 8;
        }
        iVar1 = param_1 - 0x1000;
        uVar2 = 9;
      }
    }
    if (iVar1 != 0) {
      uVar2 = 0xc;
    }
  }
  return uVar2;
}

