// Function : FUN_400dda20
// Address  : 0x400dda20
// Size     : 80 bytes


void FUN_400dda20(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x38) != 0) {
    memw();
    *(undefined1 *)(param_1 + 0x3c) = 0;
    func_0x4009183c(200);
    iVar1 = func_0x400909a4(*(undefined4 *)(param_1 + 0x38));
    if (iVar1 != 4) {
      func_0x40091740(*(undefined4 *)(param_1 + 0x38));
    }
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  if (*(int *)(param_1 + 0x34) != 0) {
    func_0x400902dc();
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  if (*(char *)(param_1 + 0x29) != '\0') {
    FUN_400dd968(param_1);
    *(undefined1 *)(param_1 + 0x29) = 0;
    FUN_400f0780(0x3ffc5490,"Exiting");
  }
  return;
}

