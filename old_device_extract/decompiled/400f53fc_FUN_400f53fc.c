// Function : FUN_400f53fc
// Address  : 0x400f53fc
// Size     : 254 bytes


undefined4 FUN_400f53fc(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 == 0xd) {
    return 0x1000;
  }
  if (param_1 < 0xe) {
    if (param_1 == 6) {
      return 0x10;
    }
    if (6 < param_1) {
      if (param_1 == 9) {
        return 0x8000;
      }
      if (9 < param_1) {
        if (param_1 == 0xb) {
          return 0x100000;
        }
        if (0xb < param_1) {
          return 0x100;
        }
        return 0x20000;
      }
      if (param_1 == 7) {
        return 0x200000;
      }
      if (param_1 == 8) {
        return 0x2000;
      }
      return 0;
    }
    if (param_1 == 2) {
      return 0x20;
    }
    if (2 < param_1) {
      if (param_1 == 4) {
        return 0x80;
      }
      if (4 < param_1) {
        return 0x40000;
      }
      return 0x800000;
    }
    if (param_1 == 0) {
      return 0x800;
    }
    iVar1 = param_1 - 1;
    uVar3 = 4;
  }
  else {
    if (param_1 == 0x14) {
      return 0x40;
    }
    if (param_1 < 0x15) {
      if (param_1 == 0x10) {
        return 2;
      }
      if (0x10 < param_1) {
        if (param_1 == 0x12) {
          return 0x10000;
        }
        if (0x12 < param_1) {
          return 0x400000;
        }
        return 0x40;
      }
      if (param_1 == 0xe) {
        return 0x200;
      }
      iVar1 = param_1 - 0xf;
      uVar3 = 0x400;
    }
    else {
      if (param_1 == 0x19) {
        return 4;
      }
      if (0x19 < param_1) {
        if (param_1 == 0x1f) {
          if (param_2 != 0) {
            return 10;
          }
          return 2;
        }
        if (param_1 == 0x20) {
          if (param_2 == 0) {
            return 4;
          }
          return 0x14;
        }
        if (param_1 != 0x1e) {
          return 0;
        }
        if (param_2 == 0) {
          return 1;
        }
        return 0x19;
      }
      if (param_1 == 0x16) {
        return 0x80000;
      }
      if (param_1 < 0x16) {
        return 0x20;
      }
      iVar1 = param_1 - 0x17;
      uVar3 = 0x80;
    }
  }
  uVar2 = 0;
  if (iVar1 == 0) {
    uVar2 = uVar3;
  }
  return uVar2;
}

