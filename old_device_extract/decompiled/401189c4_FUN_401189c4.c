// Function : FUN_401189c4
// Address  : 0x401189c4
// Size     : 66 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401189c4(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((*param_1 != _DAT_3ffc85f8) || (param_1[1] != _DAT_3ffc85fc)) ||
      (param_1[2] != _DAT_3ffc8600)) ||
     ((param_1[3] != _DAT_3ffc8604 || ((char)param_1[4] != DAT_3ffc8608)))) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

