// Function : FUN_40155514
// Address  : 0x40155514
// Size     : 37 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40155514(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _DAT_3ffbfd50;
  (*(code *)&SUB_4008b3d0)(_DAT_3ffbfd50 + 0x9c,param_1,6);
  *(undefined1 *)(iVar1 + 0xa2) = 1;
  memw();
  memw();
  return;
}

