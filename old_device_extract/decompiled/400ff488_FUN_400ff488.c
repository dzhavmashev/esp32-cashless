// Function : FUN_400ff488
// Address  : 0x400ff488
// Size     : 32 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400ff488(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_400fea78(_DAT_3ffc5830);
  (**(code **)(iVar1 + 4))(_DAT_3ffc5828,param_2,param_3);
  return param_3;
}

