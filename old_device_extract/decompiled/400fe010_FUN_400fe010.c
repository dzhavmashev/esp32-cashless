// Function : FUN_400fe010
// Address  : 0x400fe010
// Size     : 37 bytes


void FUN_400fe010(int *param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x40) = *(uint *)(*param_1 + 0x40) & 0xfff003ff | (param_2 & 0x3ff) << 10;
  memw();
  return;
}

