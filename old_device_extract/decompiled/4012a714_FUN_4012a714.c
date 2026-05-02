// Function : FUN_4012a714
// Address  : 0x4012a714
// Size     : 40 bytes


undefined4 FUN_4012a714(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0xd0) = 0x14;
  *(undefined4 *)(param_1 + 0xd4) = 1;
  **(undefined1 **)(param_1 + 0xcc) = 1;
  memw();
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  memw();
  uVar1 = FUN_4012a534(param_1);
  return uVar1;
}

