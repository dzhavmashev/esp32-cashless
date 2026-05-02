// Function : FUN_400fdee4
// Address  : 0x400fdee4
// Size     : 41 bytes


void FUN_400fdee4(int *param_1,int param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x20) =
       *(uint *)(*param_1 + 0x20) & 0xf7ffffff | (uint)(param_2 == 0) << 0x1b;
  memw();
  return;
}

