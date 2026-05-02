// Function : FUN_4014eb80
// Address  : 0x4014eb80
// Size     : 80 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4014eb80(void)

{
  (**(code **)(_DAT_3ffc1a34 + 0x19c))(0x24,0,1000000);
  (**(code **)(_DAT_3ffc1a34 + 0xfc))();
  (*(code *)&SUB_400952e4)();
  (**(code **)(_DAT_3ffc1a34 + 0x1a0))(0x24);
  DAT_3ffc7ddc = 1;
  memw();
  memw();
  memw();
  _DAT_3ff73084 = _DAT_3ff73084 & 0x7fffffff;
  memw();
  return;
}

