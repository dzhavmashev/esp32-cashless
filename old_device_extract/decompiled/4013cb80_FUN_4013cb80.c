// Function : FUN_4013cb80
// Address  : 0x4013cb80
// Size     : 87 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4013cb80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 auStack_94 [112];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  FUN_4013f784(auStack_94);
  iVar1 = FUN_4013f7ec(auStack_94,param_4);
  if ((iVar1 == 0) && (iVar1 = FUN_4013f87c(auStack_94,param_1,param_2), iVar1 == 0)) {
    iVar1 = FUN_4013f8a4(auStack_94,param_3);
  }
  FUN_4013f798(auStack_94);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return iVar1;
}

