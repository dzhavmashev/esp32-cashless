// Function : FUN_40166ec8
// Address  : 0x40166ec8
// Size     : 186 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40166ec8(void)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  memw();
  memw();
  do {
    memw();
  } while ((_DAT_3ff73d24 & 1) == 0);
  memw();
  _DAT_3ff73c40 = 0;
  memw();
  _DAT_3ff73c4c = 0xffffffff;
  memw();
  _DAT_3ff73d24 = _DAT_3ff73d24 | 2;
  FUN_401669b8();
  iVar1 = 0;
  do {
    puVar3 = (uint *)((iVar1 + 0xffdcc36) * 4);
    memw();
    memw();
    *puVar3 = *puVar3 | 5;
    memw();
    iVar2 = iVar1 + 1;
    memw();
    *puVar3 = *puVar3 & 0xfffff6ff;
    memw();
    FUN_40166dfc(iVar1,0,0);
    iVar1 = iVar2;
  } while (iVar2 != 4);
  FUN_40166888();
  FUN_40166c28();
  FUN_40167578();
  FUN_401667b8();
  FUN_401664ac();
  FUN_401674dc();
  memw();
  _DAT_3ff73c40 = 0x1e839e0;
  memw();
  (*(code *)&SUB_400886a8)(1);
  memw();
  memw();
  _DAT_3ff7309c = _DAT_3ff7309c & 0xffffff00 | 2;
  memw();
  return;
}

