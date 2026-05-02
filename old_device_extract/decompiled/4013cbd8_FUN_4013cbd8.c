// Function : FUN_4013cbd8
// Address  : 0x4013cbd8
// Size     : 98 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4013cbd8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 auStack_100 [220];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  FUN_4014098c(auStack_100);
  iVar1 = FUN_40140a08(auStack_100,param_4);
  if ((iVar1 == 0) && (iVar1 = FUN_40140aec(auStack_100,param_1,param_2), iVar1 == 0)) {
    iVar1 = FUN_40140b04(auStack_100,param_3);
  }
  FUN_401409a0(auStack_100);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return iVar1;
}

