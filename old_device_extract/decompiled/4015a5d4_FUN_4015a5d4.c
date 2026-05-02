// Function : FUN_4015a5d4
// Address  : 0x4015a5d4
// Size     : 40 bytes


int FUN_4015a5d4(int param_1)

{
  (*(code *)&SUB_4008b530)(param_1,0,0xa8);
  *(undefined4 *)(param_1 + 8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
  memw();
  return param_1 + 0x10;
}

