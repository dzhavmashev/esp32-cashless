// Function : FUN_4011eff4
// Address  : 0x4011eff4
// Size     : 33 bytes


int FUN_4011eff4(void)

{
  int iVar1;
  
  iVar1 = (*(code *)&SUB_40084b70)(2,1);
  if (iVar1 == 0) {
    DAT_3ffc66f0 = 1;
    memw();
  }
  memw();
  return iVar1;
}

