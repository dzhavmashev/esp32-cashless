// Function : FUN_401664f4
// Address  : 0x401664f4
// Size     : 147 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401664f4(char param_1,byte param_2,char param_3,char param_4)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)&DAT_3ff73800;
  if (param_1 == '\x01') {
    puVar1 = (uint *)&DAT_3ff73804;
  }
  uVar2 = 0x10010103;
  if ((param_2 & 0xfb) != 1) {
    uVar2 = 0x10103;
  }
  if (param_3 != '\0') {
    uVar2 = uVar2 | 0x20000;
  }
  if (param_4 != '\0') {
    uVar2 = uVar2 | 0x200;
  }
  memw();
  *puVar1 = uVar2;
  if (param_2 == 4) {
    memw();
    _DAT_3ff73810 = _DAT_3ff73810 | 0xffff00;
    memw();
    memw();
    uVar2 = *puVar1 & 0x3fffffff | 0x80000000;
    memw();
  }
  else {
    memw();
    _DAT_3ff73810 = _DAT_3ff73810 & 0xff0000ff;
    memw();
    memw();
    uVar2 = *puVar1 & 0x3fffffff;
  }
  memw();
  *puVar1 = uVar2;
  memw();
  return;
}

