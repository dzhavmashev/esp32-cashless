// Function : FUN_40154bf8
// Address  : 0x40154bf8
// Size     : 35 bytes


void FUN_40154bf8(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 1;
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 0x40000;
  memw();
  FUN_4015fb68(0x40151db0,2,0);
  return;
}

