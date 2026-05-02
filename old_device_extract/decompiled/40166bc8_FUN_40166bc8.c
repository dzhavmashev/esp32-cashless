// Function : FUN_40166bc8
// Address  : 0x40166bc8
// Size     : 64 bytes


void FUN_40166bc8(uint param_1,char param_2)

{
  uint *puVar1;
  
  if (param_2 != '\0') {
    puVar1 = (uint *)(((param_1 & 0xff) + 0xffdcc36) * 4);
    memw();
    memw();
    *puVar1 = *puVar1 | 2;
    memw();
    return;
  }
  puVar1 = (uint *)(((param_1 & 0xff) + 0xffdcc36) * 4);
  memw();
  memw();
  *puVar1 = *puVar1 & 0xfffffffd;
  memw();
  return;
}

