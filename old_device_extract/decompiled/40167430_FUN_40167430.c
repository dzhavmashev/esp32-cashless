// Function : FUN_40167430
// Address  : 0x40167430
// Size     : 80 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40167430(int param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  
  if (param_1 == 1) {
    puVar1 = (uint *)&DAT_3ff73cbc;
    param_2 = (param_2 & 0x7ff) << 0x10;
    memw();
    uVar2 = _DAT_3ff73cbc & 0xf800ffff;
  }
  else if (param_1 == 0) {
    puVar1 = (uint *)&DAT_3ff73cbc;
    param_2 = param_2 & 0x7ff;
    memw();
    uVar2 = _DAT_3ff73cbc & 0xfffff800;
  }
  else {
    if (param_1 != 2) goto LAB_4016747c;
    puVar1 = (uint *)&DAT_3ff73cc4;
    memw();
    uVar2 = _DAT_3ff73cc4;
  }
  memw();
  *puVar1 = param_2 | uVar2;
LAB_4016747c:
  memw();
  return 0;
}

