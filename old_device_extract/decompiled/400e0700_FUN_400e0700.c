// Function : FUN_400e0700
// Address  : 0x400e0700
// Size     : 27 bytes


void FUN_400e0700(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x14);
  if (iVar1 != 0) {
    FUN_400d73a8(iVar1);
    FUN_4016fa48(iVar1);
  }
  FUN_400f0a50(param_1 + 4);
  return;
}

