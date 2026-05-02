// Function : FUN_401666e8
// Address  : 0x401666e8
// Size     : 44 bytes


undefined4 FUN_401666e8(int param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)((uint)*(byte *)(param_1 + 4) * -8 + 0x3ff73d1c);
  memw();
  memw();
  *puVar1 = *puVar1 & 0xfffff000 | param_2 & 0xfff;
  memw();
  return 0;
}

