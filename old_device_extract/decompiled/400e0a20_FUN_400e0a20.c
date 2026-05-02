// Function : FUN_400e0a20
// Address  : 0x400e0a20
// Size     : 97 bytes


undefined8 FUN_400e0a20(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iStack_28;
  int iStack_24;
  
  iVar2 = 1;
  iStack_28 = *(int *)(param_1 + 8);
  iStack_24 = param_1 + 4;
  while (iStack_28 != 0) {
    iVar2 = FUN_400f1218(param_2,iStack_28 + 0x10);
    iStack_24 = iStack_28;
    if (iVar2 == 0) {
      iStack_28 = *(int *)(iStack_28 + 0xc);
    }
    else {
      iStack_28 = *(int *)(iStack_28 + 8);
    }
  }
  iVar1 = iStack_24;
  if (iVar2 != 0) {
    if (*(int *)(param_1 + 0xc) == iStack_24) goto LAB_400e0a51;
    iVar1 = (*(code *)&LAB_40170483_1)(iStack_24);
  }
  iVar2 = FUN_400f1218(iVar1 + 0x10,param_2);
  if (iVar2 == 0) {
    iStack_24 = 0;
    iStack_28 = iVar1;
  }
  else {
    iStack_28 = 0;
  }
LAB_400e0a51:
  return CONCAT44(iStack_24,iStack_28);
}

