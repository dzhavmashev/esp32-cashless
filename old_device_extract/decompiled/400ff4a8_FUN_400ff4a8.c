// Function : FUN_400ff4a8
// Address  : 0x400ff4a8
// Size     : 24 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400ff4a8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400fea78(_DAT_3ffc5830);
  uVar2 = (**(code **)(iVar1 + 0x20))(param_1,param_2);
  return uVar2;
}

