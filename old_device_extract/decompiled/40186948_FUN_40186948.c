// Function : FUN_40186948
// Address  : 0x40186948
// Size     : 24 bytes


bool FUN_40186948(int param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if (param_1 != 0) {
    bVar1 = *(char *)(param_1 + 0x83) != '\0';
  }
  return bVar1;
}

