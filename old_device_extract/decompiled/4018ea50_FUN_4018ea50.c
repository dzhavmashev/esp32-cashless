// Function : FUN_4018ea50
// Address  : 0x4018ea50
// Size     : 190 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018ea50(char param_1)

{
  uint uVar1;
  
  if (param_1 == '\0') {
    uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5d030);
    _DAT_3ff5d030 = uVar1 & 0xfffffc00 | 100;
    memw();
    uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff450f0);
    _DAT_3ff450f0 = uVar1 & 0xfffffe00 | 100;
    memw();
    uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5d000);
    _DAT_3ff5d000 = uVar1 & 0xe07fffff | 0xf000000;
    memw();
  }
  else {
    uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5d030);
    _DAT_3ff5d030 = uVar1 & 0xfffffc00 | 0x87;
    memw();
    uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff450f0);
    _DAT_3ff450f0 = uVar1 & 0xfffffe00 | 0xf0;
    memw();
    uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5d000);
    _DAT_3ff5d000 = uVar1 & 0xe07fffff | 0xa000000;
    memw();
  }
  (*(code *)&SUB_40089f4c)();
  return;
}

