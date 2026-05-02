// Function : FUN_4016c288
// Address  : 0x4016c288
// Size     : 52 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016c288(void)

{
  uint uVar1;
  
  _DAT_3ff4607c = (*(code *)&SUB_40084594)(&DAT_3ff4607c);
  _DAT_3ff4607c = _DAT_3ff4607c & 0xfffffffd;
  memw();
  (*(code *)&SUB_40008534)(1);
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff4607c);
  memw();
  _DAT_3ff4607c = uVar1 & 0xfffffffe;
  return;
}

