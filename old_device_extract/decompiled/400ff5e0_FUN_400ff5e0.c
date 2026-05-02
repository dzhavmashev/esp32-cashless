// Function : FUN_400ff5e0
// Address  : 0x400ff5e0
// Size     : 28 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400ff5e0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400fea78(_DAT_3ffc5830);
  uVar2 = (**(code **)(iVar1 + 0x7c))(_DAT_3ffc5828,param_2);
  return uVar2;
}

