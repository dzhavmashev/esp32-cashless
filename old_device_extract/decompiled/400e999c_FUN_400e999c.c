// Function : FUN_400e999c
// Address  : 0x400e999c
// Size     : 74 bytes


undefined4 FUN_400e999c(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int aiStack_28 [10];
  
  *(int *)(param_1 + 0x38) = param_2 * 1000;
  uVar2 = 0;
  if (-1 < **(int **)(param_1 + 0x2c)) {
    aiStack_28[1] = 0;
    aiStack_28[0] = param_2;
    iVar1 = (*(code *)&LAB_401724e2_2)(param_1,0x1006,aiStack_28);
    uVar2 = 0xffffffff;
    if (-1 < iVar1) {
      uVar2 = (*(code *)&LAB_401724e2_2)(param_1,0x1005,aiStack_28);
    }
  }
  return uVar2;
}

