// Function : FUN_4016a278
// Address  : 0x4016a278
// Size     : 20 bytes


int FUN_4016a278(void)

{
  uint uVar1;
  
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c018);
  return (uVar1 >> 5 & 0x3ff) - 0x400;
}

