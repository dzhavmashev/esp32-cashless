// Function : FUN_40188470
// Address  : 0x40188470
// Size     : 35 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40188470(uint param_1)

{
  int iVar1;
  
  iVar1 = _DAT_3ffc0034 + (param_1 & 0xff) * 0x30;
  *(undefined1 *)(iVar1 + 0x28) = 0;
  *(undefined1 *)(iVar1 + 0x29) = 0;
  memw();
  memw();
  return;
}

