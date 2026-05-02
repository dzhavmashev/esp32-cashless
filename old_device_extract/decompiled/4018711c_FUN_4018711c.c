// Function : FUN_4018711c
// Address  : 0x4018711c
// Size     : 74 bytes


void FUN_4018711c(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_SCOMPARE1;
  
  memw();
  iVar1 = param_1[1];
  do {
    iVar2 = iVar1;
    wsr((char)in_SCOMPARE1,iVar2);
    iVar1 = param_1[1];
    if (iVar1 == in_SCOMPARE1) {
      param_1[1] = iVar2 + -1;
    }
  } while (iVar1 != iVar2);
  if (iVar2 == 1) {
    (**(code **)(*param_1 + 8))(param_1);
    memw();
    iVar1 = param_1[2];
    do {
      iVar2 = iVar1;
      wsr((char)in_SCOMPARE1,iVar2);
      iVar1 = param_1[2];
      if (iVar1 == in_SCOMPARE1) {
        param_1[2] = iVar2 + -1;
      }
    } while (iVar1 != iVar2);
    if (iVar2 == 1) {
      (**(code **)(*param_1 + 0xc))(param_1);
    }
  }
  return;
}

