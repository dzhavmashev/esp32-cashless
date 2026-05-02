// Function : FUN_400ff5fc
// Address  : 0x400ff5fc
// Size     : 60 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_400ff5fc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  memw();
  iVar1 = FUN_400fea78(_DAT_3ffc5830);
  uVar2 = 0x106;
  if ((iVar1 != 0) && (*(code **)(iVar1 + 0x8c) != (code *)0x0)) {
    memw();
    uVar2 = (**(code **)(iVar1 + 0x8c))(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar2;
}

