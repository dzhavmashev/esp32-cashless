// Function : FUN_4011b338
// Address  : 0x4011b338
// Size     : 25 bytes


undefined1 FUN_4011b338(int param_1)

{
  undefined1 uVar1;
  
  *(undefined2 *)(param_1 + 0xec) = 0x7473;
  memw();
  memw();
  uVar1 = FUN_4011b2d4();
  return uVar1;
}

