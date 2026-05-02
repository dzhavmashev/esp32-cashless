// Function : FUN_400eadcc
// Address  : 0x400eadcc
// Size     : 77 bytes


void FUN_400eadcc(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == 0) {
    return;
  }
  if (param_1[2] == param_3) {
    param_1[2] = *(int *)(param_3 + 0x2c);
  }
  if (param_1[3] == param_3) {
    param_1[3] = param_2;
  }
  if (*param_1 == param_1[1]) {
    iVar2 = 0;
    param_1[1] = 0;
  }
  else {
    if (*param_1 != param_3) {
      if (param_1[1] == param_3) {
        param_1[1] = param_2;
        uVar1 = 0;
      }
      else {
        uVar1 = *(undefined4 *)(param_3 + 0x2c);
      }
      *(undefined4 *)(param_2 + 0x2c) = uVar1;
      goto LAB_400eadf1;
    }
    iVar2 = *(int *)(param_3 + 0x2c);
  }
  *param_1 = iVar2;
LAB_400eadf1:
  FUN_400ebbc0(param_3 + 4);
  FUN_4016fa48(param_3);
  return;
}

