// Function : FUN_40166100
// Address  : 0x40166100
// Size     : 103 bytes


void FUN_40166100(uint param_1)

{
  uint *puVar1;
  
  param_1 = param_1 & 0xff;
  FUN_40147fe4(5,0x2000,3,0x3f435b94,param_1);
  puVar1 = (uint *)(&DAT_3ff73250 + param_1 * -0x20);
  memw();
  memw();
  *puVar1 = *puVar1 & 0x7fffffff;
  memw();
  *(undefined4 *)((0x1ffb993 - param_1) * 0x20) = 0;
  memw();
  *(undefined4 *)(&DAT_3ff73264 + param_1 * -0x20) = 0;
  memw();
  memw();
  *puVar1 = *puVar1 | 0x80000000;
  memw();
  *puVar1 = 0;
  memw();
  return;
}

