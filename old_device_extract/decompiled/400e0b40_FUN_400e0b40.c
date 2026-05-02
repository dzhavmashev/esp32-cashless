// Function : FUN_400e0b40
// Address  : 0x400e0b40
// Size     : 109 bytes


int FUN_400e0b40(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  
  iVar1 = (*(code *)&LAB_40170217_1)(0x30);
  iVar3 = iVar1 + 0x10;
  FUN_400f0d4c(iVar3,*param_4);
  *(undefined4 *)(iVar1 + 0x28) = 0;
  uVar5 = FUN_400e0a84(param_1,param_2,iVar3);
  iVar2 = (int)((ulonglong)uVar5 >> 0x20);
  if (iVar2 == 0) {
    FUN_400e0490(iVar1);
    iVar1 = (int)uVar5;
  }
  else {
    uVar4 = 1;
    if (((int)uVar5 == 0) && (iVar2 != param_1 + 4)) {
      uVar4 = FUN_400f1218(iVar3,iVar2 + 0x10);
    }
    (*(code *)&LAB_4017048f_1)(uVar4,iVar1,iVar2,param_1 + 4);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  return iVar1;
}

