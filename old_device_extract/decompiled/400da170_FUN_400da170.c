// Function : FUN_400da170
// Address  : 0x400da170
// Size     : 131 bytes


int FUN_400da170(int param_1)

{
  int iVar1;
  
  FUN_400f0780(0x3ffc5490," failed");
  if (*(int *)(param_1 + 0x10) == 0) {
    FUN_400f0780(0x3ffc5490,"process");
    FUN_400d9fe0(param_1,3);
    FUN_400f0d70(param_1 + 0x20,"anager: No connection mode configured");
    iVar1 = 0;
  }
  else {
    FUN_400d9fe0(param_1,1);
    if (*(int *)(param_1 + 0x10) == 1) {
      iVar1 = FUN_400da014(param_1);
    }
    else {
      if (*(int *)(param_1 + 0x10) != 2) {
        FUN_400d9fe0(param_1,3);
        FUN_400f0d70(param_1 + 0x20,"figured");
        return 0;
      }
      iVar1 = FUN_400da0d0(param_1);
    }
    if (iVar1 == 0) {
      FUN_400d9fe0(param_1,0);
    }
    else {
      FUN_400d9fe0(param_1,2);
      *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x44);
    }
  }
  return iVar1;
}

