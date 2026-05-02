// Function : FUN_401687e8
// Address  : 0x401687e8
// Size     : 129 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_401687e8(undefined2 *param_1,uint param_2,int param_3)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  char cStack_25;
  undefined4 uStack_24;
  
  _DAT_3ff01008 = 4;
  if (param_3 == 1) {
    _DAT_3ff01008 = 0;
  }
  _DAT_3ff01008 = ((param_2 >> 3 & 0x1f) - 2) + _DAT_3ff01008;
  puVar1 = (undefined2 *)((int)param_1 + (param_2 & 0xfffffffc));
  memw();
  iVar2 = 0x3ff01010 - (int)param_1;
  memw();
  cStack_25 = '\0';
  while (puVar1 != param_1) {
    memw();
    uStack_24 = CONCAT13(*(undefined1 *)((int)param_1 + 3),
                         CONCAT12(*(undefined1 *)(param_1 + 1),*param_1));
    memw();
    puVar3 = (undefined4 *)(iVar2 + (int)param_1);
    param_1 = param_1 + 2;
    memw();
    *puVar3 = uStack_24;
    memw();
    cStack_25 = cStack_25 + '\x04';
    memw();
    memw();
  }
  memw();
  memw();
  return cStack_25;
}

