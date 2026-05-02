// Function : FUN_400fbaa4
// Address  : 0x400fbaa4
// Size     : 87 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_400fbaa4(undefined4 param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6)

{
  int iVar1;
  undefined4 uStack_48;
  undefined1 auStack_44 [32];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  uStack_48 = 0;
  memw();
  iVar1 = FUN_400fb6ac(param_1,param_2,param_3,param_4,&uStack_48,auStack_44,param_5,param_6);
  if (iVar1 == 0) {
    iVar1 = FUN_400fb554(param_1,uStack_48);
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return iVar1;
}

