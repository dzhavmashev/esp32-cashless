// Function : FUN_400dad2c
// Address  : 0x400dad2c
// Size     : 85 bytes


void FUN_400dad2c(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_2;
  if (iVar1 != 0) {
    iVar3 = *(int *)(iVar1 + 0x2c);
    iVar2 = param_2[1];
    *param_2 = iVar3;
    param_2[1] = iVar1;
    if (iVar1 == param_1[2]) {
      param_1[2] = iVar3;
    }
    if (iVar1 == param_1[3]) {
      param_1[3] = iVar2;
    }
    if (*param_1 == param_1[1]) {
      param_1[1] = 0;
      *param_1 = 0;
    }
    else if (iVar1 == *param_1) {
      *param_1 = iVar3;
    }
    else if (iVar1 == param_1[1]) {
      param_1[1] = iVar2;
      *(undefined4 *)(iVar2 + 0x2c) = 0;
    }
    else {
      *(int *)(iVar2 + 0x2c) = iVar3;
    }
    FUN_400ebbc0(iVar1 + 4);
    FUN_4016fa48(iVar1);
  }
  return;
}

