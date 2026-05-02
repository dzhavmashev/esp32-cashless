// Function : FUN_400fa208
// Address  : 0x400fa208
// Size     : 146 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_400fa208(int param_1,undefined1 param_2,char param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6)

{
  int iVar1;
  undefined4 uStack_48;
  undefined1 auStack_44 [32];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar1 = 0x1101;
  if ((*(int *)(param_1 + 100) == 1) &&
     ((uStack_48 = 0, param_3 != 'A' ||
      (iVar1 = FUN_400fa0e8(param_1,param_2,param_4,param_5,param_6), iVar1 == 0x1102)))) {
    memw();
    iVar1 = FUN_400f9c84(param_1,param_2,param_3,param_4,&uStack_48,auStack_44,0xff,0xff);
    if (iVar1 == 0) {
      memw();
      iVar1 = FUN_400fb884(uStack_48,param_2,param_3,param_4,param_5,param_6,0xff,0xff);
    }
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return iVar1;
}

