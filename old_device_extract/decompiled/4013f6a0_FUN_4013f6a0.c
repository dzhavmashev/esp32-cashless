// Function : FUN_4013f6a0
// Address  : 0x4013f6a0
// Size     : 88 bytes


undefined4 FUN_4013f6a0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0x6c) == 0) {
    if ((*(int *)(param_1 + 0x68) == 0) && (iVar1 = FUN_40143650(1), iVar1 != 0)) {
      *(undefined4 *)(param_1 + 0x6c) = 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x6c) = 2;
      iVar1 = 0;
      memw();
    }
  }
  if (*(int *)(param_1 + 0x6c) == 1) {
    memw();
    FUN_401436e4(1,param_2,iVar1);
    if (param_3 != 0) {
      FUN_401436b0(1,param_1 + 8);
    }
  }
  else {
    FUN_4013ee80(param_1,param_2);
  }
  return 0;
}

