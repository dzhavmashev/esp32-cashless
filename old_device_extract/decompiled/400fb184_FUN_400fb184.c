// Function : FUN_400fb184
// Address  : 0x400fb184
// Size     : 96 bytes


int FUN_400fb184(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = -1;
  if (*(uint *)(param_1 + 0x38) < 0x7e) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x18))
                      (*(int **)(param_1 + 0x50),
                       *(int *)(param_1 + 8) + 0x40 + *(uint *)(param_1 + 0x38) * 0x20,param_2,0x20)
    ;
    if (iVar1 == 0) {
      iVar1 = FUN_40184a44(param_1,*(undefined4 *)(param_1 + 0x38),2);
      if (iVar1 == 0) {
        if (*(int *)(param_1 + 0x3c) == -1) {
          *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x38);
        }
        *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + 1;
        memw();
        *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
        memw();
      }
    }
    else {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
  }
  memw();
  return iVar1;
}

