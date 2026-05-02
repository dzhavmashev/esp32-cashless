// Function : FUN_40155568
// Address  : 0x40155568
// Size     : 17 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40155568(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _DAT_3ffbfd50;
  *(undefined4 *)(_DAT_3ffbfd50 + 0x34) = param_1;
  *(undefined4 *)(iVar1 + 0x30) = param_2;
  memw();
  return;
}

