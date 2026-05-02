// Function : FUN_4011c600
// Address  : 0x4011c600
// Size     : 60 bytes


void FUN_4011c600(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(byte *)(param_1 + 0x34) = *(byte *)(param_1 + 0x34) | 8;
  memw();
  memw();
  FUN_4011b020();
  iVar2 = *(int *)(param_1 + 0x1c);
  FUN_4011b040();
  for (iVar1 = 0; iVar1 < iVar2; iVar1 = iVar1 + 1) {
    iVar3 = param_1 + 0x10;
    if (*(int *)(param_1 + 0x10) == 0) {
      iVar3 = param_1 + 0x14;
    }
    FUN_4011aeb0(iVar3,"_msg");
  }
  return;
}

