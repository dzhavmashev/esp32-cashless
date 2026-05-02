// Function : FUN_40166f94
// Address  : 0x40166f94
// Size     : 125 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_40166f94(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    memw();
    _DAT_3ff75010 = _DAT_3ff75010 | 2;
    memw();
    memw();
    uVar3 = 0xfffffffd;
    memw();
    memw();
    uVar2 = 0;
    uVar1 = _DAT_3ff75054;
  }
  else {
    if (param_1 != 1) {
      uVar1 = 0;
      uVar2 = 0;
      goto LAB_4016700d;
    }
    memw();
    _DAT_3ff75010 = _DAT_3ff75010 | 4;
    memw();
    memw();
    memw();
    uVar3 = 0xfffffffb;
    memw();
    uVar1 = _DAT_3ff75090;
    uVar2 = _DAT_3ff75094;
  }
  _DAT_3ff75010 = _DAT_3ff75010 & uVar3;
  memw();
  memw();
LAB_4016700d:
  return CONCAT44(uVar2,uVar1);
}

