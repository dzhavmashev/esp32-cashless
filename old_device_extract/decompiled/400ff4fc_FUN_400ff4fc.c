// Function : FUN_400ff4fc
// Address  : 0x400ff4fc
// Size     : 33 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400ff4fc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400fea78(_DAT_3ffc5830);
  uVar2 = (**(code **)(iVar1 + 0x54))(_DAT_3ffc5828,param_2,param_3);
  return uVar2;
}

