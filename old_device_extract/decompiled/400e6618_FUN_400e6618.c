// Function : FUN_400e6618
// Address  : 0x400e6618
// Size     : 63 bytes


void FUN_400e6618(undefined1 *param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = FUN_400f1a9c();
    if (*(int *)(param_1 + 4) == 1) {
      if ((uint)(iVar1 - *(int *)(param_1 + 8)) < *(uint *)(param_1 + 0xc)) {
        return;
      }
      FUN_400f1a40(*param_1,0);
      *(undefined4 *)(param_1 + 4) = 2;
      FUN_400f0780(0x3ffc5490,"O HIGH)");
    }
    else if (*(int *)(param_1 + 4) != 2) {
      return;
    }
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}

