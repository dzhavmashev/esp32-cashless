// Function : FUN_40162b40
// Address  : 0x40162b40
// Size     : 28 bytes


undefined4 FUN_40162b40(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar2 = FUN_401600d4(iVar1);
    if (iVar2 == 0) {
      return 1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 5);
  return 0;
}

