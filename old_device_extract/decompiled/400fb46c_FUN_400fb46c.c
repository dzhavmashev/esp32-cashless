// Function : FUN_400fb46c
// Address  : 0x400fb46c
// Size     : 59 bytes


int FUN_400fb46c(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x1c))
                    (*(int **)(param_1 + 0x50),*(undefined4 *)(param_1 + 8),0x1000);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x38) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
    memw();
    FUN_400fafc8(param_1 + 0x44);
  }
  else {
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  memw();
  return iVar1;
}

