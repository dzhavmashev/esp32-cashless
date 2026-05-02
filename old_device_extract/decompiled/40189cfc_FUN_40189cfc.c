// Function : FUN_40189cfc
// Address  : 0x40189cfc
// Size     : 40 bytes


int FUN_40189cfc(void)

{
  int iVar1;
  
  if ('\0' < DAT_3ffc072b) {
    iVar1 = FUN_4016a278();
    DAT_3ffc072b = (char)(iVar1 + 2 >> 2);
    memw();
  }
  memw();
  return (int)DAT_3ffc072b;
}

