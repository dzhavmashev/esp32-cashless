// Function : FUN_40133d88
// Address  : 0x40133d88
// Size     : 30 bytes


void FUN_40133d88(int param_1)

{
  (*(code *)&SUB_4008b530)(param_1,0,0x4c);
  *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1c) = 10000;
  memw();
  return;
}

