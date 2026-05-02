// Function : FUN_4011b354
// Address  : 0x4011b354
// Size     : 25 bytes


undefined1 FUN_4011b354(int param_1)

{
  undefined1 uVar1;
  
  *(undefined2 *)(param_1 + 0xec) = 0x7061;
  memw();
  memw();
  uVar1 = FUN_4011b2d4();
  return uVar1;
}

