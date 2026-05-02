// Function : FUN_40184d78
// Address  : 0x40184d78
// Size     : 31 bytes


void FUN_40184d78(int *param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x24) = *(uint *)(*param_1 + 0x24) & 0xffffff80 | param_2 & 0x7f;
  memw();
  return;
}

