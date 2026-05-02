// Function : FUN_40145b9c
// Address  : 0x40145b9c
// Size     : 120 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40145b9c(int param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = FUN_40189d50();
  if (iVar2 != 0) {
    return;
  }
  uVar1 = (ushort)param_2;
  if (param_1 == 1) {
    if (((_DAT_3ffc78ec ^ 0xffffffff) & param_2) == 0) goto LAB_40145c08;
    _DAT_3ffc78ec = _DAT_3ffc78ec | uVar1;
    memw();
    memw();
  }
  else if (param_1 == 0) {
    if (((_DAT_3ffc78ea ^ 0xffffffff) & param_2) == 0) goto LAB_40145c08;
    _DAT_3ffc78ea = _DAT_3ffc78ea | uVar1;
    memw();
    memw();
  }
  else {
    if ((param_1 != 2) || (((_DAT_3ffc78ee ^ 0xffffffff) & param_2) == 0)) goto LAB_40145c08;
    _DAT_3ffc78ee = _DAT_3ffc78ee | uVar1;
    memw();
    memw();
  }
  FUN_4014579c();
LAB_40145c08:
  FUN_40189d78();
  return;
}

