// Function : FUN_400e04ac
// Address  : 0x400e04ac
// Size     : 64 bytes


void FUN_400e04ac(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  iVar1 = *param_1;
  do {
    iVar2 = iVar1;
    if (iVar2 == 0) break;
    iVar1 = (*(code *)&LAB_40183a9a_2)(iVar2);
  } while (param_2 != iVar1);
  iVar1 = (*(code *)&LAB_40183a9a_2)(param_2);
  if (iVar2 == 0) {
    *param_1 = iVar1;
  }
  else {
    uVar3 = 0;
    if (iVar1 != 0) {
      uVar3 = (undefined2)(iVar1 - iVar2 >> 4);
    }
    *(undefined2 *)(iVar2 + 10) = uVar3;
  }
  if (iVar1 == 0) {
    param_1[1] = iVar2;
  }
  return;
}

