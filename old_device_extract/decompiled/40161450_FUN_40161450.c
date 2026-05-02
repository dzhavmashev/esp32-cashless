// Function : FUN_40161450
// Address  : 0x40161450
// Size     : 71 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40161450(void)

{
  if (DAT_3ffc1a44 == '\0') {
    (*(code *)&SUB_40087d08)(3,1);
    (**(code **)(_DAT_3ffc1a34 + 0x1a0))(1);
    FUN_4018b860(0);
    DAT_3ffca2f5 = 3;
    memw();
    memw();
    (*(code *)&SUB_40087d08)(3,0);
  }
  return;
}

