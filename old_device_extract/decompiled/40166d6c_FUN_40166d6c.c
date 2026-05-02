// Function : FUN_40166d6c
// Address  : 0x40166d6c
// Size     : 133 bytes


void FUN_40166d6c(uint param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = (param_1 & 0xff) * 8;
  uVar1 = *param_2;
  puVar3 = (uint *)(iVar2 + 0x3ff73024);
  memw();
  memw();
  *puVar3 = *puVar3 & 0xfffeffff;
  memw();
  *(undefined4 *)(iVar2 + 0x3ff73000) = uVar1;
  memw();
  *(uint *)(iVar2 + 0x3ff73004) = (uint)*(ushort *)(param_2 + 1);
  memw();
  *(undefined4 *)(iVar2 + 0x3ff73020) = 0xffffffff;
  memw();
  *puVar3 = 0xffff;
  memw();
  memw();
  *puVar3 = *puVar3 | 0x10000;
  memw();
  return;
}

