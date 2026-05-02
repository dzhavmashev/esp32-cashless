// Function : FUN_4018442c
// Address  : 0x4018442c
// Size     : 25 bytes


undefined2 FUN_4018442c(int param_1)

{
  short sVar1;
  
  sVar1 = *(short *)(param_1 + 0xcc) + 1;
  if (sVar1 == 0) {
    sVar1 = 1;
  }
  *(short *)(param_1 + 0xcc) = sVar1;
  return *(undefined2 *)(param_1 + 0xcc);
}

