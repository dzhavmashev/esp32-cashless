// Function : FUN_40184d04
// Address  : 0x40184d04
// Size     : 19 bytes


void FUN_40184d04(int *param_1,uint *param_2)

{
  memw();
  *param_2 = *(uint *)(*param_1 + 0x20) >> 2 & 3;
  memw();
  return;
}

