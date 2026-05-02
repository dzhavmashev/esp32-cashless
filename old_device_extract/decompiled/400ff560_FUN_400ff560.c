// Function : FUN_400ff560
// Address  : 0x400ff560
// Size     : 32 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400ff560(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400fea78(_DAT_3ffc5830);
  uVar2 = 0x106;
  if ((iVar1 != 0) && (*(code **)(iVar1 + 0xa0) != (code *)0x0)) {
    uVar2 = (**(code **)(iVar1 + 0xa0))(param_1);
  }
  return uVar2;
}

