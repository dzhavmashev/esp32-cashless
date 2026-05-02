// Function : FUN_400eb038
// Address  : 0x400eb038
// Size     : 159 bytes


void FUN_400eb038(int param_1,int param_2)

{
  int iVar1;
  int aiStack_28 [10];
  
  aiStack_28[0] = *(int *)(param_1 + 0x678);
  aiStack_28[1] = 0;
  if (param_2 == 0) {
    while (aiStack_28[0] != 0) {
      iVar1 = FUN_401844a8(aiStack_28[0] + 4);
      if (((iVar1 - 0x50U & 0xef) == 0) ||
         ((iVar1 == 0x30 && (iVar1 = FUN_401844a0(aiStack_28[0] + 4), iVar1 != 0)))) {
        (*(code *)&LAB_40184487_1)(aiStack_28);
      }
      else {
        FUN_400dad2c(param_1 + 0x678,aiStack_28);
      }
    }
  }
  else if (param_2 == 1) {
    while (aiStack_28[0] != 0) {
      iVar1 = FUN_401844a8(aiStack_28[0] + 4);
      if (iVar1 == 0x30) {
        (*(code *)&LAB_40184487_1)(aiStack_28);
      }
      else {
        FUN_400dad2c(param_1 + 0x678,aiStack_28);
      }
    }
  }
  else {
    while (aiStack_28[0] != 0) {
      FUN_400dad2c(param_1 + 0x678,aiStack_28);
    }
  }
  return;
}

