// Function : FUN_400da35c
// Address  : 0x400da35c
// Size     : 35 bytes


void FUN_400da35c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_400f1a9c();
  FUN_400da310(param_1);
  if (*(uint *)(param_1 + 0x40) <= (uint)(iVar1 - *(int *)(param_1 + 0x34))) {
    *(int *)(param_1 + 0x34) = iVar1;
    FUN_400da2c8(param_1);
  }
  return;
}

