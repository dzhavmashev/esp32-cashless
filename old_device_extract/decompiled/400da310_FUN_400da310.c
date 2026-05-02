// Function : FUN_400da310
// Address  : 0x400da310
// Size     : 72 bytes


void FUN_400da310(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    if ((*(int *)(param_1 + 0x10) != 0) &&
       (iVar1 = FUN_400f1a9c(),
       *(uint *)(param_1 + 0x3c) <= (uint)(iVar1 - *(int *)(param_1 + 0x38)))) {
      *(int *)(param_1 + 0x38) = iVar1;
      FUN_400f0780(0x3ffc5490,"%lu ms\n");
      FUN_400da170(param_1);
      FUN_400da2f0(param_1);
    }
  }
  else if ((*(int *)(param_1 + 0xc) == 2) && (iVar1 = FUN_400da298(param_1), iVar1 == 0)) {
    FUN_400da1f8(param_1);
  }
  return;
}

