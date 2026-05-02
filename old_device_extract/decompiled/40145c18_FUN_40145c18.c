// Function : FUN_40145c18
// Address  : 0x40145c18
// Size     : 120 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40145c18(int param_1,ushort param_2)

{
  int iVar1;
  
  iVar1 = FUN_40189d50();
  if (iVar1 != 0) {
    return;
  }
  if (param_1 == 1) {
    if ((_DAT_3ffc78ec & param_2) == 0) goto LAB_40145c85;
    _DAT_3ffc78ec = _DAT_3ffc78ec & (param_2 ^ 0xffff);
    memw();
    memw();
  }
  else if (param_1 == 0) {
    if ((_DAT_3ffc78ea & param_2) == 0) goto LAB_40145c85;
    _DAT_3ffc78ea = _DAT_3ffc78ea & (param_2 ^ 0xffff);
    memw();
    memw();
  }
  else {
    if ((param_1 != 2) || ((_DAT_3ffc78ee & param_2) == 0)) goto LAB_40145c85;
    _DAT_3ffc78ee = _DAT_3ffc78ee & (param_2 ^ 0xffff);
    memw();
    memw();
  }
  FUN_4014579c();
LAB_40145c85:
  FUN_40189d78();
  return;
}

