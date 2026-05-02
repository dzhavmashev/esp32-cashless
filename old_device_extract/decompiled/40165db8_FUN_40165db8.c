// Function : FUN_40165db8
// Address  : 0x40165db8
// Size     : 55 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40165db8(uint param_1)

{
  uint uVar1;
  
  uVar1 = (uint)(0xfffffffefffffffe >> 0x20 - (param_1 & 0x1f));
  _DAT_3ffc0718 = _DAT_3ffc0718 & uVar1;
  _DAT_3ffc071c = _DAT_3ffc071c & uVar1;
  _DAT_3ffc0720 = _DAT_3ffc0720 & uVar1;
  _DAT_3ffc0724 = _DAT_3ffc0724 & uVar1;
  memw();
  FUN_4016623c(param_1);
  return;
}

