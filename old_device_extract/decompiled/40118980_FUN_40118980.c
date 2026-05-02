// Function : FUN_40118980
// Address  : 0x40118980
// Size     : 67 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40118980(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((*param_1 != _DAT_3ffc851c) || (param_1[1] != _DAT_3ffc8520)) ||
      (param_1[2] != _DAT_3ffc8524)) ||
     ((param_1[3] != _DAT_3ffc8528 || ((char)param_1[4] != DAT_3ffc852c)))) {
    uVar1 = 0xff;
  }
  return uVar1;
}

