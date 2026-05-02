// Function : FUN_4016f984
// Address  : 0x4016f984
// Size     : 102 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016f984(short param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)&SUB_40086ecc)();
  memw();
  _DAT_3ffc7e92 = param_1;
  if (DAT_3ffca606 != '\0') {
    _DAT_3ffc7e92 = DAT_3ffca607 * 8 + param_1;
    memw();
  }
  FUN_4016e2bc();
  FUN_4016f7a8((int)DAT_3ffca519,DAT_3ffca5b9,(int)_DAT_3ffc7e92);
  FUN_4018eb1c((int)DAT_3ffca51b);
  (*(code *)&SUB_40086ee0)(uVar1);
  return;
}

