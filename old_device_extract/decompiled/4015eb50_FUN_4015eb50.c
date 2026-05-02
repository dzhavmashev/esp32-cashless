// Function : FUN_4015eb50
// Address  : 0x4015eb50
// Size     : 93 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015eb50(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_1 == 7) {
    if (param_2 != 0) {
      return 0xffffffff;
    }
    memw();
    _DAT_3ffbfea8 = param_3;
  }
  else {
    if (param_1 < 8) {
      if (param_1 != 3) {
        return 0xffffffff;
      }
      if (2 < param_2) {
        return 0xffffffff;
      }
      iVar1 = 0x3ffbfeac;
    }
    else {
      if (param_1 != 8) {
        if ((param_1 == 0x7f) && (param_2 == 0)) {
          _DAT_3ffbfea4 = param_3;
          memw();
          return 0;
        }
        return 0xffffffff;
      }
      if (1 < param_2) {
        return 0xffffffff;
      }
      iVar1 = 0x3ffbfe9c;
    }
    *(undefined4 *)(param_2 * 4 + iVar1) = param_3;
  }
  memw();
  return 0;
}

