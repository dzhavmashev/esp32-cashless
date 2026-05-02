// Function : FUN_4013941c
// Address  : 0x4013941c
// Size     : 88 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4013941c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 auStack_7c [88];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  FUN_401416d8(auStack_7c);
  iVar1 = FUN_401416c8(auStack_7c);
  if ((iVar1 == 0) && (iVar1 = FUN_401416b4(auStack_7c,param_1,param_2), iVar1 == 0)) {
    iVar1 = FUN_401416a0(auStack_7c,param_3);
  }
  FUN_401416e8(auStack_7c);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return iVar1;
}

