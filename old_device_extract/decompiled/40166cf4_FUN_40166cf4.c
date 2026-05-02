// Function : FUN_40166cf4
// Address  : 0x40166cf4
// Size     : 102 bytes


void FUN_40166cf4(uint param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(((param_1 & 0xff) + 0x7fee608) * 8);
  memw();
  *puVar1 = *param_2;
  memw();
  puVar1[1] = (uint)*(ushort *)(param_2 + 1);
  memw();
  puVar1[8] = 0xffffffff;
  memw();
  puVar1[9] = 0xffff;
  memw();
  memw();
  puVar1[9] = puVar1[9] | 0x10000;
  memw();
  return;
}

