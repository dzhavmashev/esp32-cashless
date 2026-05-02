// Function : FUN_4015ec38
// Address  : 0x4015ec38
// Size     : 109 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015ec38(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_1 == 7) {
    if (param_2 != 0) {
      return 0xffffffff;
    }
    memw();
    _DAT_3ffbfe8c = param_3;
  }
  else {
    if (param_1 < 8) {
      if (param_1 == 3) {
        if (2 < param_2) {
          return 0xffffffff;
        }
        iVar1 = 0x3ffbfe90;
      }
      else {
        if (param_1 != 4) {
          return 0xffffffff;
        }
        if (0x21 < param_2) {
          return 0xffffffff;
        }
        iVar1 = 0x3ffbfdf8;
      }
    }
    else {
      if (param_1 != 8) {
        if ((param_1 == 0x7f) && (param_2 == 0)) {
          _DAT_3ffbfe88 = param_3;
          memw();
          return 0;
        }
        return 0xffffffff;
      }
      if (1 < param_2) {
        return 0xffffffff;
      }
      iVar1 = 0x3ffbfe80;
    }
    *(undefined4 *)(param_2 * 4 + iVar1) = param_3;
  }
  memw();
  return 0;
}

