// Function : FUN_400d813c
// Address  : 0x400d813c
// Size     : 70 bytes


void FUN_400d813c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_400d6e3c(param_1,0x3ffc4010,10000);
  if (iVar1 != 0) {
    FUN_400f0780(0x3ffc5490,"t %d/5\n");
    FUN_400d6e9c(param_1);
  }
  FUN_400e7850(*(undefined4 *)(param_1 + 0x18));
  iVar1 = FUN_400f1a9c();
  if (60000 < (uint)(iVar1 - *(int *)(param_1 + 0x3c))) {
    FUN_400f0780(0x3ffc5490,"ry soon");
    FUN_400d7d34(param_1,1);
  }
  return;
}

