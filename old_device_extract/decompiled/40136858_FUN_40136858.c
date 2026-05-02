// Function : FUN_40136858
// Address  : 0x40136858
// Size     : 100 bytes


int FUN_40136858(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_44 [68];
  
  iVar1 = FUN_401863d8(param_1);
  iVar2 = -0x4e80;
  if (iVar1 == 1) {
    FUN_4013562c(auStack_44);
    iVar2 = FUN_401367c4(param_1,auStack_44,param_3,param_4,param_7);
    if (((iVar2 == 0) && (iVar2 = FUN_401367c4(param_1,param_2,param_5,param_6,param_7), iVar2 == 0)
        ) && (iVar2 = FUN_40135788(param_1,param_2,auStack_44,param_2), iVar2 == 0)) {
      iVar2 = FUN_401350bc(param_1,param_2);
    }
    memw();
    FUN_40135340(auStack_44);
  }
  return iVar2;
}

