// Function : FUN_400da4f0
// Address  : 0x400da4f0
// Size     : 32 bytes


bool FUN_400da4f0(int param_1)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_400ead1c(param_1);
  bVar2 = false;
  if (iVar1 != 0) {
    bVar2 = *(int *)(param_1 + 0x800) == 2;
  }
  return bVar2;
}

