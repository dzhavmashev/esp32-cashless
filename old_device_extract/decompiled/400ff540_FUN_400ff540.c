// Function : FUN_400ff540
// Address  : 0x400ff540
// Size     : 29 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400ff540(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400fea78(_DAT_3ffc5830);
  uVar2 = (**(code **)(iVar1 + 0x60))("ev/uart",param_2);
  return uVar2;
}

