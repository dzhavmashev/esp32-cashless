// Function : FUN_400ff4dc
// Address  : 0x400ff4dc
// Size     : 32 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400ff4dc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400fea78(_DAT_3ffc5830);
  uVar2 = (**(code **)(iVar1 + 0xc))(_DAT_3ffc5828,param_2,param_3);
  return uVar2;
}

