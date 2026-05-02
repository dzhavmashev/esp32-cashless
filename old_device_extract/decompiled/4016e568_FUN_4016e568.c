// Function : FUN_4016e568
// Address  : 0x4016e568
// Size     : 111 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016e568(uint param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  uVar2 = (param_1 & 0xff) * 3;
  puVar3 = param_2 + 3;
  do {
    uVar4 = *param_2;
    uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
    _DAT_3ff4e0c4 = uVar1 & 0xffffff00 | uVar2 & 0xff;
    uVar2 = (uVar2 & 0xff) + 1;
    param_2 = param_2 + 1;
    memw();
    memw();
    _DAT_3ff4e148 = uVar4;
    _DAT_3ff4e0c4 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
    _DAT_3ff4e0c4 = _DAT_3ff4e0c4 | 0x200;
    memw();
    _DAT_3ff4e0c4 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
    _DAT_3ff4e0c4 = _DAT_3ff4e0c4 & 0xfffffdff;
    memw();
  } while (puVar3 != param_2);
  return;
}

