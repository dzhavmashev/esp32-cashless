// Function : FUN_401640dc
// Address  : 0x401640dc
// Size     : 90 bytes


undefined4 FUN_401640dc(byte param_1)

{
  undefined4 uVar1;
  byte bVar2;
  
  if (param_1 == 0x24) {
    return 4;
  }
  if (param_1 < 0x25) {
    if (param_1 == 0x12) {
      return 6;
    }
    if (param_1 == 0x18) {
      return 5;
    }
    if (param_1 == 0xc) {
      return 7;
    }
  }
  else {
    if (param_1 == 0x48) {
      return 2;
    }
    if (param_1 < 0x49) {
      uVar1 = 3;
      bVar2 = 0x30;
    }
    else {
      if (param_1 == 0x60) {
        return 1;
      }
      uVar1 = 0;
      bVar2 = 0x6c;
    }
    if (param_1 == bVar2) {
      return uVar1;
    }
  }
  FUN_40147fe4(6,0x200,1,"rate=%d");
  return 0;
}

