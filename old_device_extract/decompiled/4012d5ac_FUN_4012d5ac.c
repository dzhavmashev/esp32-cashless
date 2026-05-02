// Function : FUN_4012d5ac
// Address  : 0x4012d5ac
// Size     : 199 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4012d5ac(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 auStack_dc [88];
  undefined1 auStack_84 [96];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  FUN_401416d8(auStack_dc);
  FUN_4013ec3c(auStack_84);
  iVar1 = FUN_401416c8(auStack_dc);
  if ((((iVar1 == 0) &&
       (iVar1 = FUN_401416b4(auStack_dc,*(int *)(param_1 + 0x44) + 0x470,0x40), iVar1 == 0)) &&
      (iVar1 = FUN_401416b4(auStack_dc,param_3,param_4), iVar1 == 0)) &&
     (((iVar1 = FUN_401416a0(auStack_dc,param_2), iVar1 == 0 &&
       (iVar1 = FUN_4013eca8(auStack_84), iVar1 == 0)) &&
      ((iVar1 = FUN_4013ecf4(auStack_84,*(int *)(param_1 + 0x44) + 0x470,0x40), iVar1 == 0 &&
       (iVar1 = FUN_4013ecf4(auStack_84,param_3,param_4), iVar1 == 0)))))) {
    iVar1 = FUN_4013ed0c(auStack_84,param_2 + 0x10);
  }
  FUN_401416e8(auStack_dc);
  FUN_4013ec50(auStack_84);
  if (iVar1 != 0) {
    FUN_4012a73c(param_1,2,0x50);
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return iVar1;
}

