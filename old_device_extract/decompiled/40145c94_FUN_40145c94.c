// Function : FUN_40145c94
// Address  : 0x40145c94
// Size     : 80 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40145c94(uint param_1)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = FUN_40189d50();
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  if (_DAT_3ffc78e4 != (byte *)0x0) {
    if (((_DAT_3ffc78ea == 0) && (*_DAT_3ffc78e4 == param_1)) &&
       (iVar2 = FUN_4018b174(), iVar2 == 1)) {
      param_1 = 0;
    }
    if ((int)param_1 < (int)(uint)*_DAT_3ffc78e4) {
      DAT_3ffc78e8 = (undefined1)param_1;
      memw();
      iVar2 = 0;
      goto LAB_40145cd0;
    }
  }
  iVar2 = -1;
LAB_40145cd0:
  pcVar1 = _DAT_3ffc78f8;
  memw();
  FUN_40189d78();
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(0);
  }
  return 0;
}

