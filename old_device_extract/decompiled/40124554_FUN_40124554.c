// Function : FUN_40124554
// Address  : 0x40124554
// Size     : 43 bytes


void FUN_40124554(int param_1)

{
  *(byte *)(param_1 + 0x19c) = *(byte *)(param_1 + 0x19c) | 1;
  memw();
  *(undefined4 *)(param_1 + 0x10) = 1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  memw();
  FUN_4015a5bc(param_1 + 8,0xf);
  return;
}

