// Function : FUN_40166c94
// Address  : 0x40166c94
// Size     : 89 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40166c94(void)

{
  uint uVar1;
  
  uVar1 = _DAT_3ff73d24;
  memw();
  memw();
  _DAT_3ff73288 = _DAT_3ff73288 | 1;
  memw();
  memw();
  memw();
  _DAT_3ff73c40 = 0;
  memw();
  _DAT_3ff73c4c = 0xffffffff;
  memw();
  memw();
  _DAT_3ff73d24 = _DAT_3ff73d24 | 2;
  do {
    memw();
  } while ((uVar1 & 1) == 0);
  memw();
  return;
}

