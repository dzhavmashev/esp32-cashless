// Function : FUN_400f52e4
// Address  : 0x400f52e4
// Size     : 280 bytes


undefined4 FUN_400f52e4(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 2;
  if (param_1 != 0x10) {
    if (param_1 < 0x11) {
      uVar1 = 0x200000;
      if (param_1 != 7) {
        if (param_1 < 8) {
          uVar1 = 0x800000;
          if (param_1 != 3) {
            if (param_1 < 4) {
              uVar1 = 4;
              if ((param_1 != 1) && (uVar1 = 0x20, param_1 < 2)) {
                uVar1 = 0x800;
              }
            }
            else {
              uVar1 = 0x40000;
              if ((param_1 != 5) && (uVar1 = 0x10, param_1 < 6)) {
                uVar1 = 0x80;
              }
            }
          }
        }
        else {
          uVar1 = 0x100000;
          if (param_1 != 0xb) {
            if (param_1 < 0xc) {
              uVar1 = 0x8000;
              if ((param_1 != 9) && (uVar1 = 0x20000, param_1 < 10)) {
                uVar1 = 0x2000;
              }
            }
            else {
              uVar1 = 0x1000;
              if ((((param_1 != 0xd) && (uVar1 = 0x100, 0xc < param_1)) &&
                  (uVar1 = 0x200, param_1 != 0xe)) && (uVar1 = 0x400, param_1 != 0xf)) {
                uVar1 = 0;
              }
            }
          }
        }
      }
    }
    else {
      uVar1 = 0x8000;
      if (param_1 != 0x18) {
        if (param_1 < 0x19) {
          if (param_1 == 0x14) {
            return 0x2000;
          }
          if (param_1 < 0x15) {
            if (param_1 == 0x12) {
              return 0x10000;
            }
            if (param_1 < 0x13) {
              return 0x40;
            }
            return 0x400000;
          }
          if (param_1 == 0x16) {
            return 0x80000;
          }
          uVar1 = 0x10;
          if (0x16 < param_1) {
            return 0x4000;
          }
        }
        else {
          if (param_1 == 0x1c) {
            return 0x800;
          }
          if (param_1 < 0x1d) {
            if (param_1 == 0x1a) {
              return 0x30800;
            }
            if (param_1 < 0x1b) {
              return 0x406;
            }
            return 0x3c9;
          }
          if (param_1 == 0x1e) {
            return 1;
          }
          if (param_1 < 0x1e) {
            return 0x30000;
          }
          if (param_1 == 0x1f) {
            return 2;
          }
          uVar1 = 0;
          if (param_1 == 0x20) {
            uVar1 = 4;
          }
        }
      }
    }
  }
  return uVar1;
}

