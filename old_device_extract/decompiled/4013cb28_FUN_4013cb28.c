// Function : FUN_4013cb28
// Address  : 0x4013cb28
// Size     : 88 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4013cb28(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 auStack_84 [96];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  FUN_4013ec3c(auStack_84);
  iVar1 = FUN_4013eca8(auStack_84);
  if ((iVar1 == 0) && (iVar1 = FUN_4013ecf4(auStack_84,param_1,param_2), iVar1 == 0)) {
    iVar1 = FUN_4013ed0c(auStack_84,param_3);
  }
  FUN_4013ec50(auStack_84);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return iVar1;
}

