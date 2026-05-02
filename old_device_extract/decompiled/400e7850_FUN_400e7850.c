// Function : FUN_400e7850
// Address  : 0x400e7850
// Size     : 30 bytes


void FUN_400e7850(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (1 < iVar1) {
    if (iVar1 < 5) {
      FUN_400e7794(param_1);
    }
    else if (iVar1 == 5) {
      FUN_400e7808();
    }
  }
  return;
}

