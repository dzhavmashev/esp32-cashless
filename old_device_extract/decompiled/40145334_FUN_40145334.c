// Function : FUN_40145334
// Address  : 0x40145334
// Size     : 59 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40145334(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 != (undefined4 *)0x0) {
    uVar1 = _DAT_3ffbf7c8;
    if (((param_1 == 7) || (uVar1 = _DAT_3ffbf7cc, param_1 == 9)) ||
       (uVar1 = _DAT_3ffbf7c4, param_1 == 4)) {
      *param_2 = uVar1;
      memw();
      return 0;
    }
    *param_2 = 0;
  }
  memw();
  return 0xffffffff;
}

