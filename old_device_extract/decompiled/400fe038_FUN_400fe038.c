// Function : FUN_400fe038
// Address  : 0x400fe038
// Size     : 35 bytes


void FUN_400fe038(int *param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x24) = *(uint *)(*param_1 + 0x24) & 0xffff80ff | (param_2 & 0x7f) << 8;
  memw();
  return;
}

