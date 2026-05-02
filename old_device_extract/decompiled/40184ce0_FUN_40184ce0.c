// Function : FUN_40184ce0
// Address  : 0x40184ce0
// Size     : 34 bytes


void FUN_40184ce0(int *param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x20) = *(uint *)(*param_1 + 0x20) & 0xfffffff3 | (param_2 & 3) << 2;
  memw();
  return;
}

