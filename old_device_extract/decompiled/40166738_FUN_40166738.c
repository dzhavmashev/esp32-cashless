// Function : FUN_40166738
// Address  : 0x40166738
// Size     : 36 bytes


void FUN_40166738(uint param_1)

{
  uint *puVar1;
  
  puVar1 = (uint *)((0x7fee7a4 - (param_1 & 0xff)) * 8);
  memw();
  memw();
  *puVar1 = *puVar1 & 0xbfffffff;
  memw();
  return;
}

