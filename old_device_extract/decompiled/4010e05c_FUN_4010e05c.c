// Function : FUN_4010e05c
// Address  : 0x4010e05c
// Size     : 62 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_4010e05c(void)

{
  undefined1 uVar1;
  uint uVar2;
  
  uVar2 = (uint)_DAT_3ffc634c;
  _DAT_3ffc634c = _DAT_3ffc634c + 1;
  memw();
  if ((_DAT_3ffc6350 == 0) || (uVar2 < _DAT_3ffc6354)) {
    uVar1 = *(undefined1 *)(_DAT_3ffc6358 + uVar2 + 0x14);
  }
  else {
    uVar1 = *(undefined1 *)(_DAT_3ffc6350 + (uVar2 - _DAT_3ffc6354 & 0xff));
  }
  memw();
  return uVar1;
}

