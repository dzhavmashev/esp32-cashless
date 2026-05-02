// Function : FUN_40133d68
// Address  : 0x40133d68
// Size     : 30 bytes


void FUN_40133d68(int param_1)

{
  FUN_4013ce8c(param_1 + 0x20);
  FUN_4013ae54(param_1,0x4c);
  *(undefined4 *)(param_1 + 0x1c) = 10000;
  *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
  memw();
  return;
}

