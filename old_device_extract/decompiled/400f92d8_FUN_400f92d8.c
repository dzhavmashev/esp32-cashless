// Function : FUN_400f92d8
// Address  : 0x400f92d8
// Size     : 40 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f92d8(int param_1)

{
  (*(code *)&SUB_4008b530)(0x3ffc0878,0,0xc);
  *(undefined1 **)(param_1 + 0xc) = &DAT_3ffc0874;
  *(undefined4 *)(param_1 + 8) = 0x3ffc0850;
  DAT_3ffc0874 = '%';
  DAT_3ffc0874_1._0_1_ = 's';
  DAT_3ffc0874_1._1_1_ = '.';
  DAT_3ffc0874_1._2_1_ = '\n';
  memw();
  return 0;
}

