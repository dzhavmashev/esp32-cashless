// Function : FUN_40167020
// Address  : 0x40167020
// Size     : 103 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_40167020(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    uVar3 = 0xfffffffe;
    memw();
    _DAT_3ff75010 = _DAT_3ff75010 | 1;
    memw();
    memw();
    memw();
    memw();
    memw();
    uVar1 = _DAT_3ff75014;
    uVar2 = _DAT_3ff75018;
  }
  else {
    memw();
    _DAT_3ff75010 = _DAT_3ff75010 | 2;
    uVar3 = 0xfffffffd;
    memw();
    memw();
    memw();
    memw();
    uVar1 = _DAT_3ff75054;
    uVar2 = _DAT_3ff75058;
  }
  memw();
  _DAT_3ff75010 = _DAT_3ff75010 & uVar3;
  memw();
  return CONCAT44(uVar2,uVar1);
}

