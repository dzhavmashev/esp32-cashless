// Function : FUN_400d7038
// Address  : 0x400d7038
// Size     : 87 bytes


void FUN_400d7038(int param_1)

{
  int iVar1;
  
  FUN_400f0780(0x3ffc5490,"g state");
  if (*(int *)(param_1 + 0x50) != 0) {
    memw();
    *(undefined1 *)(param_1 + 0x54) = 0;
    func_0x4009183c(100);
    iVar1 = func_0x400909a4(*(undefined4 *)(param_1 + 0x50));
    if (iVar1 != 4) {
      func_0x40091740(*(undefined4 *)(param_1 + 0x50));
    }
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  if (*(int **)(param_1 + 0x28) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x28) + 4))();
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  FUN_400e7250(*(undefined4 *)(param_1 + 0x24),0);
  FUN_400db4c0(0x3ffc4218);
  return;
}

