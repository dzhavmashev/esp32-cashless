// Function : FUN_400e0a84
// Address  : 0x400e0a84
// Size     : 184 bytes


undefined8 FUN_400e0a84(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  int iStack_28;
  int iStack_24;
  
  if (param_2 == param_1 + 4) {
    if ((*(int *)(param_1 + 0x14) != 0) &&
       (iVar1 = FUN_400f1218(*(int *)(param_1 + 0x10) + 0x10,param_3), iVar1 != 0)) {
      iStack_28 = 0;
      iStack_24 = *(int *)(param_1 + 0x10);
      goto LAB_400e0aa7;
    }
  }
  else {
    iVar1 = FUN_400f1218(param_3,param_2 + 0x10);
    if (iVar1 == 0) {
      iVar1 = FUN_400f1218(param_2 + 0x10,param_3);
      if (iVar1 == 0) {
        iStack_28 = param_2;
        iStack_24 = 0;
        goto LAB_400e0aa7;
      }
      iStack_24 = *(int *)(param_1 + 0x10);
      if (iStack_24 == param_2) {
        iStack_28 = 0;
        goto LAB_400e0aa7;
      }
      iStack_28 = FUN_40186fe4(param_2);
      iVar1 = FUN_400f1218(param_3,iStack_28 + 0x10);
      if (iVar1 != 0) {
        iStack_24 = iStack_28;
        if (*(int *)(param_2 + 0xc) == 0) {
          iStack_28 = 0;
          iStack_24 = param_2;
        }
        goto LAB_400e0aa7;
      }
    }
    else {
      iStack_28 = *(int *)(param_1 + 0xc);
      iStack_24 = iStack_28;
      if (iStack_28 == param_2) goto LAB_400e0aa7;
      iVar1 = (*(code *)&LAB_40170483_1)(param_2);
      iVar2 = FUN_400f1218(iVar1 + 0x10,param_3);
      if (iVar2 != 0) {
        iStack_28 = param_2;
        iStack_24 = param_2;
        if (*(int *)(iVar1 + 0xc) == 0) {
          iStack_28 = 0;
          iStack_24 = iVar1;
        }
        goto LAB_400e0aa7;
      }
    }
  }
  uVar3 = FUN_400e0a20(param_1,param_3);
  iStack_28 = (int)uVar3;
  iStack_24 = (int)((ulonglong)uVar3 >> 0x20);
LAB_400e0aa7:
  return CONCAT44(iStack_24,iStack_28);
}

